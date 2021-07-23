#include<bits/stdc++.h>
#define LL long long
using namespace std;

LL a,inf=1e18;

int main()
{
    cin>>a;
    LL b;
    b=(inf%a*9%a*9%a+1%a)%a;//拆成9*9是害怕爆炸
    LL l=a-b+1,r=1e18+a-b;
    //cout<<b<<endl;
    cout<<l<<" "<<r;
    return 0;
} 
