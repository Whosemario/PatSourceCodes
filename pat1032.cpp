//============================================================================
// Name        : PAT1032.cpp
// Author      : Whosemario
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#define SIZE 100005

struct node{
	char w[2];
	int next;
};

node buffer[SIZE];

int main() {
	int head1,head2,N;
	scanf("%d%d%d",&head1,&head2,&N);
	for(int i=0;i<N;i++){
		int cur;
		scanf("%d",&cur);
		scanf("%s%d",buffer[cur].w,&buffer[cur].next);
	}
	int tail1 = head1;
	int tail2 = head2;
	if(tail1==-1 || tail2==-1) puts("-1");
	else{
		while(buffer[tail1].next!=-1) tail1=buffer[tail1].next;
		while(buffer[tail2].next!=-1) tail2=buffer[tail2].next;
		if(tail1!=tail2) puts("-1");
		else{
			int len1=0,len2=0;
			tail1=head1;
			while(tail1!=-1){len1++;tail1=buffer[tail1].next;}
			tail2=head2;
			while(tail2!=-1){len2++;tail2=buffer[tail2].next;}
			int offset = len1-len2;
			if(offset>=0){
				while(offset--) head1=buffer[head1].next;
				while(head1!=head2){
					head1=buffer[head1].next;
					head2=buffer[head2].next;
				}
				printf("%05d\n",head1);
			}
			else{
				while(offset++) head2=buffer[head2].next;
				while(head1!=head2){
					head1=buffer[head1].next;
					head2=buffer[head2].next;
				}
				printf("%05d\n",head1);
			}
		}
	}
	return 0;
}
