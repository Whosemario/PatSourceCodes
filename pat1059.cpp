#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

int prime[5000];
int sz;

int main()
{
	int num;
	scanf("%d",&num);
	int top = sqrt(num*1.0)+2;
	prime[sz++]=2;
	for(int p = 3;p<=top;p+=2){
		bool flag = true;
		for(int i=0;i<sz&&prime[i]*prime[i]<=p;i++)
			if(p%prime[i]==0){
				flag = false;
				break;
			}
		if(flag) prime[sz++]=p;
	}

	if(num==1) puts("1=1");
	else{
		printf("%d=",num);
		int ind = 0;
		int pre = 0;
		int cnt = 0;
		while(num>1){
			for(;ind<sz;ind++)
				if(num%prime[ind]==0) break;
			if(ind==sz){
				if(pre!=0){
					if(cnt>1)
						printf("%d^%d*",pre,cnt);
					else
						printf("%d*",pre);

				}
				pre = num;
				cnt = 1;
				num=1;
			}
			else{
				num/=prime[ind];
				if(prime[ind]!=pre){
					if(pre!=0){
						if(cnt > 1)
							printf("%d^%d*",pre,cnt);
						else
							printf("%d*",pre);
					}
					pre = prime[ind];
					cnt=1;
				}
				else cnt++;
			}

		}
		if(cnt>1)
			printf("%d^%d\n",pre,cnt);
		else
			printf("%d\n",pre);
	}
}