#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 505;

int a[maxn];
int n, k;
int ans;

int check(int x) {   //贪心判断
    int sum = 0;
    int t = 1;
    for(int i = n; i >= 1; i--) {
        if(sum + a[i] <= x)    //反着找！！！
            sum += a[i];       //不然#5会MLE
        else {
            t++;
            sum = a[i];
        }
    }
    return t <= k;
}

void print(int l, int r) {  //左右界输出
    int sum = 0;
    for(int i = r; i >= l; i--) {
        if(sum + a[i] > ans) {
            print(l, i);  //先输出最早的
            cout << i+1 << ' ' << r << endl;
            return;
        }
        sum += a[i];
    }
    cout << 1 << ' ' << r << endl; //注意边界，我错了3次（qwq）
}

int main() {
    cin >> n >> k;
    if(n == 0) return 0;  //到底是加呢，还是不加呢？加吧
    int l = 0x7fffff, r = 0;  //左右边界
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        l = min(l, a[i]);
        r += a[i];
    }
//    printf("%d %d\n",l,r);
    //二分模板，不说。
    while(l <= r) {
        int mid = (l+r) / 2;
//        printf("%d\n",mid);
        if(check(mid)) {
            ans = mid;
            r = mid-1;
        }
        else l = mid+1;
    }

    //cout << ans << endl;

    print(1, n);  //根据ans输出，这里我写的是递归，你硬要循环也行
    return 0;
}
