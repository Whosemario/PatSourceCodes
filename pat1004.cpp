#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

#define SIZE 102

vector<int> tree[SIZE];

struct node{
	int id;
	int depth;
};
node queue[SIZE];

int res[SIZE];

int bfs(int root){
	int head = 0,tail = 0;
	node n;
	n.id = root;
	n.depth = 0;
	queue[tail++] = n;
	int ret = 0;
	while(head < tail){
		n = queue[head++];
		if(n.depth> ret) ret = n.depth;
		if(tree[n.id].size()){
			for(int i=0;i<tree[n.id].size();i++){
				node v;
				v.id = tree[n.id][i];
				v.depth = n.depth + 1;
				queue[tail++] = v;
			}
		}
		else{
			res[n.depth]++;
		}
	}
	return ret;
}

int col[SIZE];

int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++){
		int id,num;
		scanf("%d%d",&id,&num);
		if(col[id]==0) col[id] = 1;
		for(int j=0;j<num;j++){
			int c;
			scanf("%d",&c);
			col[c] = 2;
			tree[id].push_back(c);
		}
	}
	int root = 0;
	for(int i=0;i<100;i++)
		if(col[i]==1){
			root = i;
			break;
		}
	int depth = bfs(root);
	printf("%d",res[0]);
	for(int i=1;i<=depth;i++)
		printf(" %d",res[i]);
	puts("");
}
