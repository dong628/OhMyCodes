#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define N 10001
#define re register 
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int n,m,query[101];
int e_cnt=0,head[N],maxp[N],siz[N],root,tot=0,d[N],b[N],a[N];
bool vis[N],ok[101];
struct Edge{
	int to,nxt,val;
}edge[N<<1];
void add(int a,int b,int c){
	e_cnt++;
	edge[e_cnt].nxt=head[a];
	edge[e_cnt].to=b;
	edge[e_cnt].val=c;
	head[a]=e_cnt;
}
void get_root(int u,int fa,int total){
	siz[u]=1;
	maxp[u]=0;
	for(re int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(v==fa||vis[v])continue;
		get_root(v,u,total);
		siz[u]+=siz[v];
		maxp[u]=max(siz[v],maxp[u]);
	}
	maxp[u]=max(maxp[u],total-siz[u]);
	if(!root||maxp[u]<maxp[root]){
		root=u;
	}
}
bool cmp(int x,int y){
	return d[x]<d[y];
}
void get_dis(int u,int fa,int dis,int from){
	a[++tot]=u;
	d[u]=dis;
	b[u]=from;
	for(re int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(v==fa||vis[v])continue;
		get_dis(v,u,dis+edge[i].val,from);
	}
}
void calc(int u){
	tot=0;
	a[++tot]=u;
	d[u]=0;
	b[u]=u;
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(vis[v])continue;
		get_dis(v,u,edge[i].val,v);
	}
	sort(a+1,a+tot+1,cmp);
	for(int i=1;i<=m;i++){
		int l=1,r=tot;
		if(ok[i])continue;
		while(l<r){
			if(d[a[l]]+d[a[r]]>query[i]){
				r--;
			}
			else if(d[a[l]]+d[a[r]]<query[i]){
				l++;
			}
			else if(b[a[l]]==b[a[r]]){
				if(d[a[r]]==d[a[r-1]])r--;
				else l++;
			}
			else{
				ok[i]=true;
				break;
			}
		}
	}
}
void solve(int u){
	vis[u]=true;
	calc(u);
	for(re int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(vis[v])continue;
		root=0;
		get_root(v,0,siz[v]);
		solve(root);
	}
}
int main(){
	freopen("data.in", "r", stdin);

	n=read(),m=read();
	for(re int i=1;i<=n-1;i++){
		int u,v,w;
		u=read(),v=read(),w=read();
		add(u,v,w);
		add(v,u,w);
	}
	for(re int i=1;i<=m;i++){
		query[i]=read();
		if(!query[i])ok[i]=1;//这里,加个特判
	}
	maxp[0]=n;
	get_root(1,0,n);
	solve(root);
	for(re int i=1;i<=m;i++){
		if(ok[i]){
			cout<<"AYE"<<endl;
		}
		else{
			cout<<"NAY"<<endl;
		}
	}
	return 0;
}


