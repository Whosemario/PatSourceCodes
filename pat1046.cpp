//============================================================================
// Name        : PAT1046.cpp
// Author      : Whosemario
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int dist[100005];

int main() {

	int sum=0;
	int N;
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		scanf("%d",&dist[i]);
		sum+=dist[i];
	}
	dist[0]=0;
	for(int i=1;i<=N;i++) dist[i]+=dist[i-1];
	int M;
	scanf("%d",&M);
	while(M--){
		int a,b;
		scanf("%d%d",&a,&b);
		if(a>b){
			int tmp=b;
			b=a;
			a=tmp;
		}
		int res = dist[b-1]-dist[a-1] < sum-dist[b-1]+dist[a-1] ? dist[b-1]-dist[a-1]:sum-dist[b-1]+dist[a-1];
		printf("%d\n",res);
	}
	return 0;
}
