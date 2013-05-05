#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
	int N;
	scanf("%d",&N);
	int res = 0;
	int prev = 0;
	for(int i=0;i<N;i++){
		int f;
		scanf("%d",&f);
		prev = f - prev;
		if(prev>0) {
			res += 6*prev + 5;
		}
		else if(prev < 0){
			res += -prev*4+5;
		}
		else{
			res+=5;
		}
		prev = f;
	}
	cout<<res<<endl;
}
