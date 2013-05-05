//============================================================================
// Name        : PAT1054.cpp
// Author      : Whosemario
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int M, N;
	scanf("%d%d",&M,&N);
	int num=0;
	int candidate=-1;
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++){
			int val;
			scanf("%d",&val);
			if(num==0){
				candidate = val;
				num++;
			}
			else if(val == candidate) ++num;
			else{
				--num;
			}
		}
	printf("%d\n",candidate);
	return 0;
}
