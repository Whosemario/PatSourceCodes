#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;

char* _hash[] = {
	"zero","one","two","three",
	"four","five","six","seven",
	"eight","nine"
};

char * res[10];

int main()
{
	char str[200];
	scanf("%s",str);
	int len = strlen(str);
	int sum = 0;
	for(int i=0;i<len;i++){
		sum += str[i]-'0';
	}
	if(sum==0){
		puts("zero");
	}
	else{
		int sz = 0;
		while(sum){
			res[sz++] = _hash[sum%10];
			sum/=10;
		}
		printf("%s",res[sz-1]);
		for(int i=sz-2;i>=0;i--)
			printf(" %s",res[i]);
		puts("");
	}
}

