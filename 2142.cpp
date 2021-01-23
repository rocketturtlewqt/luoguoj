#include <iostream>
#include <cmath>
#include <cstring> 
using namespace std;
char a[100010],b[100010];//设两个字符串
inline void jian(char a[],char b[]){ 
//    cin>>a>>b;//读入两个字符串 
    int c[100010],d[100010],h[100010],n1,n2,i,f=0,l=0;
    n1=strlen(a);//求字符串长度 
    n2=strlen(b);
    for(i=0;i<n1/2;i++) swap(a[i],a[n1-1-i]);
    for(i=0;i<n2/2;i++) swap(b[i],b[n2-1-i]);
    for(i=0;i<n1;i++) c[i]=a[i]-'0';//把字符串a的字符转化为数字存到数组c当中。其中“-‘0’”为转换方法 
    for(i=0;i<n2;i++) d[i]=b[i]-'0';
    if(n2>n1)//这一步是判断那个数长，哪个就大，就用哪个做被减数存到数组c中，哪个小就存到d中 
    {
        for(i=0;i<n2;i++) swap(c[i],d[i]);//把两数交换，swap为交换函数 
        f=1;//设一个旗帜，以后如果f=1就说明这数被减数比减数小，是负数。 
    }
    if(n1>n2) swap(n1,n2); //取长的做for循环条件 
    for(i=0;i<n2;i++) h[i]=c[i]-d[i];  
    for(i=0;i<n2;i++)//这部就是借位 
    {
         if(h[i]<0)
         { 
             h[i]=10+h[i];
             h[i+1]--; 
         } 
    }
    if(f==1) cout<<"-";//如果f等于一也就是结果为负数，打印“-” 
    for(i=n2-1;i>=0;i--)//这步很重要！ 这是在输出时把首位的0都去掉 
    {
         if(l==0)//设了一个l，如果l为0意味着还没有碰到非零数，也就是有0就要去掉的0 
         {
             if(h[i]!=0) //如果这数不为零 
             {
                 l=1;//l=1表明碰到了非零数了以后的0有实际意义要打印出来 
                 cout<<h[i];//打印此数 
                 continue;//然后跳出本次循环 
             } 
         }
         if(l!=0)//如果l不等于0，就说明这时的0有实际意义，要打印出来 
         {
             cout<<h[i];
         }
    }
}
int main(){
	cin>>a>>b;
	return 0;
}
