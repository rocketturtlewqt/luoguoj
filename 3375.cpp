#include<string.h>
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
char s1[1000100],s2[1000100];
inline void start(){
	scanf("%s%s",s1+1,s2+1); 
} 
int next[1000100],f[1000100];
inline void solve(){
	int len1=strlen(s1+1),len2=strlen(s2+1);
	next[1]=0;
	for(int i=2,j=0;i<=len2;i++){
		while(j>0&&s2[i]!=s2[j+1]) j=next[j];
		if(s2[i]==s2[j+1]) j++;
 		next[i]=j;
	}
	for(int i=1,j=0;i<=len1;i++){
		while(j>0&&(j==len2||s1[i]!=s2[j+1])) j=next[j];
		if(s1[i]==s2[j+1]) j++;
		f[i]=j;
		if(f[i]==len2) printf("%d\n",i-len2+1),j=next[i];
	}
	for(int i=1;i<len2;i++) printf("%d ",next[i]);
	printf("%d",next[len2]);
}
int main(){
	start();
	solve();
	return 0;
}
