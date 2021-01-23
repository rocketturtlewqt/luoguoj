#include<bits/stdc++.h>
using namespace std;
int day,week;
int main(){
	cin>>day>>week;
    int end=day+week-1,sum=0;
    for(int i=day;i<=end;i++) if(i%7!=6&&i%7!=0) sum+=250;
    cout<<sum<<endl;
    return 0;
}

