#include<iostream>
#include<stdio.h>
using namespace std;

#define SIZE 1003

int col[SIZE];
double res[SIZE];

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int ind;
		double k;
		scanf("%d%lf",&ind,&k);
		if(col[ind]){
			res[ind]+=k;
		}
		else{
			col[ind]=1;
			res[ind]=k;
		}
	}	
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int ind;
		double k;
		scanf("%d%lf",&ind,&k);
		if(col[ind]){
			res[ind]+=k;
		}
		else{
			col[ind]=1;
			res[ind]=k;
		}
	}	
	N=0;
	for(int i=0;i<=1000;i++)
		if(col[i] && res[i]!=0) N++;
	printf("%d",N);
	for(int i=1000;i>=0;i--)
		if(col[i]&& res[i]!=0){
			printf(" %d %.1lf",i,res[i]);
		}
	puts("");
}
