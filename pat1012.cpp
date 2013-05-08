#include<iostream>
#include<algorithm>
using namespace std;

#define SIZE 1000002

int Rank[SIZE][4];

struct stu{
	int id,c,m,a,e;
};

bool cmpC(const stu& a, const stu& b){ return a.c > b.c;}
bool cmpM(const stu& a, const stu& b){ return a.m > b.m;}
bool cmpA(const stu& a, const stu& b){ return a.a > b.a;}
bool cmpE(const stu& a, const stu& b){ return a.e > b.e;}

stu arr[2005];

char cource[] = {'A','C','M','E'};

void output(int id){
	if(Rank[id][0]==0) puts("N/A");
	else{
		int res = 0;
		int sc = Rank[id][0];
		for(int i=1;i<4;i++)
			if(Rank[id][i] < sc){
				sc = Rank[id][i];
				res = i;
			}
		printf("%d %c\n",sc,cource[res]);
	}
}

int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++){
		scanf("%d%d%d%d",&arr[i].id,&arr[i].c,&arr[i].m,&arr[i].e);
		arr[i].a = (int)((arr[i].c+arr[i].m+arr[i].e)*1.0/3+0.5);
	}

	//A
	sort(arr,arr+N,cmpA);
	Rank[arr[0].id][0] = 1;
	for(int i=1;i<N;i++)
		if(arr[i].a == arr[i-1].a) Rank[arr[i].id][0]=Rank[arr[i-1].id][0];
		else Rank[arr[i].id][0]=i+1;
	//C
	sort(arr,arr+N,cmpC);
	Rank[arr[0].id][1] = 1;
	for(int i=1;i<N;i++)
		if(arr[i].c == arr[i-1].c) Rank[arr[i].id][1]=Rank[arr[i-1].id][1];
		else Rank[arr[i].id][1]=i+1;
	//M
	sort(arr,arr+N,cmpM);
	Rank[arr[0].id][2] = 1;
	for(int i=1;i<N;i++)
		if(arr[i].m == arr[i-1].m) Rank[arr[i].id][2]=Rank[arr[i-1].id][2];
		else Rank[arr[i].id][2]=i+1;
	//E
	sort(arr,arr+N,cmpE);
	Rank[arr[0].id][3] = 1;
	for(int i=1;i<N;i++)
		if(arr[i].e == arr[i-1].e) Rank[arr[i].id][3]=Rank[arr[i-1].id][3];
		else Rank[arr[i].id][3]=i+1;

	for(int i=0;i<M;i++){
		int tmp;
		scanf("%d",&tmp);
		output(tmp);
	}
}