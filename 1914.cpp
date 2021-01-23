#include<cstdio>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1e6;
int n;
char s[MAXN];
int main(){
	cin>>n;
	cin>>(s+1);int len=strlen(s+1);
	for(int i=1;i<=len;i++) s[i]='a'+(s[i]+n-'a')%26;
	printf("%s",s+1);
	return 0;
}
