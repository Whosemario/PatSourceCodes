//============================================================================
// Name        : PAT1045.cpp
// Author      : Whosemario
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#define SIZE 10002

int arr[SIZE];
int res[SIZE];
int sz ;
int hashMap[202];

int binarySearch(int target){
	int low =0;
	int high = sz-1;
	while(low<=high){
		int mid = (low+high)/2;
		if(target>=res[mid]) low=mid+1;
		else high = mid-1;
	}
	return low;
}

int main() {
	int N;
	scanf("%d",&N);
	int M;
	scanf("%d",&M);
	for(int i=1;i<=M;i++){
		int tmp;
		scanf("%d",&tmp);
		hashMap[tmp]=i;
	}
	scanf("%d",&M);
	int j=0;
	for(int i=0;i<M;i++){
		int tmp;
		scanf("%d",&tmp);
		if(hashMap[tmp]){
			arr[j++]=hashMap[tmp];
		}
	}
	M=j;
	sz=0;
	for(int i=0;i<M;i++){
		if(sz==0){res[0]=arr[i];sz++;}
		else{
			if(arr[i]>=res[sz-1]) res[sz++]=arr[i];
			else{
				int ind = binarySearch(arr[i]);
				res[ind] = arr[i];
			}
		}
	}

	printf("%d\n",sz);
	return 0;
}
