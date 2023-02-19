#include<cstdio>
#include<algorithm>
using namespace std;typedef long long ll;const ll mod=998244353;const int N=3*1e5+10;const int M=60;
int n;int m;int v[2*N];int x[2*N];int al[N];int ct;ll dep[N];int fa[N][22];int book[N];ll val[N][M];
inline void add(int u,int V){v[++ct]=V;x[ct]=al[u];al[u]=ct;}ll mi[M];
inline void dfs(int u)//处理val的信息以及倍增的信息 
{
    book[u]=true;for(int i=0;fa[u][i];i++){fa[u][i+1]=fa[fa[u][i]][i];}
    for(int i=al[u];i;i=x[i])
    {
        if(book[v[i]]){continue;}
        fa[v[i]][0]=u;dep[v[i]]=dep[u]+1;
        for(int j=1;j<=50;j++){mi[j]=mi[j-1]*dep[v[i]]%mod;}
        for(int j=1;j<=50;j++){val[v[i]][j]=(mi[j]+val[u][j])%mod;}
        dfs(v[i]);
    }
}
inline int lca(int u,int v)//倍增求lca 
{
    if(dep[u]<dep[v]){swap(u,v);}int d=dep[u]-dep[v];
    for(int i=0;d;d>>=1,i++){if(d&1){u=fa[u][i];}}if(u==v){return u;}
    for(int i=20;i>=0;i--){if(fa[u][i]!=fa[v][i]){u=fa[u][i];v=fa[v][i];}}
    return fa[u][0]; 
}
int main()
{
freopen("data.in", "r", stdin);
    scanf("%d",&n);mi[0]=1;
    for(int i=1,u,v;i<n;i++){scanf("%d%d",&u,&v);add(u,v);add(v,u);}dfs(1);//dfs处理 
    scanf("%d",&m);
    for(int i=1,u,v,k;i<=m;i++)
    {
        scanf("%d%d%d",&u,&v,&k);int l=lca(u,v);//然后我们就直接减了，注意lca只算但是要算一次 
        printf("%lld\n",(val[u][k]+val[v][k]+2*mod-val[fa[l][0]][k]-val[l][k])%mod);
    }return 0;//拜拜程序~ 
}
