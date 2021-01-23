#include<iostream>
#include<algorithm>
using namespace std;
long long n,num,now,sum,f[1001];
int main()
{
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        cin>>num;
        if(num>f[now])//如果这个数比以前的大说明不破坏数列严格递增的性质那么将这个数放在数列都后面
        f[++now]=num;
        else
        {
            *lower_bound(f+1,f+now+1,num)=num;//如果这个数比之前的数小那么用lower_bound()函数找到它适合的位置将这个数放进去
            sum++;//这样做相当于修改一个数，所以累加器加1
        }
    }
    cout<<sum;
    return 0;
}
//比人代码不精大神勿喷
