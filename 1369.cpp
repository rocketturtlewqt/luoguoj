#include<bits/stdc++.h>
using namespace std;
int heng[200][200],shu[200][200],tmp[200],n;
int main(){
	cin>>n;int maxx=0;
	for(int i=1;i<=n;i++){
		int x,y;cin>>x>>y;
		heng[x][y]++;shu[x][y]++;
	}
	for(int i=1;i<=100;i++)
	for(int j=1;j<=100;j++)
	heng[i][j]+=heng[i][j-1],shu[i][j]+=shu[i-1][j];
	for(int l=1;l<=100;l++){
		for(int r=l;r<=100;r++){
			for(int i=1;i<=100;i++) tmp[i]=shu[r-1][i]-shu[l][i];
			int d=1;
			for(int k=1;k<=100;k++){
				int ans=tmp[d]+tmp[k]+heng[r][k]-heng[r][d-1]+heng[l][k]-heng[l][d-1];
				maxx=max(ans,maxx);
				if(tmp[k]>tmp[d]+heng[l][k-1]-heng[l][d-1]+heng[r][k-1]-heng[r][d-1]) d=k;
			}
		}
	}
	cout<<maxx<<endl;
	return 0;
}
