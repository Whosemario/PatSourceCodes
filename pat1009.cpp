#include<iostream>
#include<stdio.h>
using namespace std;

#define SIZE 1003
double in1[SIZE];
double in2[SIZE];
double res[SIZE*2];

int main()
{
	for(int i=0;i<=1000;i++)
		in1[i]=in2[i]=res[i]=0;
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int c;
		double f;
		scanf("%d%lf",&c,&f);
		in1[c] = f;
	}
	
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int c;
		double f;
		scanf("%d%lf",&c,&f);
		in2[c] = f;
	}
	
	for(int i=0;i<=1000;i++)
		for(int j=0;j<=1000;j++){
			res[i+j] += in1[i]*in2[j];
		}
	
	int num = 0;
	for(int i=0;i<=2000;i++)
	  if(res[i]>=0.05 || res[i]<=-0.05) num++;
	printf("%d",num);
	for(int i=2000;i>=0;i--)
		if(res[i]>=0.05 || res[i]<=-0.05)
			printf(" %d %.1lf",i,res[i]);
	puts("");
}
