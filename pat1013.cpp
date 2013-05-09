#include<iostream>
#include<string.h>
using namespace std;

#define SIZE 1003

struct edge{
	int next,to;
};

edge buffer[SIZE*SIZE];
int list[SIZE];
int ind;

void init(){memset(list,-1,sizeof(list));ind=0;}
void insert(int a,int b){
	buffer[ind].next = list[a];
	buffer[ind].to = b;
	list[a] = ind++;
	buffer[ind].next = list[b];
	buffer[ind].to = a;
	list[b] = ind++;
}

int col[SIZE];
int queue[SIZE];

void dfs(int u,int con){
	col[u] = 1;
	int head=0,tail=0;
	queue[tail++]=u;
	while(head < tail){
		int v = queue[head++];
		for(int p = list[v];p!=-1;p=buffer[p].next)
			if(buffer[p].to!=con && col[buffer[p].to]==0){
				col[buffer[p].to]=1;
				queue[tail++]=buffer[p].to;
			}
	}
}

int main()
{
	int N,M,K;
	init();
	scanf("%d%d%d",&N,&M,&K);
	for(int i=0;i<M;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		insert(a,b);
	}
	for(int i=0;i<K;i++){
		int con;
		scanf("%d",&con);
		memset(col,0,sizeof(col));
		int num = 0;
		for(int j=1;j<=N;j++)
			if(col[j]==0 && j!=con){
				num++;
				dfs(j,con);
			}
		printf("%d\n",(num?(num-1):0));
	}
}