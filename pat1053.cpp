//============================================================================
// Name        : PAT1053.cpp
// Author      : Whosemario
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#define SIZE 102

int tree[SIZE][SIZE];
int res[SIZE];
int weight[SIZE];

void pushNode(int u, int val){
	tree[u][++tree[u][0]] = val;
	int i;
	for(i=tree[u][0]-1;i>0;i--)
		if(weight[tree[u][i]] < weight[val])
			tree[u][i+1] = tree[u][i];
		else
			break;
	tree[u][i+1]=val;
}

void dfs(int root, int sum,int S,int depth){
	res[depth]=weight[root];
	sum+=weight[root];
	if(tree[root][0]==0){
		// leaf
		if(sum==S){
			for(int i=0;i<=depth;i++)
				if(i==0) printf("%d",res[i]);
				else printf(" %d",res[i]);
			puts("");
		}
		return ;
	}

	for(int i=1;i<=tree[root][0];i++)
		dfs(tree[root][i],sum,S,depth+1);

}

int main() {
	int N,M,S;
	scanf("%d%d%d",&N,&M,&S);
	for(int i=0;i<N;i++) scanf("%d",&weight[i]);
	for(int i=0;i<M;i++){
		int node;
		int num;
		scanf("%d%d",&node,&num);
	//	cout<<node<<" "<<num<<endl;
		tree[node][0]=0;
		for(int j=0;j<num;j++){
			int c;
			scanf("%d",&c);
			pushNode(node,c);
		}
	}

	dfs(0,0,S,0);
	return 0;
}
