//============================================================================
// Name        : PAT1024.cpp
// Author      : Whosemario
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
using namespace std;

bool isPalindromic(char* in){
	int len = strlen(in);
	for(int i=0;i<len/2;i++)
		if(in[i]!=in[len-1-i]) return false;
	return true;
}

int main() {

	char in[200];
	char rev[200];
	int N;
	scanf("%s%d",in,&N);
	if(isPalindromic(in)){printf("%s\n0\n",in);}
	else{
		int num;
		for(num=1;num<=N;num++){
			int len = strlen(in);
			//reverse
			for(int i=0;i<len;i++)
				rev[i] = in[len-1-i];
			int c = 0;
			for(int i=0;i<len;i++){
				c += (in[i]-'0')+(rev[i]-'0');
				in[i] = c%10+'0';
				c/=10;
			}
			if(c){
				in[len]=c+'0';
				in[++len] = 0;
			}
			if(isPalindromic(in)) break;
		}
		if(num>N) num=N;
		//reverse
		int len = strlen(in);
		for(int i=0;i<len/2;i++){
			char c = in[i];
			in[i] = in[len-1-i];
			in[len-1-i] = c;
		}
		printf("%s\n%d\n",in,num);
	}
	return 0;
}
