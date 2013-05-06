#include<iostream>
using namespace std;

struct node{
	int val,next;
};

#define SIZE 100002
node buffer[SIZE];

int merge(int pHead1, int pHead2){
	if(pHead1 == -1) return pHead2;
	if(pHead2 == -1) return pHead1;
	int ret = -1;
	if(buffer[pHead1].val < buffer[pHead2].val){
		ret = pHead1;
		pHead1 = buffer[pHead1].next;
	}
	else{
		ret = pHead2;
		pHead2 = buffer[pHead2].next;
	}
	int tail = ret;
	while(pHead1 !=-1 && pHead2 != -1){
		if(buffer[pHead1].val < buffer[pHead2].val){
			buffer[tail].next = pHead1;
			pHead1 = buffer[pHead1].next;
		}
		else{
			buffer[tail].next = pHead2;
			pHead2 = buffer[pHead2].next;
		}
		tail = buffer[tail].next;
	}
	if(pHead1!=-1) buffer[tail].next = pHead1;
	if(pHead2!=-1) buffer[tail].next = pHead2;
	return ret;
}

int mergeSort(int head){
	if(head==-1 || buffer[head].next ==-1) return head;
	int slow = head;
	int fast = head;
	while(buffer[fast].next !=-1 && buffer[buffer[fast].next].next != -1){
		fast =  buffer[buffer[fast].next].next;
		slow = buffer[slow].next;
	}
	int mid = buffer[slow].next;
	buffer[slow].next = -1;
	head = mergeSort(head);
	mid = mergeSort(mid);
	head = merge(head,mid);
	return head;
}

int main()
{
	int N,head;
	scanf("%d%d",&N,&head);
	for(int i=0;i<N;i++){
		int ind,val,next;
		scanf("%d%d%d",&ind,&val,&next);
		buffer[ind].val = val;
		buffer[ind].next = next;
	}
	head = mergeSort(head);
	int cur = head;
	int num = 0;
	while(cur!=-1){
		++num;
		cur = buffer[cur].next;
	}
	if(num){
		printf("%d %05d\n",num,head);
		while(head != -1){
			if(buffer[head].next !=-1)
				printf("%05d %d %05d\n",head,buffer[head].val,buffer[head].next);
			else
				printf("%05d %d -1\n",head,buffer[head].val);
			head = buffer[head].next;
		}
	}
	else{
		printf("0 -1\n");
	}
}