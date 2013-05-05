//============================================================================
// Name        : PAT1029.cpp
// Author      : Whosemario
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#define SIZE 1000005

long long arr1[SIZE];
long long arr2[SIZE];

int main() {
	int N,M;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		scanf("%lld",&arr1[i]);
	scanf("%d",&M);
	for(int i=0;i<M;i++)
		scanf("%lld",&arr2[i]);
	int mid = (N+M+1)/2;
	int i=0,j=0;
	long long res = -1;
	bool flag = false;
	while(i<N && j<M){
		if(arr1[i]<=arr2[j]) {i++;mid--;if(mid==0){flag = true; res = arr1[i-1];break;}}
		else {j++;mid--;if(mid==0){flag=true;res=arr2[j-1];break;}}
	}
	if(flag){
		printf("%lld\n",res);
	}
	else{
		while(i<N){i++;mid--;if(mid==0){printf("%lld\n",arr1[i-1]);break;}}
		while(j<M){j++;mid--;if(mid==0){printf("%lld\n",arr2[j-1]);break;}}
	}
	return 0;
}
