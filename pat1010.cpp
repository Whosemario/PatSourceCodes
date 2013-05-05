//============================================================================
// Name        : PAT1010.cpp
// Author      : Whosemario
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
using namespace std;

int equal(char* A, char* B){
	int i,j;
	for(int i=0;i<strlen(A);i++) if(A[i]!='0') break;
	for(int j=0;j<strlen(B);j++) if(B[j]!='0') break;
	int lenA = strlen(A);
	int lenB = strlen(B);
	if(lenA-i != lenB-j) return -1;
	for(int k=0;k<lenA-i;k++)
		if(A[lenA-1-k]!=B[lenB-1-k]) return false;
	if(lenA-i==1&&A[lenA-1]=='1') return 1;
	return 2;
}

long long str2Num(char * A, long long radix){
	int len = strlen(A);
	long long ret = 0;
	long long p =1;

	for(int i=len-1;i>=0;i--){
		int num ;
		if(A[i]>='0' && A[i]<='9') num = A[i]-'0';
		else num = A[i]-'a'+10;
		ret += p*num;
		p*=radix;
	}

	return ret;
}

long long calcRadix(char * B){
	long long ret = 0;
	int len = strlen(B);
	for(int i=0;i<len;i++){
		int num ;
		if(B[i]>='0' && B[i]<='9') num = B[i]-'0';
		else num = B[i]-'a'+10;
		if(num+1>ret) ret=num+1;
	}
	return ret;
}

int compare(char* B, long long radix, long long target){
	int len = strlen(B);
	long long ret = 0;
	long long p = 1;
	for(int i=len-1;i>=0;i--){
		int num;
		if(B[i]>='0' && B[i]<='9') num = B[i]-'0';
		else num = B[i]-'a'+10;
		ret += p*num;
		if(ret > target) return 1;
		p*=radix;
	}
	if(ret > target) return 1;
	else if(ret<target) return -1;
	else return 0;
}

long long binarySearch(char* B, long long low, long long high, long long target){
	long long mid;
	while(low<=high){
		mid = (low+high)/2;
		int res = compare(B,mid,target);
		if(res > 0)
			high = mid-1;
		else if(res<0)
			low = mid+1;
		else return mid;
	}
	return -1;
}

int main() {
	char A[12];
	char B[12];
	int chose;
	long long radix;

	cin>>A>>B>>chose>>radix;
	int eq = equal(A,B);
	if(eq==1) printf("2\n");
	else if(eq==2) printf("%d\n",radix);
	else{
		if(chose==1){
			long long target = str2Num(A,radix);
			long long least = calcRadix(B);
			long long most = (target)>(least)?(target):(least);  // input : 11 b 1 10
			long long res = binarySearch(B,least,most,target);
			if(res==-1) cout<<"Impossible"<<endl;
			else cout<<res<<endl;
		}
		else{
			long long target = str2Num(B,radix);
			long long least = calcRadix(A);
			long long most = (target)>(least)?(target):(least);
			long long res = binarySearch(A,least,most,target);
			if(res==-1) cout<<"Impossible"<<endl;
			else cout<<res<<endl;
		}
	}
	return 0;
}
