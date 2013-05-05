//============================================================================
// Name        : PAT1056.cpp
// Author      : Whosemario
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
using namespace std;

#define SIZE 1002

struct Node{
	int val;
	int ind;
	int i;
};

Node arr[SIZE];
int col[SIZE];
int res[SIZE];

int comp(const Node& a,const Node& b){
	if(a.i<b.i) return true;
	return false;
}
int main() {

	int N,Gap;
	scanf("%d%d",&N,&Gap);
	int size = N;
	for(int i=0;i<N;i++) {scanf("%d",&arr[i].val);arr[i].ind = i;}
	for(int i=0;i<N;i++) {int tt; scanf("%d",&tt);arr[tt].i=i;}
	sort(arr,arr+N,comp);

	int maxInd = 0;
	while(size > 1){
		int rank = (size+Gap-1)/Gap+1;
		for(int i=0,j=0;i<N;i++){
			if(col[i]==0 && j==0){maxInd = i;j++;}
			else if(col[i]==0&&arr[i].val > arr[maxInd].val){
				res[arr[maxInd].ind]=rank;
				col[maxInd]=1;
				maxInd = i;
				j++;
			}
			else if(col[i]==0&&arr[i].val <= arr[maxInd].val){
				res[arr[i].ind]=rank;
				col[i]=1;
				j++;
			}
			if(j==Gap){
				j=0;
			}
		}
		size = rank-1;
	}
	res[arr[maxInd].ind] = 1;
	for(int i=0;i<N;i++)
		if(i==0) printf("%d",res[i]);
		else printf(" %d",res[i]);
	puts("");
	return 0;
}
