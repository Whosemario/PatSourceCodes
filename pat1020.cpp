//============================================================================
// Name        : PAT1020.cpp
// Author      : Whosemario
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#define SIZE 33

struct TreeNode{
	int val;
	int left,right;
};
TreeNode buffers[SIZE];
int sz=0;

int postarr[SIZE];
int inarr[SIZE];

int dfs(int postl,int postr,int inl,int inr){
	int ret = sz++;
	buffers[ret].val = postarr[postr];
	//left
	int i=inl;
	while(inarr[i]!=postarr[postr]) i++;
	if(i<=inl)
		buffers[ret].left = -1;
	else
		buffers[ret].left = dfs(postl,postl+(i-inl)-1,inl,i-1);
	//right
	if(i>=inr)
		buffers[ret].right = -1;
	else
		buffers[ret].right = dfs(postl+(i-inl),postr-1,i+1,inr);
	return ret;
}

int res[SIZE];
int queue[SIZE];
void getRes(int root){
	int len =0;
	int head =0,tail=0;
	queue[tail++] = root;
	while(head < tail){
		int u = queue[head++];
		res[len++] = buffers[u].val;
		if(buffers[u].left!=-1)
			queue[tail++] = buffers[u].left;
		if(buffers[u].right != -1)
			queue[tail++] = buffers[u].right;
	}
}

int main() {

	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		scanf("%d",&postarr[i]);
	for(int i=0;i<N;i++)
		scanf("%d",&inarr[i]);
	dfs(0,N-1,0,N-1);
	getRes(0);
	printf("%d",res[0]);
	for(int i=1;i<N;i++)
		printf(" %d",res[i]);
	puts("");
	return 0;
}
