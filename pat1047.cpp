//============================================================================
// Name        : PAT1047.cpp
// Author      : Whosemario
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct student{
	string name;
	vector<int> c;
};

student stu[40005];

bool cmp(const student& a, const student& b){return a.name<b.name;}

vector<string> cla[2502];

int main() {
	int N,K;
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++){
		char na[10];
		int num;
		scanf("%s%d",na,&num);
		stu[i].name=na;
		for(int j=0;j<num;j++){
			int cn;
			scanf("%d",&cn);
			stu[i].c.push_back(cn);
		}
	}
	sort(stu,stu+N,cmp);
	for(int i=0;i<N;i++){
		int size = stu[i].c.size();
		for(int j=0;j<size;j++)
			cla[stu[i].c[j]].push_back(stu[i].name);
	}

	for(int i=1;i<=K;i++){
		int size = cla[i].size();
		printf("%d %d\n",i,size);
		for(int j=0;j<size;j++)
			printf("%s\n",cla[i][j].c_str());
	}
	return 0;
}
