#include<bits/stdc++.h>
using namespace std;
#define rint register int
#define N 100001
int t,n,len[N];
int main(){
    for(rint i=1;i<10;i++)
        len[i]=len[i-1]+1;
    for(rint i=10;i<100;i++)
        len[i]=len[i-1]+2;
    for(rint i=100;i<1000;i++)
        len[i]=len[i-1]+3;
    for(rint i=1000;i<10000;i++)
        len[i]=len[i-1]+4;
    for(rint i=10000;i<100000;i++)
        len[i]=len[i-1]+5;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int s=0,k1=0,k2=0;
        while(++k1){
            s+=len[k1];
            if(s>=n)break;
        }
        n-=(s-len[k1]);     
//       printf("n=%lld\n",n);
        while(++k2)
            if(len[k2]>=n)break;
        printf("%d\n",(int)(k2/pow(10,len[k2]-n))%10);
    }
    return 0;
}
