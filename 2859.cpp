#include<bits/stdc++.h>
using namespace std;
struct Cow{
	int start,end,num,pos;
}cow[1000000];
bool com1(struct Cow a,struct Cow b){
	return a.start<b.start;
}
bool com2(struct Cow a,struct Cow b){
	return a.num<b.num;
}
int n;
priority_queue<pair<int,int> >q;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>cow[i].start>>cow[i].end;
		cow[i].num=i;
	}
	sort(cow+1,cow+n+1,com1);
	int num=0;
	q.push(make_pair(-cow[1].end,++num));
	cow[1].pos=1;
	for(int i=2;i<=n;i++){
		int end=-q.top().first;
		int num_now=q.top().second;
		if(cow[i].start>end){
			q.pop();
			q.push(make_pair(-cow[i].end,num_now));
			cow[i].pos=num_now;
		}
		else{
			num++;
			cow[i].pos=num;
			q.push(make_pair(-cow[i].end,num));
		}
	}
	sort(cow+1,cow+n+1,com2);
	cout<<num<<endl;
	for(int i=1;i<=n;i++) cout<<cow[i].pos<<endl;
	return 0;
}
