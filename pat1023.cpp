//============================================================================
// Name        : PAT1023.cpp
// Author      : Whosemario
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
using namespace std;

void reverse(char * in){
	int len = strlen(in);
	for(int i=0;i<len/2;i++){
		char t = in[i];
		in[i] = in[len-1-i];
		in[len-1-i] = t;
	}
}

int cnt[10][2];

int main() {
	char in[30];
	scanf("%s",in);
	reverse(in);
	int c = 0;
	int len = strlen(in);
	for(int i=0;i<len;i++)
		cnt[in[i]-'0'][0]++;
	for(int i=0;i<len;i++){
		c += (in[i]-'0')*2;
		in[i] = c%10+'0';
		c/=10;
	}
	if(c){
		in[len] = c+'0';
		in[++len] = 0;
		reverse(in);
		printf("No\n%s\n",in);
	}
	else{
		for(int i=0;i<len;i++)
			cnt[in[i]-'0'][1]++;
		bool flag = true;
		for(int i=0;i<10;i++)
			if(cnt[i][0]!=cnt[i][1]){
				flag = false;
				break;
			}
		if(flag) puts("Yes");
		else puts("No");
		reverse(in);
		printf("%s\n",in);
	}
	return 0;
}
