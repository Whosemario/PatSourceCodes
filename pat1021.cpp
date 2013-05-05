#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

#define SIZE 10005

struct Edge{
  int to;
	int next;
};
Edge buffers[SIZE*2];
int ind=0;

int list[SIZE];

void initList(){ind=0;memset(list,-1,sizeof(list));}
void insert(int a, int b){
	buffers[ind].to = b;
	buffers[ind].next = list[a];
	list[a]=ind++;
	buffers[ind].to = a;
	buffers[ind].next = list[b];
	list[b]=ind++;
}

int dist[SIZE];

int queue[SIZE];

void bfs(int root){
	int head=0,tail = 0;
	queue[tail++]=root;
	dist[root]=1;
	while(head<tail){
		int u = queue[head++];
		for(int p = list[u];p!=-1;p=buffers[p].next){
			int v = buffers[p].to;
			if(dist[v]==0){
				dist[v]=1;
				queue[tail++]=v;
			}
		}
	}
}

int dij(int root){
	memset(dist,-1,sizeof(dist));
	int head=0,tail=0;
	queue[tail++]=root;
	dist[root]=0;
	int ret=0;
	while(head<tail){
		int u = queue[head++];
		for(int p=list[u];p!=-1;p=buffers[p].next){
			int v = buffers[p].to;
			if(dist[v]==-1){
				dist[v] = dist[u]+1;
				if(dist[v]>ret) ret=dist[v];
				queue[tail++]=v;
			}
		}
	}
	return ret;
}

vector<int> res;

int main()
{
	int N;
	scanf("%d",&N);
	initList();
	for(int i=0;i<N-1;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		insert(a,b);
	}

	memset(dist,0,sizeof(dist));
	int comp=0;
	for(int i=1;i<=N;i++)
		if(dist[i]==0){
			comp++;
			bfs(i);
		}
	if(comp>1){
		printf("Error: %d components\n",comp);
	}
	else{
		int maxv = dij(1);
		for(int i=1;i<=N;i++)
			if(dist[i]==maxv){
				res.push_back(i);
			}
		maxv = dij(res[0]);
		for(int i=1;i<=N;i++)
			if(dist[i]==maxv) res.push_back(i);
		sort(res.begin(),res.end());
		printf("%d\n",res[0]);
		for(int i=1;i<res.size();i++)
			if(res[i]!=res[i-1])
				printf("%d\n",res[i]);
	}
}