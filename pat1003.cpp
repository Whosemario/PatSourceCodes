#include<stdio.h>
#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

struct node{
	int to;
	int dist;
	int per;
	bool operator<(const node& a)const{
		if(dist > a.dist) return true;
		else if(dist == a.dist && per < a.per) return true;
		return false;
	}
};

#define SIZE 502
int mat[SIZE][SIZE];

int col[SIZE];
int person[SIZE];
int num[SIZE];
int res[SIZE];
int resnum[SIZE];

priority_queue<node> pq;

int N;

void dij(int start, int end){
	memset(res,-1,sizeof(res));
	node n;
	n.to = start;
	n.dist = 0;
	n.per = person[start];
	resnum[start] = 1;
	num[start] = person[start];
	res[start] = 0;
	pq.push(n);
	while(!pq.empty()){
		while(!pq.empty() && col[pq.top().to]) pq.pop();
		if(pq.empty()) break;
		n = pq.top();
	//	cout<<n.to<<endl;
		pq.pop();
		col[n.to] = 1;
		for(int i=0;i<N;i++)
			if(mat[n.to][i]!=-1 && !col[i]){
				if(res[i]==-1 || n.dist + mat[n.to][i] < res[i]){
					res[i] = n.dist + mat[n.to][i];
					num[i] = n.per+person[i];
					resnum[i] = resnum[n.to];
					node v;
					v.to = i;
					v.dist = res[i];
					v.per = num[i];
					pq.push(v);
				}
				else if(n.dist + mat[n.to][i] == res[i]){
					resnum[i]+=resnum[n.to];
					if(n.per + person[i] > num[i]){
						num[i] = n.per + person[i];
						node v;
						v.to = i;
						v.dist = res[i];
						v.per = num[i];
						pq.push(v);
					}
				} 
			}
	}
}

int main()
{
	memset(mat,-1,sizeof(mat));
	int M,s,e;
	scanf("%d%d%d%d",&N,&M,&s,&e);
	for(int i=0;i<N;i++)
		scanf("%d",&person[i]);
	for(int i=0;i<M;i++){
		int from,to;
		int L;
		scanf("%d%d%d",&from,&to,&L);
		if(mat[from][to]==-1 || L < mat[from][to]){
			mat[from][to] = mat[to][from] = L;
		}
	}
	dij(s,e);
	printf("%d %d\n",resnum[e],num[e]);
}
