//============================================================================
// Name        : PAT1051.cpp
// Author      : Whosemario
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
using namespace std;

#define SIZE 1002
int arr[SIZE];

int stack[SIZE];
int sz ;

int main() {
	int N,M,K;
	scanf("%d%d%d",&M,&N,&K);
	while(K--){
		for(int i=0;i<N;i++) scanf("%d",&arr[i]);
		int n=1;
		sz = 0;
		bool res = true;
		for(int i=0;i<N&&res;i++){
			if(sz==0){
				if(arr[i] < n) res=false;
				else if(arr[i]-n+1 > M) res = false;
				else{
					for(int j=n;j<arr[i];j++)
						stack[sz++] = j;
					n=arr[i]+1;
				}
			}
			else{
				if(arr[i]==stack[sz-1]){
					sz--;
				}
				else if(arr[i] < stack[sz-1]) res=false;
				else {
					if(arr[i] < n) res=false;
					else if(arr[i]-n+1+sz>M) res = false;
					else{
						for(int j=n;j<arr[i];j++)
							stack[sz++]=j;
						n=arr[i]+1;
					}
				}
			}
		}
		if(res) puts("YES");
		else puts("NO");
	}
	return 0;
}
