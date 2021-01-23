#include<bits/stdc++.h>
using namespace std;
#define maxium 10000
char s[maxium],len;
inline void start(){
	cin>>s;
	len=strlen(s);
}
#define fp(i,w,n) for(int i=w;i<=n;i++)
inline void solve(){
	int num=0,ans=0;
	fp(i,0,len-3){
		if(s[i]>'9'||s[i]<'0') continue;
		int a=s[i]-'0';
		num+=a*(++ans);
	}
	if(num%11==10){
		if(s[len-1]=='X') printf("Right\n"); 
		else{
			fp(i,0,len-2) printf("%c",s[i]);
			printf("X\n");
		}
	}
	else{
		int b=s[len-1]-'0';
		if(b==num%11) printf("Right\n");
		else{
			fp(i,0,len-2) printf("%c",s[i]);
			printf("%d\n",num%11);
		}
	}
}
int main(){
	start();
	solve();
	return 0;
}
