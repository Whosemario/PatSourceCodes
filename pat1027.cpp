//============================================================================
// Name        : PAT1027.cpp
// Author      : Whosemario
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

char hashmap[20] = {'0','1','2','3','4','5','6','7','8','9','A','B','C'};

string change(int n){
	if(n==0) return "00";
	if(n<13) return string("0")+hashmap[n];
	else{
		return string("")+hashmap[n/13]+hashmap[n%13];
	}
}

int main() {
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	cout<<"#"<<change(a)<<change(b)<<change(c)<<endl;
	return 0;
}
