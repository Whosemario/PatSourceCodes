#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

struct student{
  char id[15];
	int score;
	int final_rank;
	int loc;
	int loc_rank;
};

#define SIZE 30005

student arr[SIZE];

bool cmp(const student& a, const student& b){
	if(a.score > b.score) return true;
	else if(a.score==b.score && strcmp(a.id,b.id)<0) return true;
	return false;
}

int main()
{
	int N;
	scanf("%d",&N);
	int M=0;
	for(int i=0;i<N;i++){
		int K;
		scanf("%d",&K);
		for(int j=0;j<K;j++){
			scanf("%s%d",arr[M+j].id,&arr[M+j].score);
			arr[M+j].loc = i+1;
		}
		sort(arr+M,arr+M+K,cmp);
		arr[M].loc_rank = 1;
		for(int j=M+1;j<M+K;j++)
			if(arr[j].score == arr[j-1].score) arr[j].loc_rank = arr[j-1].loc_rank;
			else arr[j].loc_rank = j-M+1;
		M+=K;
	}
	sort(arr,arr+M,cmp);
	arr[0].final_rank = 1;
	for(int i=1;i<M;i++)
		if(arr[i].score == arr[i-1].score) arr[i].final_rank = arr[i-1].final_rank;
		else arr[i].final_rank = i+1;
	printf("%d\n",M);
	for(int i=0;i<M;i++)
		printf("%s %d %d %d\n",arr[i].id,arr[i].final_rank,arr[i].loc,arr[i].loc_rank);
}