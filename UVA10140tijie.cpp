#include<stdio.h>
#include<string.h>
#define INF 1000000000
#define LL long long
int judge[100005],prime[100005],isprime[10000005];
int a[1000005],num;
int minx,miny,maxx,maxy;
void findprime(){
    judge[0]=1;
    judge[1]=1;
    num=0;
    for(int i=2;i<=47000;i++){
        if(judge[i]==0){
            prime[num++]=i;
            for(int j=i+i;j<47000;j+=i)
                judge[j]=1;
        }
    }
    return;
}
int charge;
int main(){
    memset(judge,0,sizeof(judge));
    memset(prime,0,sizeof(prime));
    int u,l;
    findprime();
    while(scanf("%d%d",&u,&l)!=EOF){
        if(u<=1) u=2;
        memset(isprime,0,sizeof(isprime));
        for(int i=0;i<num&&(LL)(prime[i]*prime[i])<=l;i++){
            int s=u/prime[i];
            if(s<=1) s=2;
            for(int j=s;(LL)j*prime[i]<=l;j++){
                if((LL)j*prime[i]>=u)
                isprime[j*prime[i]-u]=1;
            }
        }
        charge=0;
        for(long long i=u;i<=l;i++){
            if(isprime[i-u]==0)
                a[charge++]=i;
        }
        if(charge<2){
            printf("There are no adjacent primes.\n");
            continue;
        }
        else if(charge>=2){
                miny=INF;
                maxy=0;
                minx=0;
                maxx=0;
            for(int i=1;i<charge;i++){
               if((a[i]-a[i-1])>(maxy-maxx)){
                    maxx=a[i-1];
                    maxy=a[i];
               }
               if((a[i]-a[i-1])<(miny-minx)){
                    minx=a[i-1];
                    miny=a[i];
               }
            }
            printf("%d,%d are closest, %d,%d are most distant.\n",minx,miny,maxx,maxy);
        }
    }
    return 0;
}
