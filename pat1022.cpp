#include<iostream>
#include<string.h>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

#define SIZE 10003

struct Book{
	string id,title,author,key[5],publisher,year;
	int keyn;
}buffer[SIZE];

bool comp(const Book& a,const Book& b){ return a.id < b.id; }

map<string,vector<string> > _hash[5];

int main()
{
	int N;
	scanf("%d",&N);
	char ss[5];
	gets(ss);
	for(int i=0;i<N;i++){
		char input[100];
		gets(input);
		buffer[i].id = input;
		gets(input);
		buffer[i].title = input;
		gets(input);
		buffer[i].author = input;
		gets(input);
		int len = strlen(input);
		char keyword[15];
		buffer[i].keyn = 0;
		int j=0;
		for(int k=0;k<len;k++)
			if(input[k]==' '){
				keyword[j]=0;
				j=0;
				buffer[i].key[buffer[i].keyn++] = keyword;
			}
			else{
				keyword[j++]=input[k];
			}
		keyword[j]=0;
		buffer[i].key[buffer[i].keyn++] = keyword;
		gets(input);
		buffer[i].publisher = input;
		gets(input);
		buffer[i].year = input;
	}

	sort(buffer,buffer+N,comp);

	for(int i=0;i<N;i++){
		//1 book title
		_hash[0][buffer[i].title].push_back(buffer[i].id);
		//2 author
		_hash[1][buffer[i].author].push_back(buffer[i].id);
		//3 key word
		for(int j=0;j<buffer[i].keyn;j++)
			_hash[2][buffer[i].key[j]].push_back(buffer[i].id);
		//4 publisher
		_hash[3][buffer[i].publisher].push_back(buffer[i].id);
		//5 year
		_hash[4][buffer[i].year].push_back(buffer[i].id);
	}

	scanf("%d",&N);
	gets(ss);
	for(int i=0;i<N;i++){
		char input[200];
		gets(input);
		puts(input);
		int len = strlen(input);
		int ind = input[0]-'0';
		int j=0;
		for(int i=3;i<len;i++,j++)
			input[j] = input[i];
		input[j]=0;
		string srh = input;
		map<string,vector<string> >::iterator it;
		if((it = _hash[ind-1].find(srh))==_hash[ind-1].end())
			puts("Not Found");
		else{
			vector<string>& v = it->second;
			for(int ii=0;ii<v.size();ii++)
				cout<<v[ii]<<endl;
		}
	}
}