//============================================================================
// Name        : PAT1035.cpp
// Author      : Whosemario
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
using namespace std;

struct person{
	char name[15];
	char psw[15];
};

person arr[1005];
int sz;

int main() {
	int N;
	scanf("%d",&N);
	sz=0;
	for(int i=0;i<N;i++){
		scanf("%s%s",arr[sz].name,arr[sz].psw);
		int len = strlen(arr[sz].psw);
		bool flag = false;
		for(int j=0;j<len;j++){
			if(arr[sz].psw[j]=='1'){flag=true;arr[sz].psw[j]='@';}
			else if(arr[sz].psw[j]=='0'){flag=true;arr[sz].psw[j]='%';}
			else if(arr[sz].psw[j]=='l'){flag=true;arr[sz].psw[j]='L';}
			else if(arr[sz].psw[j]=='O'){flag=true;arr[sz].psw[j]='o';}
		}
		if(flag) sz++;
	}

	if(sz==0){
		if(N==1) puts("There is 1 account and no account is modified");
		else printf("There are %d accounts and no account is modified\n",N);
	}
	else{
		printf("%d\n",sz);
		for(int i=0;i<sz;i++)
			printf("%s %s\n",arr[i].name,arr[i].psw);
	}
	return 0;
}
