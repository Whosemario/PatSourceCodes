//============================================================================
// Name        : PAT1050.cpp
// Author      : Whosemario
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
using namespace std;

char S1[10003];
char S2[10003];

int mapSet[200];

int main() {
	gets(S1);
	gets(S2);

	int len = strlen(S2);
	for(int i=0;i<len;i++)
		mapSet[(int)S2[i]] = 1;
	int j=0;
	len = strlen(S1);
	for(int i=0;i<len;i++)
		if(mapSet[(int)S1[i]]==0) S1[j++] = S1[i];
	S1[j]=0;
	puts(S1);
	return 0;
}
