#include <cstdio>
#include <cctype>
const int MOD = 19260817;//MOD是题解中的"p"
inline int getint()
{
    int res = 0, ch = getchar();
    while(!isdigit(ch) and ch != EOF)
        ch = getchar();
    while(isdigit(ch))
    {
        res = (res << 3) + (res << 1) + (ch - '0');
        res %= MOD;//直接对MOD取余
        ch = getchar();
    }
    return res;
}

int x, y;
void exgcd(int a, int b)
{
    if(b == 0)
    {
        x = 1;
        y = 0;
        return;
    }
    exgcd(b, a % b);
    int Last_x = x;
    x = y;
    y = Last_x - a / b * y;
}

int main()
{
    int a, b;
    a = getint();
    b = getint();

    if(b == 0)
    {
        puts("Angry!");
        return 0;
    }
    exgcd(b, MOD);
    x = (x % MOD + MOD) % MOD;
    printf("%lld\n", a * (long long)(x) % MOD);//小心相乘后爆int
    return 0;
}
