#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<queue>
#define maxium 53
using namespace std;
int n,m,x1,y1,x2,y2;
char direction;
int map[maxium][maxium],book[maxium][maxium][5];
struct node
{
	int x;
	int y;
	char dir;
	int time;
};
queue<struct node> q;
void start()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	cin>>map[i][j];
	cin>>x1>>y1>>x2>>y2>>direction;
}
int judge_walk(struct node temp,int cnt)
{
	int sum=0;
	if(temp.dir=='S')
	{
		if(temp.x+cnt>n) return 1;
		if(book[temp.x+cnt][temp.y][1]==1) return 1;
		for(int i=1;i<=cnt+1;i++)
		{
		    sum+=map[temp.x+i][temp.y];
		    sum+=map[temp.x+i][temp.y-1];
		}
		if(sum!=0) return 1;
	}
	if(temp.dir=='N')
	{
		if(temp.x-cnt<0) return 1;
		if(book[temp.x-cnt][temp.y][2]==1) return 1;
		for(int i=1;i<=cnt;i++)
		{
		    sum+=map[temp.x-i][temp.y];
		    sum+=map[temp.x-i][temp.y-1];
		}
		if(sum!=0) return 1;
	}
	if(temp.dir=='W')
	{
		if(temp.y-cnt<1) return 1;
		if(book[temp.x][temp.y-cnt][3]==1) return 1;
		for(int i=1;i<=cnt+1;i++)
		{
		    sum+=map[temp.x][temp.y-i];
		    sum+=map[temp.x+1][temp.y-i];
		}
		if(sum!=0) return 1;
	}
	if(temp.dir=='E')
	{
		if(temp.y+cnt>m+1) return 1;
		if(book[temp.x][temp.y+cnt][4]==1) return 1;
		for(int i=1;i<=cnt;i++)
		{
		    sum+=map[temp.x][temp.y+i];
		    sum+=map[temp.x+1][temp.y+i];
		}
		if(sum!=0) return 1;
	}
	return 0;
}
void f(struct node temp,struct node son,int cnt)
{
	if(judge_walk(temp,cnt)) return;
	if(temp.dir=='S') 
	{
		son.x=temp.x+cnt;
		son.y=temp.y;
		book[son.x][son.y][1]=1;
		son.dir=temp.dir;
		son.time=temp.time+1;
		q.push(son);
	}
	if(temp.dir=='N')
	{
		son.x=temp.x-cnt;
		son.y=temp.y;
		book[son.x][son.y][2]=1;
		son.dir=temp.dir;
		son.time=temp.time+1;
		q.push(son);
	}
	if(temp.dir=='W')
	{
		son.x=temp.x;
		son.y=temp.y-cnt;
		book[son.x][son.y][3]=1;
		son.dir=temp.dir;
		son.time=temp.time+1;
		q.push(son);
	}
	if(temp.dir=='E')
	{
		son.x=temp.x;
		son.y=temp.y+cnt;
		book[son.x][son.y][4]=1;
		son.dir=temp.dir;
		son.time=temp.time+1;
		q.push(son);
	}
}
void change_dir_left(struct node temp,struct node son)
{
    if(temp.dir=='S') 
	{
		if(book[temp.x][temp.y][4]==1) return;
		son.x=temp.x;
		son.y=temp.y;
		son.dir='E';
		book[son.x][son.y][4]=1;
		son.time=temp.time+1;
		q.push(son);
	}
	if(temp.dir=='N')
	{
		if(book[temp.x][temp.y][3]==1) return;
		son.x=temp.x;
		son.y=temp.y;
		son.dir='W';
		book[son.x][son.y][3]=1;
		son.time=temp.time+1;
		q.push(son);
	}
	if(temp.dir=='W')
	{
		if(book[temp.x][temp.y][1]==1) return;
		son.x=temp.x;
		son.y=temp.y;
		son.dir='S';
		book[son.x][son.y][1]=1;
		son.time=temp.time+1;
		q.push(son);
	}
	if(temp.dir=='E')
	{
		if(book[temp.x][temp.y][2]==1) return;
		son.x=temp.x;
		son.y=temp.y;
		son.dir='N';
		book[son.x][son.y][2]=1;
		son.time=temp.time+1;
		q.push(son);
	}
}
void change_dir_right(struct node temp,struct node son)
{
    if(temp.dir=='S') 
	{
		if(book[temp.x][temp.y][3]==1) return;
		son.x=temp.x;
		son.y=temp.y;
		son.dir='W';
		book[son.x][son.y][3]=1;
		son.time=temp.time+1;
		q.push(son);
	}
	if(temp.dir=='N')
	{
		if(book[temp.x][temp.y][4]==1) return;
		son.x=temp.x;
		son.y=temp.y;
		son.dir='E';
		book[son.x][son.y][4]=1;
		son.time=temp.time+1;
		q.push(son);
	}
	if(temp.dir=='W')
	{
		if(book[temp.x][temp.y][2]==1) return;
		son.x=temp.x;
		son.y=temp.y;
		son.dir='N';
		book[son.x][son.y][2]=1;
		son.time=temp.time+1;
		q.push(son);
	}
	if(temp.dir=='E')
	{
		if(book[temp.x][temp.y][1]==1) return;
		son.x=temp.x;
		son.y=temp.y;
		son.dir='S';
		book[son.x][son.y][1]=1;
		son.time=temp.time+1;
		q.push(son);
	}
}
void solve()
{
	struct node a;
	a.x=x1;a.y=y1+1;a.dir=direction;a.time=0;
	if(a.dir=='S') book[a.x][a.y][1]=1;
	if(a.dir=='N') book[a.x][a.y][2]=1;
	if(a.dir=='W') book[a.x][a.y][3]=1;
	if(a.dir=='E') book[a.x][a.y][4]=1;
	q.push(a);
	while(!q.empty())
	{
		struct node temp=q.front();
		printf("%d %d %c %d\n",temp.x,temp.y,temp.dir,temp.time);
		if(temp.x==x2&&temp.y==y2+1)
		{
			cout<<temp.time;
		    return;
		}
		for(int i=1;i<=5;i++)
		{
			struct node son;
			if(i==1) f(temp,son,1);
			if(i==2) f(temp,son,2);
			if(i==3) f(temp,son,3);
		    if(i==4) change_dir_left(temp,son);
		    if(i==5) change_dir_right(temp,son);
		}
		q.pop();
	}
	cout<<-1;
}
int main()
{
	start();
	solve();
	return 0;
}
