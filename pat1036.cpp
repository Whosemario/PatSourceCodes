//============================================================================
// Name        : PAT1036.cpp
// Author      : Whosemario
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
using namespace std;

int main() {
	int N;
	scanf("%d",&N);
	int maxF=-1,minM=-1;
	char resFN[15],resFID[15],resMN[15],resMID[15];
	char name[15],g[3],id[15];
	int score;
	for(int i=0;i<N;i++){
		scanf("%s%s%s%d",name,g,id,&score);
		if(g[0]=='M'){
			if(minM==-1 || score < minM){
				minM = score;
				strcpy(resMN,name);
				strcpy(resMID,id);
			}
		}
		else{
			if(maxF==-1 || score > maxF){
				maxF = score;
				strcpy(resFN,name);
				strcpy(resFID,id);
			}
		}
	}

	if(maxF!=-1) printf("%s %s\n",resFN,resFID);
	else puts("Absent");

	if(minM!=-1) printf("%s %s\n",resMN,resMID);
	else puts("Absent");

	if(maxF!=-1 && minM!=-1) printf("%d\n",maxF-minM);
	else puts("NA");

	return 0;
}
