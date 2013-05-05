#include<iostream>
#include<stdio.h>
using namespace std;

#define SIZE 10005

int arr[SIZE];
int dp[SIZE];
int ind[SIZE];

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		scanf("%d",&arr[i]);
	dp[0] = arr[0];
	ind[0] = 0;
	for(int i=1;i<N;i++)
		if(arr[i] > dp[i-1]+arr[i]){
			dp[i] = arr[i];
			ind[i] = i;
		}
		else{
			dp[i] = dp[i-1]+arr[i];
			ind[i] = ind[i-1];
		}
	int res = dp[0];
	int left = 0,right = 0;
	for(int i=1;i<N;i++)
		if(dp[i] > res){
			res = dp[i];
			left = ind[i];
			right = i;
		}
		else if(dp[i] == res && ind[i]<left ){
			left = ind[i];
			right = i;
		}
	if(res>=0){
		printf("%d %d %d\n",res,arr[left],arr[right]);
	}
	else{
		printf("0 %d %d\n",arr[0],arr[N-1]);
	}
}
