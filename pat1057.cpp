//============================================================================
// Name        : PAT1057.cpp
// Author      : Whosemario
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>
#include <string>
#include <string.h>
using namespace std;

#define SIZE 100005
int stack[SIZE];
int sz = 0;
int mid = -1;

map<int,int> minTree;
map<int,int> maxTree;

void printTree(){
	for(map<int,int>::iterator it = minTree.begin();it!=minTree.end();it++) cout<<it->first<<" ";
	cout<<endl;
	for(map<int,int>::iterator it = maxTree.begin();it!=maxTree.end();it++) cout<<it->first<<" ";
	cout<<endl;
}
void pushValue(int value, bool isMin){
	if(isMin){
		map<int,int>::iterator it ;
		it = minTree.find(value);
		if(it!=minTree.end()) it->second += 1;
		else minTree[value] = 1;
	}
	else{
		map<int,int>::iterator it ;
		it = maxTree.find(value);
		if(it!=maxTree.end()) it->second += 1;
		else maxTree[value] = 1;
	}
}

int getValue(bool isMin){
	if(isMin){
		if(minTree.size()==0) return -1;
		map<int,int>::iterator it = minTree.end();
		--it;
		int ret = it->first;
		it->second -=1;
		if(it->second==0) minTree.erase(it);
		return ret;
	}
	else{
		if(maxTree.size()==0) return -1;
		map<int, int>::iterator it = maxTree.begin();
		int ret = it->first;
		it->second-=1;
		if(it->second==0) maxTree.erase(it);
		return ret;
	}
}
void eraseValue(int value, int isMin){
	if(isMin){
		map<int,int>::iterator it ;
		it = minTree.find(value);
		if(it->second==1) minTree.erase(it);
		else it->second-=1;
	}
	else{
		map<int,int>::iterator it;
		it = maxTree.find(value);
		if(it->second==1) maxTree.erase(it);
		else it->second-=1;
	}
}
int midVal(){return mid;}
void push(int value){
	if(sz==0){
		mid = value;
		stack[sz++]=value;
	}
	else if(sz&1){
		if(value >= mid){
			pushValue(value,false);
		}
		else{
			pushValue(value,true);
			pushValue(mid,false);
			mid = getValue(true);
		}
		stack[sz++]=value;
	}
	else{
		if(value>=mid){
			pushValue(value,false);
			pushValue(mid,true);
			mid = getValue(false);
		}
		else{
			pushValue(value,true);
		}
		stack[sz++]=value;
	}
}
int pop(){
	if(sz==0) return -1;
	else if(sz&1){
		int ret = stack[--sz];
		if(ret==mid){
			mid = getValue(true);
		}
		else if(ret > mid){
			eraseValue(ret,false);
			pushValue(mid,false);
			mid = getValue(true);
		}
		else{
			eraseValue(ret,true);
		}
		return ret;
	}
	else{
		int ret = stack[--sz];
		if(ret==mid){
			mid = getValue(false);
		}
		else if(ret>mid){
			eraseValue(ret,false);
		}
		else{
			eraseValue(ret,true);
			pushValue(mid,true);
			mid = getValue(false);
		}
		return ret;
	}
}
int main() {
	int N;
	scanf("%d",&N);
	while(N--){
		char oper[15];
		scanf("%s",oper);
		if(strcmp(oper,"Pop")==0){
			int res = pop();
			if(res==-1) puts("Invalid");
			else printf("%d\n",res);
//			printTree();
		}
		else if(strcmp(oper,"Push")==0){
			int val ;
			scanf("%d",&val);
			push(val);
//			printTree();
		}
		else{
			int res = midVal();
			if(res==-1) puts("Invalid");
			else printf("%d\n",res);
//			printTree();
		}
	}
	return 0;
}
