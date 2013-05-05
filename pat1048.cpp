//============================================================================
// Name        : PAT1048.cpp
// Author      : Whosemario
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
using namespace std;

int arr[100005];

int main() {

	int N,M;
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)
		scanf("%d",&arr[i]);
	sort(arr,arr+N);
	int i=0,j=N-1;
	while(i<j){
		if(arr[i]+arr[j]==M){
			printf("%d %d\n",arr[i],arr[j]);
			break;
		}
		else if(arr[i]+arr[j]>M) j--;
		else i++;
	}
	if(i>=j) puts("No Solution");
	return 0;
}
