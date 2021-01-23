#include<cstdio>
#include<string.h>
#include<algorithm>
#include<iostream>
#define maxium 150
using namespace std;
int n,treasure,minn=0x7fffffff;
int map[maxium][maxium],value[maxium];
void start()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    cin>>map[i][j];
    cin>>treasure;
    for(int i=1;i<=treasure;i++)
    cin>>value[i];
}
void floyd()
{
	for(int k=1;k<=n;k++)
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    map[i][j]=min(map[i][j],map[i][k]+map[k][j]);
}
void solve()
{
	floyd();
    sort(value+1,value+treasure+1);
    do
    {
        int sum=0;
        sum+=map[1][value[1]]+map[value[treasure]][n];//先加上第一个点到第一处宝藏以及最后一处宝藏到n的距离
        for(int i=1;i<treasure;i++)//枚举更新
        sum+=map[value[i]][value[i+1]];
        minn=min(minn,sum);//更新答案
    }while(next_permutation(value+1,value+treasure+1));
//    l sum=0;
//    sum+=map[1][value[1]]+map[value[treasure]][n];
//    for(int i=1;i<treasure;i++)
//    sum+=map[value[i]][value[i+1]];
//    minn=min(minn,sum);
//    while(next_permutation(value+1,value+treasure+1))
//    {
//    	sum=0;
//    	sum+=map[1][value[1]]+map[value[treasure]][n];
//        for(int i=1;i<treasure;i++)
//        sum+=map[value[i]][value[i+1]];
//        minn=min(minn,sum);
//	}
	cout<<minn;
}
int main()
{
	start();
	solve();
	return 0;
}
