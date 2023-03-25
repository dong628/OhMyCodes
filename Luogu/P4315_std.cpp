#include<iostream>
#include<cstdio>
#define lson id<<1,l,m
#define rson id<<1|1,m+1,r
using namespace std;
const int N = 1e5+5;
struct node{
	int v;
	int next;
}e[N<<1];
int pos[N],tid[N],top[N],dep[N],son[N],siz[N],f[N],head[N];
int d[N][5],sum[N<<2],col[N<<2],lzy[N<<2],n,m,k,ofo;
void add(int u,int v)//加边函数，记得加双向
{
	e[++k].v=v;
	e[k].next=head[u];
	head[u]=k;
}
void dfs1(int u,int fa)//两个dfs初始化
{
	f[u]=fa;
	siz[u]=1;
	son[u]=0;
	dep[u]=dep[fa]+1;
	for(int i=head[u];i;i=e[i].next)
	{
		int v=e[i].v;
		if(v==fa)
		continue;
		dfs1(v,u);
		siz[u]+=siz[v];
		if(siz[v]>siz[son[u]])
		son[u]=v;
	}
}
void dfs2(int u,int tp)
{
	top[u]=tp;
	tid[u]=++ofo;
	pos[ofo]=u;
	if(son[u])
	dfs2(son[u],tp);
	for(int i=head[u];i;i=e[i].next)
	{
		int v=e[i].v;
		if(v==f[u]||v==son[u])
		continue;
		dfs2(v,v);
	}
}
void pushup(int id)
{
	sum[id]=max(sum[id<<1],sum[id<<1|1]);
}
void pushdown(int id)//因为这个WA了不下三遍
{
	if(lzy[id]!=-1)//先覆再加！先覆再加！先覆再加！重要的事情说三遍
	{
		col[id<<1]=col[id<<1|1]=0;
		sum[id<<1]=sum[id<<1|1]=lzy[id];
		lzy[id<<1]=lzy[id<<1|1]=lzy[id];
		lzy[id]=-1;
	}
	if(col[id])
	{
		col[id<<1]+=col[id];
		col[id<<1|1]+=col[id];
		sum[id<<1]+=col[id];
		sum[id<<1|1]+=col[id];
		col[id]=0;
	}
}
void build(int id,int l,int r)
{
	lzy[id]=-1;
	if(l==r)
	return;
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	pushup(id);
}
void update1(int id,int l,int r,int x,int y,int z)//区间加数
{
	if(x<=l&&r<=y)
	{
		sum[id]+=z;
		col[id]+=z;
		return;
	}
	int m=(l+r)>>1;
	pushdown(id);
	if(x<=m)
	update1(lson,x,y,z);
	if(y>m)
	update1(rson,x,y,z);
	pushup(id);
}
void update2(int id,int l,int r,int x,int y,int z)//区间覆盖
{
	if(x<=l&&r<=y)
	{
		sum[id]=z;
		lzy[id]=z;
		col[id]=0;
		return;
	}
	int m=(l+r)>>1;
	pushdown(id);
	if(x<=m)
	update2(lson,x,y,z);
	if(y>m)
	update2(rson,x,y,z);
	pushup(id);
}
int query(int id,int l,int r,int x,int y)//区间查询
{
	if(x<=l&&r<=y)
	return sum[id];
	int m=(l+r)>>1,ans=-1e9;
	pushdown(id);
	if(x<=m)
	ans=max(ans,query(lson,x,y));
	if(y>m)
	ans=max(ans,query(rson,x,y));
	return ans;
}
void Tupdate(int a,int b,int c,int flag)//树剖区间修改
{
	while(top[a]!=top[b])
	{
		if(dep[top[a]]<dep[top[b]])
		swap(a,b);
		if(flag==1)
		update1(1,1,n,tid[top[a]],tid[a],c);
		else
		update2(1,1,n,tid[top[a]],tid[a],c);
		a=f[top[a]];
	}
	if(a==b)
	return;
	if(dep[a]>dep[b])
	swap(a,b);
	if(flag==1)
	update1(1,1,n,tid[son[a]],tid[b],c);
	else
	update2(1,1,n,tid[son[a]],tid[b],c);
}
int Tquery(int a,int b)//树剖区间查询
{
	int ans=-1e9;
	while(top[a]!=top[b])
	{
		if(dep[top[a]]<dep[top[b]])
		swap(a,b);
		ans=max(ans,query(1,1,n,tid[top[a]],tid[a]));
		a=f[top[a]];
	}
	if(a==b)
	return ans;
	if(dep[a]>dep[b])
	swap(a,b);
	ans=max(ans,query(1,1,n,tid[son[a]],tid[b]));
	return ans;
}
int main()//注：在这里我用了数组来存边，就不用乘以二了
{
	freopen("data.in", "r", stdin);

	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d%d",&d[i][0],&d[i][1],&d[i][2]);
		add(d[i][0],d[i][1]);
		add(d[i][1],d[i][0]);
	}
	dfs1(1,1);
	dfs2(1,1);
	build(1,1,n);
	for(int i=1;i<n;i++)
	{
		if(dep[d[i][0]]>dep[d[i][1]])
        swap(d[i][0],d[i][1]);
		update1(1,1,n,tid[d[i][1]],tid[d[i][1]],d[i][2]);
	}
	char s[15]={'f'};
	while(s[0]!='S')
	{
		int a,b,c;
		scanf("%s",s);
		if(s[0]=='A')
		{
			scanf("%d%d%d",&a,&b,&c);
			Tupdate(a,b,c,1);
		}
		if(s[0]=='C')
		{
			if(s[1]=='o')
			{
				scanf("%d%d%d",&a,&b,&c);
				Tupdate(a,b,c,2);
			}
			if(s[1]=='h')
			{
				scanf("%d%d",&a,&b);
				update2(1,1,n,tid[d[a][1]],tid[d[a][1]],b);
			}
		}
		if(s[0]=='M')
		{
			scanf("%d%d",&a,&b);
			printf("%d\n",Tquery(a,b));
		}
	}
	return 0;
}
