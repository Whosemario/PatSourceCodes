//============================================================================
// Name        : PAT1016.cpp
// Author      : Whosemario
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
 
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <queue>
#include <assert.h>
using namespace std;
 
int cost[30];
 
struct OneCall{
  int mon,d,h,m;
  int on;
  void addOneHour(){
	h+=1;
	m=0;
	if(h==24){d+=1;h=0;}
  }
};
 
bool comp(const OneCall& a , const OneCall& b){
	if(a.mon < b.mon) return true;
	else if(a.mon == b.mon && a.d < b.d) return true;
	else if(a.mon == b.mon && a.d == b.d && a.h < b.h) return true;
	else if(a.mon == b.mon && a.d == b.d && a.h == b.h && a.m < b.m ) return true;
	return false;
}

 
map<string,vector<OneCall> > record;
 
int main() {
 
	for(int i=0;i<24;i++)
		scanf("%d",&cost[i]);
	int N;
	scanf("%d",&N);
	for(int k=0;k<N;k++){
		char name[22];
		char state[10];
		OneCall obj;
		scanf("%s %d:%d:%d:%d %s",name,&obj.mon,&obj.d,&obj.h,&obj.m,state);
		if(strcmp(state,"on-line")==0) obj.on = 1;
		else obj.on = 0;
		string tname = name;
		vector<OneCall>& v = record[tname];
		v.push_back(obj);
	}
 
	map<string,vector<OneCall> >::iterator it;
	for(it = record.begin();it!=record.end();++it){
		vector<OneCall>& v = it->second;
		sort(v.begin(),v.end(),comp);
		int flag = 0;
		for(int i=0;i<v.size();i++)
			if(v[i].on) flag=1;
			else if(flag){flag=2;break;}
		if(flag < 2) continue;
		cout<<it->first<<" ";
		printf("%02d\n",v[0].mon);
		int sum = 0;
		
		int ind = -1;
		for(int i=0;i<v.size();i++){
			if(v[i].on) ind=i;
			else if(ind!=-1){
				int toll = 0;
				int offset = (v[i].d*24*60+v[i].h*60+v[i].m)-(v[ind].d*24*60+v[ind].h*60+v[ind].m);
				printf("%02d:%02d:%02d ",v[ind].d,v[ind].h,v[ind].m);
				while(!comp(v[i],v[ind])){
					if(v[i].d == v[ind].d && v[i].h == v[ind].h){
						toll += (v[i].m-v[ind].m)*cost[v[i].h];
					}
					else{
						toll += (60-v[ind].m)*cost[v[ind].h];
					}
					v[ind].addOneHour();
				}
				sum+=toll;
				printf("%02d:%02d:%02d %d $%.2lf\n",v[i].d,v[i].h,v[i].m,offset,toll*1.0/100);
				ind = -1;
			}
		}
		//assert(sum);
		printf("Total amount: $%.2lf\n",sum*1.0/100);
	}
	return 0;
}