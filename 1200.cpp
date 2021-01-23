#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char star[20],pe[20];
int main(){
	cin>>(star+1)>>(pe+1);
	ll mod1,mod2,len1=strlen(star+1),len2=strlen(pe+1),sum1=1,sum2=1;
	for(int i=1;i<=len1;i++) sum1*=star[i]-'A'+1;
	for(int i=1;i<=len2;i++) sum2*=pe[i]-'A'+1;
	if(sum1%47==sum2%47) puts("GO");
	else puts("STAY");
	return 0;
}
