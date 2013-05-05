//============================================================================
// Name        : PAT1019.cpp
// Author      : Whosemario
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int res[100];

int main() {
	int N,b;
	scanf("%d%d",&N,&b);
	if(N==0){
		puts("Yes");
		puts("0");
	}
	else{
		int sz=0;
		while(N){
			res[sz++] = N%b;
			N/=b;
		}
		bool flag = true;
		for(int i=0;i<sz;i++)
			if(res[i]!=res[sz-1-i]){
				flag = false;
				break;
			}
		if(flag){
			puts("Yes");
		}
		else{
			puts("No");
		}
		printf("%d",res[sz-1]);
		for(int i=sz-2;i>=0;i--)
			printf(" %d",res[i]);
		puts("");
	}
	return 0;
}
