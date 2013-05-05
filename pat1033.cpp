#include<iostream>
#include<algorithm>

using namespace std;

struct sta{
  double price;
	double pos;
}station[505];

bool cmp(const sta& a, const sta& b){
	return a.pos < b.pos;
};

int main()
{
    double CM,D,unit;
	int N;
	scanf("%lf%lf%lf%d",&CM,&D,&unit,&N);
	for(int i=0;i<N;i++)
		scanf("%lf%lf",&station[i].price,&station[i].pos);
	station[N].price = 0;
	station[N].pos = D;
	sort(station,station+N+1,cmp);
	double step = CM*unit;
	if(station[0].pos > 0){
		puts("The maximum travel distance = 0.00");
	}
	else{
		bool flag = true;
		for(int i=0;i<N;i++)
			if(station[i+1].pos-station[i].pos > step){
				printf("The maximum travel distance = %.2lf\n",station[i].pos+step);
				flag = false;
				break;
			}
		if(flag){
			double reminder = 0;
			double res = 0;
			for(int i=0;i<N;){
				int index = i;
				double minPrice = station[i].price;
				for(int j=i+1;j<=N&&station[j].pos-station[i].pos <= reminder*unit;j++)
					if(station[j].price < minPrice){
						index = j;
						minPrice = station[j].price;
					}
				if(index!=i){
					reminder -= (station[index].pos-station[index].pos)/unit;
					i = index;
					continue;
				}
				index = i;
				for(int j = i+1;j<=N&&station[j].pos-station[i].pos<=step;j++)
					if(station[j].price < minPrice){
						index = j;
						break;
					}
				if(index!=i){
					res += (station[index].pos-station[i].pos-reminder*unit)/unit*station[i].price;
					reminder = 0;
					i = index;
				}
				else{
					minPrice = -1;
					for(int j=i+1;j<=N&&station[j].pos-station[i].pos<=step;j++)
						if(minPrice==-1 || station[j].price < minPrice){
							index = j;
							minPrice = station[j].price;
						}
					res += (CM-reminder)*station[i].price;
					reminder = CM-(station[index].pos-station[i].pos)/unit;
					i = index;
				}
			}
			printf("%.2lf\n",res);
		}
	}
}
