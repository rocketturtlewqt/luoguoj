#include<bits/stdc++.h>
using namespace std;
int T,a0,a1,b0,b1;
int main(){
	scanf("%d",&T);
	while(T--){
		int sum=0;
		scanf("%d%d%d%d",&a0,&a1,&b0,&b1); 
		for(int i=1;i*i<=b1;i++){
			if(b1%i==0){
		        if(i%a1==0&&__gcd(b1/b0,b1/i)==1&&__gcd(i/a1,a0/a1)==1) sum++;
		        int other=b1/i;
		        if(i==other) continue;
		        if(other%a1==0&&__gcd(b1/b0,b1/other)==1&&__gcd(other/a1,a0/a1)==1) sum++;
		    }
		}
		printf("%d\n",sum);
	}
	return 0;
}
