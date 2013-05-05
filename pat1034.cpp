//============================================================================
// Name        : PAT1034.cpp
// Author      : Whosemario
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

map<string,int> hash1;
map<int,string> hash2;

int sz = 0;

struct node{
	int val;
	int next;
}buffer[2500];
int ind = 0;
int list[2500];
void insert(int a,int b){
	buffer[ind].val = b;
	buffer[ind].next = list[a];
	list[a]=ind++;
	buffer[ind].val = a;
	buffer[ind].next = list[b];
	list[b] = ind++;
}

int weight[2500];
int num,sum,maxw;
string name;
int col[2500];

void dfs(int u){
	num++;
	sum+=weight[u];
	if(weight[u]>maxw){maxw=weight[u];name=hash2[u];}
	for(int p=list[u];p!=-1;p=buffer[p].next)
		if(col[buffer[p].val]==0){
			col[buffer[p].val] = 1;
			dfs(buffer[p].val);
		}
}

struct person{
	string na;
	int w;
};

person res[1005];

bool cmp(const person& a, const person& b){
	return a.na < b.na;
}

int main() {
	int N,K;
	scanf("%d%d",&N,&K);
	sz=0;ind=0;
	memset(weight,0,sizeof(weight));
	memset(list,-1,sizeof(list));
	while(N--){
		char a[5],b[5];
		int ti ;
		scanf("%s%s%d",a,b,&ti);
		string aa=a,bb=b;
		int from , to;
		if(hash1.find(aa)!=hash1.end()) from = hash1[aa];
		else{
			hash1[aa]=sz++;
			from = sz-1;
			hash2[sz-1]=aa;
		}
		if(hash1.find(bb)!=hash1.end()) to = hash1[bb];
		else{
			hash1[bb]=sz++;
			to = sz-1;
			hash2[sz-1]=bb;
		}
		insert(from,to);
		weight[from]+=ti;
		weight[to]+=ti;
	}

	memset(col,0,sizeof(col));
	int len = 0;
	for(int i=0;i<sz;i++){
		if(col[i]==0){
			num=0;sum=0;maxw=-1;
			col[i]=1;
			dfs(i);
			if(num>2&&sum/2>K){
				res[len].na=name;
				res[len++].w = num;
			}
		}
	}

	sort(res,res+len,cmp);
	cout<<len<<endl;
	for(int i=0;i<len;i++)
		cout<<res[i].na<<" "<<res[i].w<<endl;
	return 0;
}
