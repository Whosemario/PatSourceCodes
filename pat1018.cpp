#include<stdio.h>
#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

#define SIZE 505
struct node{
	int to;
	int dist;
	int send;
	int recv;
	int next;
	bool operator<(const node& a) const{
		if(dist > a.dist) return true;
		else if(dist == a.dist){
			if(send > a.send) return true;
			else if(send == a.send ) return recv > a.recv;
			return false;
		} 
		return false;
	}
};
node buffer[SIZE*4];
int res[SIZE];
int pre[SIZE];
int col[SIZE];
int snum[SIZE];
int rnum[SIZE];
int mat[SIZE][SIZE];
int bike[SIZE];

struct wraper{
	wraper(){}
	wraper(int i):ind(i){
	}
	int ind;
	bool operator<(const wraper& a) const{
		if(buffer[ind].dist > buffer[a.ind].dist) return true;
		else if(buffer[ind].dist == buffer[a.ind].dist){
			if(buffer[ind].send > buffer[a.ind].send) return true;
			else if(buffer[ind].send == buffer[a.ind].send ) return buffer[ind].recv > buffer[a.ind].recv;
			return false;
		} 
		return false;
	}
};
priority_queue<wraper> pq;
int C,N;

int dij(int end){
	int sz = 0;
	memset(res,-1,sizeof(res));
	memset(pre,-1,sizeof(pre));
	node& nn = buffer[sz++];
	nn.to = 0;
	nn.dist = 0;
	nn.send = 0;
	nn.recv = 0;
	nn.next = -1;
	res[0] = 0;
	snum[0] = 0;
	rnum[0] = 0;
	pre[0]=-1;
	
	pq.push(wraper(sz-1));
	
	while(!pq.empty()){
//		while(!pq.empty() && col[pq.top().to]) pq.pop();
//		if(pq.empty()) break;
		int p = pq.top().ind;
		node& n = buffer[pq.top().ind];
		pq.pop();
//		col[n.to] = 1;
//		cout<<n.to<<endl;
		if(n.to == end) return p;
		for(int i=0;i<=N;i++)
			if(mat[n.to][i]!=-1 && col[i]==0){
				if(res[i]==-1 || n.dist+mat[n.to][i] < res[i]){
					res[i] = n.dist + mat[n.to][i];
					snum[i] = n.send;
					rnum[i] = n.recv;
					if(bike[i] > C/2) rnum[i]+=bike[i]-C/2;
					else if(bike[i] < C/2) rnum[i] -= C/2-bike[i];
					if(rnum[i] < 0){
						snum[i] -= rnum[i];
						rnum[i] = 0;
					}
					node& v = buffer[sz++];
					v.to = i;
					v.dist = res[i];
					v.send = snum[i];
					v.recv = rnum[i];
					v.next = p;
					pq.push(wraper(sz-1));
//					pre[i] = n.to;
				}
				else if(n.dist + mat[n.to][i] == res[i]){
					if(bike[i] <= C/2 ){
						int st = n.send ;
						int rt = n.recv;
						rt -= C/2- bike[i];
						if(rt < 0){
							st -= rt;
							rt = 0;
						}
						if(st < snum[i] || (st == snum[i] /*&& rt < rnum[i]*/)){
							snum[i] = st;
							rnum[i] = rt;
							node& v = buffer[sz++];
							v.to = i;
							v.dist = res[i];
							v.send = snum[i];
							v.recv = rnum[i];
							v.next = p;
							pq.push(wraper(sz-1));
//							pre[i] = n.to;
						}
						
					}
					else if(bike[i] > C/2 && n.send < snum[i]){
						snum[i] = n.send;
						rnum[i] = n.recv + bike[i] - C/2;
						node& v = buffer[sz++];
						v.to = i;
						v.dist = res[i];
						v.send = snum[i];
						v.recv = rnum[i];
						v.next = p;
						pq.push(wraper(sz-1));
//						pre[i] = n.to;
					}
					else if(bike[i] > C/2 && n.send == snum[i] /*&& n.recv + bike[i] - C/2 < rnum[i]*/){
						rnum[i] = n.recv + bike[i] - C/2;
						node& v = buffer[sz++];
						v.to = i;
						v.dist = res[i];
						v.send = snum[i];
						v.recv = rnum[i];
						v.next = p;
						pq.push(wraper(sz-1));
//						pre[i] = n.to;
					}
				}
			}
	}
	return -1;
}

int main()
{
	memset(mat,-1,sizeof(mat));
	int M,E;
	scanf("%d%d%d%d",&C,&N,&E,&M);
	for(int i=1;i<=N;i++)
		scanf("%d",&bike[i]);
	for(int i=0;i<M;i++){
		int to,from,L;
		scanf("%d%d%d",&from,&to,&L);
		if(mat[from][to]==-1 || mat[from][to]>L)
			mat[from][to] = mat[to][from] = L;
	}
	int e = dij(E);
	int sz=0;
	int sres = buffer[e].send;
	int rres = buffer[e].recv;
	while(e!=-1){
		res[sz++] = buffer[e].to;
		e = buffer[e].next;
	}
	
	printf("%d ",sres);
	printf("%d",res[sz-1]);
	for(int i = sz-2;i>=0;i--) printf("->%d",res[i]);
	printf(" %d\n",rres);
}
