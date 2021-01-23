#include<cstdio>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
char a[10000],b[10000],c[10000],d[10000],e[10000];
int main(){
	cin>>(a+1)>>(b+1);
	int lena=strlen(a+1),lenb=strlen(b+1);
	for(int i=1;i<=lena;i++) c[i]=a[i]-'0';
	for(int i=1;i<=lenb;i++) d[i]=b[i]-'0';
	int flag=0,pos,ans=0;
	for(int i=lena,j=lenb;;i--,j--){
		if(i==0&&j==0){flag=0;break;}
		else if(j==0){flag=1;pos=i;break;}
		else if(i==0){flag=2;pos=j;break;}
	    e[++ans]=c[i]+d[j];
	}
	if(flag==0){
		for(int i=1;i<=lena;i++){
			e[i+1]+=e[i]/10;
			e[i]%=10;
		}
	}
	else if(flag==1){
		for(int i=1;i<=ans;i++){
			e[i+1]+=e[i]/10;
			e[i]%=10;
		}
		for(int i=ans+1;pos>=1;i++,pos--){
			e[i]+=c[pos];
			e[i+1]+=e[i]/10;
			e[i]%=10;
		}
	}
	else if(flag==2){
		for(int i=1;i<=ans;i++){
			e[i+1]+=e[i]/10;
			e[i]%=10;
		}
		for(int i=ans+1;pos>=1;i++,pos--){
			e[i]+=d[pos];
			e[i+1]+=e[i]/10;
			e[i]%=10;
		}
	}
    for(int i=1000;i>=1;i--) 
	if(e[i]!=0){
		pos=i;
		break;
	}
	int cnt=0;
	for(int i=1;i<=1000;i++) if(e[i]!=0) cnt=1;
	if(cnt)
    for(int i=pos;i>=1;i--) printf("%d",e[i]);
    else cout<<0<<endl;
	return 0;
}
