  #include <bits/stdc++.h> 
  #define LL long long 
  #define For(i,j,k) for(int i=j;i<=k;i++) 
  using namespace std ; 
  
  const int N = 10011 , M = 50011 ; 
  struct node{
     LL to,pre,val ; 
 }e[M*2];
 struct edge{
     LL x,y,val ; 
 }beg[M];
 LL n,m,b,cnt,point[N],head[N],mx,blood,dist[N] ;
 bool visit[N] ;  
 queue<LL> Q ; 
 
 inline void add(int x,int y,int val) 
 {
     e[++cnt].to = y ; 
     e[cnt].pre = head[x] ; 
     e[cnt].val = val ; 
     head[x] = cnt; 
 }
 
 inline bool check( int mid ) 
 {
     LL u,v ; 
     For(i,0,n) head[i] = 0,dist[i] = (1LL<<62) ; 
     cnt = 0 ; 
     For(i,1,m) {
         if( point[beg[ i ].x] > mid ) continue ; 
         if( point[beg[ i ].y] > mid ) continue ; 
         add( beg[ i ].x,beg[ i ].y,beg[ i ].val ) ; 
         add( beg[ i ].y,beg[ i ].x,beg[ i ].val ) ; 
     }
     while(!Q.empty()) Q.pop() ; 
     Q.push(1) ; dist[ 1 ] = 0 ; visit[ 1 ] = 1 ;  
     while(!Q.empty()) {
         u = Q.front() ;
         Q.pop() ;  
         visit[u] = 0 ;          
		 for(int i=head[u];i;i=e[i].pre) {
             v = e[ i ].to ; 
            if( dist[ u ] +  e[ i ].val < dist[ v ] ) {
                 dist[ v ] = dist[ u ] + e[ i ].val ;   
                 if( !visit[ v ] ) {
                     visit[ v ] = 1 ; 
                     Q.push(v) ; 
                 }
             }
         }
     }
     if( dist[n]>=blood || dist[n]==dist[0] ) return 0 ;   // 血量不够 或者 不能到达  
     return 1 ;  
 }
 
 inline void erfen() 
 {
     LL l = 0 , r = mx+1,mid ; 
     while( l < r ) {
         mid = ( l+r )/2 ; 
         if( check( mid ) ) 
             r = mid ; 
         else 
             l = mid+1 ;  
     } 
     if(r==mx+1) {
         printf("AFK\n") ;
         exit(0) ;  
     }
     printf("%d\n",r) ; 
 }
 
 int main() 
 {
     scanf("%lld%lld%lld",&n,&m,&blood);
     For(i,1,n) scanf("%lld",&point[ i ]),mx = max(mx,point[ i ]) ;  
     For(i,1,m) {
         scanf("%lld%lld%lld",&beg[ i ].x,&beg[ i ].y,&beg[ i ].val); 
     }
     erfen() ; 
     return 0 ; 
 }
