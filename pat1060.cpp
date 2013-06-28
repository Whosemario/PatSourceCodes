//============================================================================
// Name        : PAT1060.cpp
// Author      : Whosemario
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
 
#include <iostream>
#include <string.h>
using namespace std;
 
bool isZero(char * str){
  bool ret = true;
	int len = strlen(str);
	for(int i=0;i<len;i++)
		if(str[i]!='.' && str[i]!='0'){
			ret = false;
			break;
		}
	return ret;
}
 
void printNum(int N, char* str, int exp){
	if(isZero(str)){
		printf("0.");
		for(int i=0;i<N;i++) printf("0");
		printf("*10^%d",exp);
	}
	else{
		int ind ;
		int len = strlen(str);
		for(ind =0;ind<len;ind++)
			if(str[ind]!='0'&&str[ind]!='.') break;
		printf("0.");
		for(int i=0;i<N;i++)
			if(ind >= len){
				printf("0");
			}
			else if(str[ind]=='.'){
				ind++;
				i--;
			}
			else{
				printf("%c",str[ind++]);
			}
		printf("*10^%d",exp);
	}
}
 
int calcExp(char * str){
	if(isZero(str)) return 0;
	else{
		int dot,num;
		int len = strlen(str);
		for(num=0;num<len;num++)
			if(str[num]!='.' && str[num]!='0') break;
		for(dot=0;dot<len;dot++)
			if(str[dot]=='.') break;
		if(dot-num<0) return dot-num+1;
		else return dot-num;
	}
}
 
bool isEqual(int N , char* A, char* B){
	bool ret = true;
	int lenA = strlen(A);
	int lenB = strlen(B);
	int indA,indB;
	for(indA=0;indA<lenA;indA++)
		if(A[indA]!='.'&&A[indA]!='0') break;
	for(indB=0;indB<lenB;indB++)
		if(B[indB]!='.'&&B[indB]!='0') break;
	for(int i=0;i<N;){
		char a,b;
		if(indA>=lenA) a='0';
		else if(A[indA]=='.'){
			indA++;continue;
		}
		else a = A[indA];
 
		if(indB>=lenB) b='0';
		else if(B[indB]=='.'){
			indB++;continue;
		}
		else b=B[indB];
 
		if(a!=b){
			ret = false;
			break;
		}
	    i++;
	    indA++;
	    indB++;
	}
 
	return ret;
}
 
int main() {
	char A[103],B[103];
	int N;
	scanf("%d%s%s",&N,A,B);
	if(isZero(A) && isZero(B)){
		printf("YES ");
		printNum(N,A,0);
		puts("");
	}
	else if(isZero(A) || isZero(B)){
		printf("NO ");
		printNum(N,A,calcExp(A));
		printf(" ");
		printNum(N,B,calcExp(B));
		puts("");
	}
	else if(calcExp(A)!=calcExp(B)){
		printf("NO ");
		printNum(N,A,calcExp(A));
		printf(" ");
		printNum(N,B,calcExp(B));
		puts("");
	}else{
		if(isEqual(N,A,B)){
			printf("YES ");
			printNum(N,A,calcExp(A));
			puts("");
		}
		else{
			printf("NO ");
			printNum(N,A,calcExp(A));
			printf(" ");
			printNum(N,B,calcExp(B));
			puts("");
		}
	}
	return 0;
}