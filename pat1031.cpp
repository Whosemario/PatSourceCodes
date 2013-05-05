//============================================================================
// Name        : PAT1031.cpp
// Author      : Whosemario
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
using namespace std;

int main() {
	char str[100];
	scanf("%s",str);
	int len = strlen(str);
	int n1;
	for(n1=1;n1*3<=len+2;n1++);
	n1--;
	int n2=len-2*n1+2;
	for(int i=1,j=0;i<n1;i++,j++){
		printf("%c",str[j]);
		for(int k=1;k<=n2-2;k++) printf(" ");
		printf("%c\n",str[len-j-1]);
	}
	for(int i=0,j=n1-1;i<n2;i++,j++) printf("%c",str[j]);
	puts("");
	return 0;
}
