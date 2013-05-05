//============================================================================
// Name        : PAT1055.cpp
// Author      : Whosemario
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

struct Node{
	int age;
	int worth;
	string name;
//	char name2[10];
	Node& operator=(const Node& node){
		age = node.age;
		worth = node.worth;
		name = node.name;
//		for(int i=0;i<name.length();i++) name2[i]=name[i];
		return *this;
	}
};

bool compare(const Node& a,const Node& b){
	if(a.worth > b.worth) return true;
	else if(a.worth == b.worth){
		if(a.age < b.age) return true;
		else if(a.age == b.age) return a.name<b.name;
		return false;
	}
	return false;
}

int sz[201];
Node arr[100002];

int main() {
	int N,Q;
	char input[10];
	scanf("%d%d",&N,&Q);
	for(int i=0;i<N;i++){
		scanf("%s%d%d",input,&arr[i].age,&arr[i].worth);
		arr[i].name = input;
	}
	sort(arr,arr+N,compare);
	int total = 0;
	for(int i=0;i<N;i++)
		if(++sz[arr[i].age]<=100)
		arr[total++] = arr[i];
	for(int ca = 1;ca<=Q;ca++){  // time complex is 10^3*2*10^4

		printf("Case #%d:\n",ca);

		int M , Amin, Amax;
		scanf("%d%d%d",&M,&Amin,&Amax);
		bool None = true;

		for(int i=0;i<total&&M;i++)
			if(arr[i].age>=Amin && arr[i].age<=Amax){
				printf("%s %d %d\n",arr[i].name.c_str(),arr[i].age,arr[i].worth);
				--M;
				None = false;
			}
		if(None) puts("None");
	}
	return 0;
}
