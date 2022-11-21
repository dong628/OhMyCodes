#include<cstdio>
#include<cstring>
#include<cmath>
#include<climits>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<complex>
#include<iostream>
#include<map>
#include<queue>
#include<vector>
#define ll long long
#define INF 0x3f3f3f3f
#define ls(p) tree[p].lson
#define rs(p) tree[p].rson
#define tls(p) tree[ls(p)]
#define trs(p) tree[rs(p)]
#define t(p) tree[p]
#define tpi t(++tot)
#define tp t(tot)
using namespace std;
const int N(2e5);
int n;ll lastans;
struct node
{
	int rand,size,tag;
	ll val,sum;
	int lson,rson;
}tree[(N<<7)+10];
int rt[N+10];
inline int new_node(long long v=0)
{
	static int tot(0);
	tpi.val=v;tp.sum=v;
	tp.rand=rand();tp.size=1;
	return tot;
}
inline int copy_node(int p)
{
	int ret=new_node();
	tree[ret]=tree[p];
	return ret;
}
inline void push_up(int p)
{
	tree[p].size=tls(p).size+trs(p).size+1;
	tree[p].sum=tls(p).sum+trs(p).sum+t(p).val;
}
inline void push_down(int p)
{
	if(!t(p).tag)return;
	if(ls(p))ls(p)=copy_node(ls(p));
	if(rs(p))rs(p)=copy_node(rs(p));
	swap(ls(p),rs(p));
	if(ls(p))tls(p).tag^=1;
	if(rs(p))trs(p).tag^=1;
	tree[p].tag=0;
}
void split(int p,int k,int &x,int &y)
{
	if(!p){x=y=0;return;}
	push_down(p);
	if(tls(p).size<k){x=copy_node(p);split(rs(x),k-tls(p).size-1,rs(x),y);push_up(x);}
	else{y=copy_node(p);split(ls(y),k,x,ls(y));push_up(y);}
}
int merge(int x,int y)
{
	if(!x||!y)return x|y;
	push_down(x);push_down(y);
	if(t(x).rand<t(y).rand){rs(x)=merge(rs(x),y);push_up(x);return x;}
	else{ls(y)=merge(x,ls(y));push_up(y);return y;}
}
int main()
{
	freopen("data.in", "r", stdin);

	srand(224144);scanf("%d",&n);
	int cnt(0);int v,op;ll a,b;int x,y,z;
	while(n--)
	{
		scanf("%d%d",&v,&op);
		lastans = 0;
		if(op==1)
		{
			scanf("%lld%lld",&a,&b);
			a^=lastans;b^=lastans;
			split(rt[v],a,x,y);
			rt[++cnt]=merge(merge(x,new_node(b)),y);
		}
		if(op==2)
		{
			scanf("%lld",&a);
			a^=lastans;
			split(rt[v],a,x,z);
			split(x,a-1,x,y);
			rt[++cnt]=merge(x,z);
		}
		if(op==3)
		{
			scanf("%lld%lld",&a,&b);
			a^=lastans;b^=lastans;
			split(rt[v],b,x,z);
			split(x,a-1,x,y);
			t(y).tag^=1;
			rt[++cnt]=merge(merge(x,y),z);
		}
		if(op==4)
		{
			scanf("%lld%lld",&a,&b);
			a^=lastans;b^=lastans;
			split(rt[v],b,x,z);
			split(x,a-1,x,y);
			printf("%lld\n",lastans=t(y).sum);
			rt[++cnt]=merge(merge(x,y),z);
		}
	}
	return 0;
}
