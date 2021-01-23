#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <queue>
using namespace std;

int n,num=1;
struct llo{
    int begin,end,xu,used;
} cow[50008];
priority_queue<pair <int,int> > q;
//用 priority_queue实现小根堆有两种方式：一是插入相反数，而是重载运算符，这里介绍前一种
//对于c++内置数据类型（如int，float），可以把要插入的数的相反数插入，在堆中取出后再取负得到原来的数，
//例如：要插入1,2,3，可以插入-1，-2，-3，那么从堆中会取出最大数-1，再取负就可得到1 

bool cmp1(llo x,llo y){
    return x.begin<y.begin;
}
bool cmp2(llo x,llo y){
    return x.xu<y.xu;
}
//每一头牛都必须从编号为未知的牛棚挤奶，那我们在挤奶前假设需要一个牛棚（最优），再不断往上加牛棚
// 1. 为神马以开始时间排序呢，因为每两头牛之间只存在互斥（不能在一个牛棚）和相容（可以在一个牛棚）两种关系 
//那么易得：当相容时，开始时间早的必须先开始；当互斥时，两牛棚互不影响，此时不如让开始时间早的先挤奶
// 2.因为题目具有全覆盖性，所以当存在两牛均可以在某个牛棚挤奶时（或开始时间相同）必须有一牛再开一个牛棚，而此时两牛挤奶的截止时间都会被保存下来，
//对以后的选择没有影响 

int main(){
    scanf("%d",&n);//输入 
    for(int i=1;i<=n;i++){
        scanf("%d%d",&cow[i].begin,&cow[i].end);
        cow[i].xu=i;//捆绑序号，开始，结束，和使用哪个牛棚
    }
    sort(cow+1,cow+n+1,cmp1);//按开始端点排序 
    q.push(make_pair(-cow[1].end,num));//小根堆存数对，num牛棚现在截止的时间 和牛棚号码 
    cow[1].used=1;//第一头牛使用一号牛栏 
    for(int i=2;i<=n;i++){//从第二个开始，看是否需要新建牛棚 
        int x=-q.top().first;//取最早的截止时间 
        int num_q=q.top().second;//取最早截止时间的牛棚号 
        if(cow[i].begin>x){//当前牛使用之前牛腾出来的 
            q.pop();//将现牛棚的截止时期和num再更新一遍 
            q.push(make_pair(-cow[i].end,num_q));
            cow[i].used=num_q;//当前牛入住此牛棚，记录 
        }
        else{//当前牛必须自己再搞一个 
            num++;//牛栏数加一个 
            cow[i].used=num;//当前牛入住此牛棚，记录
            q.push(make_pair(-cow[i].end,num));//将新牛棚和num存入 
        }
    }
    printf("%d\n",num);
    sort(cow+1,cow+n+1,cmp2);//按序号重新排一遍 ，因为最后是让按序号输出 
    //很显然答案有很多种，只要让该在一个牛棚挤奶的牛的输出号码一样就行，所以保证输出编号和输入编号一致是必要的 
    for(int i=1;i<=n;i++)
        printf("%d\n",cow[i].used);//取每个牛使用的牛棚编号 
    return 0;
}
