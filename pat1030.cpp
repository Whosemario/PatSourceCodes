//============================================================================
// Name        : PAT1030.cpp
// Author      : Whosemario
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <string.h>
using namespace std;

#define SIZE 505

struct node{
	int to,dist,cost;
	bool operator< (const node& other) const{
		if(dist < other.dist) return true;
		else if(dist == other.dist && cost < other.cost) return true;
		return false;
	}
	bool operator > (const node& other) const{
		if(dist > other.dist) return true;
		else if(dist==other.dist && cost > other.cost) return true;
		return false;
	}
};

int mat[SIZE][SIZE][2];

priority_queue<node,vector<node> ,greater<node> > pq;

int col[SIZE][2];
int color[SIZE];
int pre[SIZE];

int N,S,D;

int res[SIZE];

int main() {
	int M;
	scanf("%d%d%d%d",&N,&M,&S,&D);
	memset(mat,-1,sizeof(mat));
	for(int i=0;i<M;i++){
		int from, to, dist, cost;
		scanf("%d%d%d%d",&from,&to,&dist,&cost);
		if(mat[from][to][0]==-1 || mat[from][to][0] > dist
				|| (mat[from][to][0]==dist && mat[from][to][1] > cost)){
			mat[from][to][0] = mat[to][from][0] = dist;
			mat[from][to][1] = mat[to][from][1] = cost;
		}
	}

	memset(col,-1,sizeof(col));
	memset(color,0,sizeof(color));
	pre[S]=-1;
	node u ;
	u.to=S;u.dist=0;u.cost = 0;
	pq.push(u);
	while(!pq.empty()){
		while(!pq.empty() && color[pq.top().to]==1) pq.pop();
		if(pq.empty()) break;
		u = pq.top();
		pq.pop();
		col[u.to][0] = u.dist;
		col[u.to][1] = u.cost;
		color[u.to]=1;
		if(u.to == D) break;
		for(int i=0;i<N;i++)
			if(mat[u.to][i][0]!=-1 && color[i]==0){
				if(col[i][0]==-1){
					col[i][0] = u.dist + mat[u.to][i][0];
					col[i][1] = u.cost + mat[u.to][i][1];
					node v;
					v.to = i;
					v.dist = col[i][0];
					v.cost = col[i][1];
					pq.push(v);
					pre[i]=u.to;
				}
				else{
					if(col[i][0] > u.dist+mat[u.to][i][0]
				    || (col[i][0] == u.dist+mat[u.to][i][0] && col[i][1] > u.cost + mat[u.to][i][1])){
						col[i][0] = u.dist + mat[u.to][i][0];
						col[i][1] = u.cost + mat[u.to][i][1];
						node v;
						v.to = i;
						v.dist = col[i][0];
						v.cost = col[i][1];
						pq.push(v);
						pre[i]=u.to;
					}
				}
			}
	}
	if(col[D][0]!=-1){
		int sz=0;
		int cur = D;
		while(cur!=-1){
			res[sz++]=cur;
			cur=pre[cur];
		}
		for(int i=sz-1;i>=0;i--)
			if(i==sz-1)
				printf("%d",res[i]);
			else
				printf(" %d",res[i]);
		printf(" %d %d\n",col[D][0],col[D][1]);
	}
	return 0;
}
