#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

#define SIZE 100005

int prime[SIZE];

void initPrime(){
	memset(prime,-1,sizeof(prime));
	prime[0] = prime[1] = 0;
	for(int i=2;i*i<=100000;i++)
		for(int j=i*i ; j<=100000;j+=i)
			prime[j] = 0;
}

int rev[40];
int reverse(int n,int d){
	if(n<=1) return n;
	int sz=0;
	while(n){
		rev[sz++] = n%d;
		n/=d;
	}
	int ret = 0;
	for(int i=0;i<sz;i++)
		ret = ret*d + rev[i];
	return ret;
}
int main()
{
	initPrime();
	int N,D;
//	cout<<1<<endl;
	while(scanf("%d",&N)&&N>=0){
		scanf("%d",&D);
		int M = reverse(N,D);
		if(prime[N]&&prime[M]) puts("Yes");
		else puts("No");
	}
}
