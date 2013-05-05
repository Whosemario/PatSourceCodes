//============================================================================
// Name        : PAT1049.cpp
// Author      : Whosemario
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	int pre,last=0,last10=1;
	long long res = 0;
	while(n){
		int x = n%10;
		pre = n/10;
		if(x>1){
			res += ((long long)(pre+1))*last10;
		}
		else if(x==1){
			res += ((long long)pre)*last10+last+1;
		}
		else{
			res += ((long long)pre)*last10;
		}
		last+=x*last10;
		last10*=10;
		n=pre;
	}
	cout<<res<<endl;
	return 0;
}
