#include<iostream>
#include<algorithm>
using namespace std;

#define SIZE 10005

struct customer{
	int arrive;
	int cost;
}arr[SIZE];

bool comp(const customer& a, const customer& b){return a.arrive < b.arrive;}

const int startT = 8*3600;
const int endT = 17*3600;

int win[103];

int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++){
		int h,m,s;
		scanf("%d:%d:%d %d",&h,&m,&s,&arr[i].cost);
		arr[i].arrive = h*3600+m*60+s;
	}
	sort(arr,arr+N,comp);
	for(int i=0;i<M;i++) win[i] = startT;
	int res = 0;
	int num = 0;
	for(int i=0;i<N;i++){
		if(arr[i].arrive > endT) break;  //anyone comes too late (at or after 17:00:01) will not be served nor counted into the average
		int ind = -1;
		int _min;
		for(int j=0;j<M;j++){
			int w = win[j]<=arr[i].arrive?0:(win[j]-arr[i].arrive);
			if(ind==-1 || w<_min){
				ind = j;
				_min = w;
			}
		}
		win[ind] = win[ind]<=arr[i].arrive?arr[i].arrive:win[ind];
		res+=(win[ind]==arr[i].arrive?0:(win[ind]-arr[i].arrive));
		win[ind]+=arr[i].cost*60;
		num++;
	}
	if(res) printf("%.1lf\n",res*1.0/60/num);
	else puts("0.0");
}