#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int n,num,book[20000],maxx[20000];
int main(){
	cin>>n;if(n==0) return puts("0"),0;
	for(int i=1;i<=n;i++){
		v.clear();v.push_back(0);memset(book,0,sizeof(book));
	    while(cin>>num&&num!=-1){
	        int size=v.size();
	        for(int j=0;j<size;j++)
	        if(!book[v[j]+num]){book[v[j]+num]=1;v.push_back(v[j]+num);}
		}
		int size=v.size();
		for(int j=0;j<size;j++) if(book[v[j]]) maxx[v[j]]++;
	}
	for(int i=20001;i>=0;i--)
	if(maxx[i]==n) return printf("%d\n",i),0;
	return puts("0"),0;
}
