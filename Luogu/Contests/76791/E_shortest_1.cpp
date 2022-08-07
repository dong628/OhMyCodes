#include <bits/stdc++.h>
#define q make_pair
#define b min
#define m max
#define s o.end()
#define f o.find(t)
using namespace std;typedef pair<int,int> pii;typedef unsigned long long l;int n,x,y;l z,a,pre;map<pii,l> o;int main(){pii t;scanf("%d",&n);for(int i=0;i<n;i++){cin>>x>>y>>z;t=q(x,y);if(f!=s){pre=o[t];o[t]+=z;}else{pre=0;o.insert(q(t,z));}a+=4*z;t=q(x+1,y);if(f!=s&&o[t]>pre)a-=2*b(m(l(0),o[t]-pre),z);t=q(x-1,y);if(f!=s&&o[t]>pre)a-=2*b(m(l(0),o[t]-pre),z);t=q(x,y+1);if(f!=s&&o[t]>pre)a-=2*b(m(l(0),o[t]-pre),z);t=q(x,y-1);if(f!=s&&o[t]>pre)a-=2*b(m(l(0),o[t]-pre),z);printf("%llu\n",a);}return 0;}
