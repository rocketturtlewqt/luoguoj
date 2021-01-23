#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#define maxium 51
using namespace std;
int n,k;
int maxx[maxium][maxium],minx[maxium][maxium],mayy[maxium][maxium],miny[maxium][maxium];
struct Node
{
	int x;
	int y;
}node[maxium];
bool comparex(struct Node& a,struct Node& b)
{
	return a.x<=b.x;
}
bool comparey(struct Node& a,struct Node& b)
{
	return a.y<=b.y;
}
void start()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	cin>>node[i].y>>node[i].x;
	for(int i=1;i<=n-1;i++)
	for(int j=i+1;j<=n;j++)
	{
		printf("sort:%d-%d,%d\n",i,j,j+1);
	    sort(node+i,node+j+1,comparex);
	    maxx[i][j]=node[j].x;
	    minx[i][j]=node[i].x;
	    sort(node+i,node+j+1,comparey);
	    mayy[i][j]=node[j].y;
	    miny[i][j]=node[i].y;
	}
	for(int i=1;i<=n-1;i++)
	for(int j=i+1;j<=n;j++)
	printf("[%d,%d]:minx=%d [%d,%d]:maxx=%d  [%d,%d]:miny=%d [%d,%d]:maxy=%d\n",i,j,minx[i][j],i,j,maxx[i][j],i,j,miny[i][j],i,j,mayy[i][j]);
}
int main()
{
	start();
	return 0;
}
