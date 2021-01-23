#include<string.h>
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int next[100];
int main(){
	int T;cin>>T;
	while(T--){
		char s[100];cin>>(s+1);
		next[1]=0;
		for(int i=2,j=0;i<=strlen(s+1);i++){
			while(j>0&&s[i]!=s[j+1]) j=next[j];
			if(s[i]==s[j+1]) j++;
			next[i]=j;
		}
//		if(strlen(s+1)/(strlen(s+1)-next[strlen(s+1)])>1&&strlen(s+1)%(strlen(s+1)-next[strlen(s+1)]==0))
		printf("%d\n",strlen(s+1)/(strlen(s+1)-next[strlen(s+1)])-1);
//		else printf("%d\n",strlen(s+1));
	}
}
