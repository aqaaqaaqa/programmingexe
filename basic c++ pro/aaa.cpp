#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int k,q=1,s;//切记 q=1
int main()
{
    scanf("%d",&k);
    while(q<k)
        q*=2;// 2 的非负整数次幂的数值
    if(q==k)
        return !printf("%d 0",q);//第一种情况
    else printf("%d ",q);//第二种情况（注意不要打漏空格）
    while(k>0)
        q/=2,k%=q,s++;
    return !printf("%d",s);
}