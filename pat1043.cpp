//============================================================================
// Name        : PAT1043.cpp
// Author      : Whosemario
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct node{
	int val;
	int left,right;
};

#define SIZE 1003
node buffers[SIZE];
int ind;

int arr[SIZE];

int dfs(int first , int last, bool isMirror){
	buffers[ind].val = arr[first];
	buffers[ind].left = -1;
	buffers[ind].right = -1;
	int tmp = ind;
	ind++;
	if(first == last){
		return ind-1;
	}
	else{
		if(isMirror){
			int i = first+1;
			while(i<=last&&arr[i]>=arr[first]) ++i;
			i=i-1;
			for(int j=i+1;j<=last;j++)
				if(arr[j]>=arr[first]) return -1;
			if(i-first>0){
				int ret = dfs(first+1,i,isMirror);
				if(ret==-1) return -1;
				else buffers[tmp].left = ret;
			}
			if(i+1<=last){
				int ret = dfs(i+1,last,isMirror);
				if(ret==-1) return -1;
				else buffers[tmp].right = ret;
			}
			return tmp;
		}
		else{
			int i = first+1;
			while(i<=last&&arr[i]<arr[first]) ++i;
			i=i-1;
			for(int j=i+1;j<=last;j++)
				if(arr[j]<arr[first]) return -1;
			if(i-first>0){
				int ret = dfs(first+1,i,isMirror);
				if(ret==-1) return -1;
				else buffers[tmp].left = ret;
			}
			if(i+1<=last){
				int ret = dfs(i+1,last,isMirror);
				if(ret==-1) return -1;
				else buffers[tmp].right = ret;
			}
			return tmp;
		}

	}

}

int flag = 0;
void print(int root){
	if(buffers[root].left!=-1)
		print(buffers[root].left);
	if(buffers[root].right!=-1)
		print(buffers[root].right);
	if(flag) printf(" %d",buffers[root].val);
	else{
		flag =1;
		printf("%d",buffers[root].val);
	}
}

int main() {
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++) scanf("%d",&arr[i]);
	ind=0;
	int res = dfs(0,N-1,false);
	if(res==-1){ind=0;res=dfs(0,N-1,true);}
	if(res==-1) puts("NO");
	else{
		puts("YES");
		print(res);
		puts("");
	}
	return 0;
}
