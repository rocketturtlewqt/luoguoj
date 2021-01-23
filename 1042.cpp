#include<bits/stdc++.h>
using namespace std;
string s;
int a11[3],a21[3];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	string w;s="";
	while(cin>>w){
		string sub=w.substr(w.length()-1,1);
		if(sub=="E"){
			s+=w.substr(0,w.length()-1);
			break;
		}
		else s+=w;
	}
	cout<<s<<endl;
    for(int i=0;i<s.length();i++){
    	if(s[i]=='W') a11[1]++;
    	else a11[2]++;
    	if((i+1)%11==0&&i!=0){
    		printf("%d:%d\n",a11[1],a11[2]);
    		a11[1]=a11[2]=0;
		}else if(i==s.length()-1){
			printf("%d:%d\n\n",a11[1],a11[2]);
		}
	}
	for(int i=0;i<s.length();i++){
    	if(s[i]=='W') a21[1]++;
    	else a21[2]++;
    	if((i+1)%21==0&&i!=0){
    		printf("%d:%d\n",a21[1],a21[2]);
    		a21[1]=a21[2]=0;
		}else if(i==s.length()-1){
			printf("%d:%d\n\n",a21[1],a21[2]);
		}
	}
	return 0;
}
