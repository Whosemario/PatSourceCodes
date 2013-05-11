#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define SIZE 22
queue<int> win[SIZE];

int ti[1002];
int res[1002];
int cnt[SIZE];

const int startT = 8*60;
const int endT = 17*60;

int main()
{
	int N,M,K,Q;
	scanf("%d%d%d%d",&N,&M,&K,&Q);
	for(int i=1;i<=K;i++)
		scanf("%d",&ti[i]);
	for(int i=1;i<=N;i++){
		for(int j=i,k=1;j<=K&&k<=M;j+=N,++k)
			win[i].push(j);
	}

	for(int i = N*M+1;i<=K;i++){
		int ind = -1;
		int _min;
		for(int j=1;j<=N;j++)
			if(win[j].size()){
				if(ind==-1 || cnt[j]+ti[win[j].front()] < _min){
					ind = j;
					_min = cnt[j]+ti[win[j].front()];
				}
			}
		if(ind==-1) break;
		cnt[ind] = _min;
		res[win[ind].front()] = _min;
		win[ind].pop();
		win[ind].push(i);
	}

	while(1){
		int ind = -1;
		int _min;
		for(int j=1;j<=N;j++)
			if(win[j].size()){
				if(ind==-1 || cnt[j]+ti[win[j].front()] < _min){
					ind = j;
					_min = cnt[j]+ti[win[j].front()];
				}
			}
		if(ind==-1) break;
		cnt[ind] = _min;
		res[win[ind].front()] = _min;
		win[ind].pop();
	}

	for(int i=0;i<Q;i++){
		int q;
		scanf("%d",&q);
		if(res[q]+startT-ti[q]>=endT) puts("Sorry");
		else
			printf("%02d:%02d\n",(res[q]+startT)/60,(res[q]+startT)%60);
	}
}