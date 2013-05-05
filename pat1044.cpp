//============================================================================
// Name        : PAT1044.cpp
// Author      : Whosemario
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#define SIZE 100004

int arr[SIZE];

int main() {

	int N,M;
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++) scanf("%d",&arr[i]);

	int sum = arr[0];
	int _min = -1;
	int i=0;int j=0;
	while(j<N){
		if(sum==M){
			_min = sum;
			j++;
			if(j<N)
				sum+=arr[j];
		}
		else if(sum > M){
			if(_min==-1 || sum < _min) _min = sum;
			sum-=arr[i];
			i++;
		}
		else{
			j++;
			if(j<N)
				sum+=arr[j];
		}
	}

	M = _min;
	i=j=0;
	sum=arr[0];
	while(j<N){
		if(sum==M){
			printf("%d-%d\n",i+1,j+1);
			j++;
			if(j<N) sum+=arr[j];
		}
		else if(sum>M){
			sum-=arr[i];
			i++;
		}
		else{
			j++;
			if(j<N) sum+=arr[j];
		}
	}
	return 0;
}
