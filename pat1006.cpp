#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	int M;
	scanf("%d",&M);
	char inname[20],outname[20];
	int in,out;
	for(int i=0;i<M;i++){
		char id[20];
		int tin,tout;
		scanf("%s",id);
		int h,m,s;
		scanf("%d:%d:%d",&h,&m,&s);
		tin = h*3600+m*60+s;
		if(i==0 || in > tin){
			strcpy(inname,id);
			in = tin;
		}
		scanf("%d:%d:%d",&h,&m,&s);
		tout = h*3600+m*60+s;
		if(i==0 || out < tout){
			strcpy(outname,id);
			out = tout;
		}
	}
	printf("%s %s\n",inname,outname);
}