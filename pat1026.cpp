//============================================================================
// Name        : PAT1026.cpp
// Author      : Whosemario
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
using namespace std;

struct player{
	int start,serve,wait,play;
};

#define SIZE 10005
player viparr[SIZE];
int vipsz=0;
player simarr[SIZE];
int simsz=0;
player res[SIZE];
int sz=0;

bool cmp1(const player& a, const player& b){ return a.start < b.start;}
bool cmp2(const player& a, const player& b){ return a.serve < b.serve;}

int servetime[102];
int isvip[102];
int num[102];

int main() {

	int N;
	scanf("%d",&N);

	for(int i=0;i<N;i++){
		int h,m,s;
		int p,v;
		scanf("%d:%d:%d %d %d",&h,&m,&s,&p,&v);
		if(h*3600+m*60+s < 8*3600 || h*3600+m*60+s > 21*3600) continue;
		if(v==0){
			simarr[simsz].start = h*3600+m*60+s;
			simarr[simsz++].play = p*60 > 7200 ? 7200 : p*60;  //用户只能玩2个小时，大于2个小时看成2个小时
		}
		else{
			viparr[vipsz].start = h*3600+m*60+s;
			viparr[vipsz++].play = p*60 > 7200 ? 7200 : p*60;
		}
	}
	sort(simarr,simarr+simsz,cmp1);
	sort(viparr,viparr+vipsz,cmp1);

	int K,M;
	scanf("%d%d",&K,&M);
	for(int i=0;i<M;i++){
		int v;
		scanf("%d",&v);
		isvip[v-1] = 1;
	}
	int end = 21*3600;
	int i=0,j=0;
	N = simsz+vipsz;
	for(int k=0;k<N;k++){
		if((i<vipsz && j==simsz) || (i<vipsz && viparr[i].start < simarr[j].start)){
			int ind = -1;
			int _min = -1;
			for(int l=0;l<K;l++)
				if(isvip[l]&&(servetime[l]<=viparr[i].start)){
					ind = l;
					_min = servetime[l];
					break;
				}
			if(ind==-1){
				for(int l=0;l<K;l++)
					if(servetime[l]<=viparr[i].start){
						ind = l;
						_min = servetime[l];
						break;
					}
			}
			if(ind==-1){
				ind = 0;
				_min = servetime[0];
				for(int l=0;l<K;l++)
					if(servetime[l] < _min){
						ind = l;
						_min = servetime[l];
					}
			}
			if(_min >= end) break;
			res[sz].start = viparr[i].start;
			res[sz].serve = _min > viparr[i].start ? _min : viparr[i].start;
			res[sz].wait = _min > viparr[i].start ? _min-viparr[i].start : 0;
			servetime[ind] = res[sz].serve + viparr[i].play;
			sz++;
			i++;
			if(res[sz-1].serve < end)
				num[ind]++;
		}
		else{
			int ind = -1;
			int _min = -1;
			for(int l=0;l<K;l++)
				if(servetime[l]<=simarr[j].start){
					ind = l;
					_min = servetime[l];
					break;
				}
			if(ind!=-1){
				if(_min >= end) break;
				res[sz].start = simarr[j].start;
				res[sz].serve = _min > simarr[j].start ? _min : simarr[j].start;
				res[sz].wait = _min > simarr[j].start ? _min-simarr[j].start : 0;
				servetime[ind] = res[sz].serve + simarr[j].play;
				sz++;
				j++;
				if(res[sz-1].serve < end)
					num[ind]++;
				continue;
			}
			ind = 0;
			_min = servetime[0];
			for(int l=0;l<K;l++)
				if(servetime[l] < _min){
					ind =l;
					_min = servetime[l];
				}
			if(_min >= end) break;
			if(isvip[ind]){
				if(i<vipsz && _min >= viparr[i].start){
					res[sz].start = viparr[i].start;
					res[sz].serve = _min > viparr[i].start ? _min : viparr[i].start;
					res[sz].wait = _min > viparr[i].start ? _min-viparr[i].start : 0;
					servetime[ind] = res[sz].serve + viparr[i].play;
					sz++;
					i++;
					if(res[sz-1].serve < end)
						num[ind]++;
					continue;
				}
			}
			res[sz].start = simarr[j].start;
			res[sz].serve = _min > simarr[j].start ? _min : simarr[j].start;
			res[sz].wait = _min > simarr[j].start ? _min-simarr[j].start : 0;
			servetime[ind] = res[sz].serve + simarr[j].play;
			sz++;
			j++;
			if(res[sz-1].serve < end)
				num[ind]++;
		}
	}

	sort(res,res+sz,cmp2);
	for(int i=0;i<sz;i++){
		if(res[i].serve < end)
			printf("%02d:%02d:%02d %02d:%02d:%02d %d\n",
					res[i].start/3600,res[i].start/60%60,res[i].start%60,
					res[i].serve/3600,res[i].serve/60%60,res[i].serve%60,
					(res[i].wait+30)/60);
	}
	printf("%d",num[0]);
	for(int i=1;i<K;i++)
		printf(" %d",num[i]);
	puts("");
	return 0;
}
