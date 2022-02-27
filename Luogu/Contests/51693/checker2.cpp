#include<vector>
#include "testlib.h"
#define AC quitf(_ok,"AC!")
#define WA0(n1,n2) quitf(_wa,"WA! correct n=%d but your n=%d",n1,n2)
#define WA1 quitf(_wa,"WA, it's not a tree!")
#define WA2 quitf(_wa,"WA, diameter not unique!")
#define WA3 quitf(_wa,"WA, center of gravity not unique!")
#define WA4 quitf(_wa,"WA, center of gravity of diameter not unique!")
#define WA5 quitf(_wa,"WA, center of gravity of diameter equal to center of gravity!")
#define WA quitf(_wa,"WA!")
#define in1 inf.readInt()
#define in2 ouf.readInt()
#define in3 ans.readInt()
const int N=(int)3e6+5;
struct Node{
	int next,to;
}s[N<<1];int head[N],sLen;
int n,fa[N],dep[N];
inline void dfs(int,int,int);
inline void AddEdge(int,int);
inline void Relax(int&,int);
inline bool check(int);
int sz[N];
std::vector<int>G[2][N];
std::vector<int>Z;
inline void dfs2(int,int,int);
inline int mx(int,int);
int fat[N];
inline int find(int);
inline void merge(int,int);
int main(int argc,char**argv){
	registerTestlibCmd(argc,argv);
	n=in3;
	register int m=in2;
	if(m!=n)WA0(n,m);
	if(n==-1){AC;}
	for(register int i=1;i<=n;++i)
		fat[i]=i;
	for(register int i=1;i<n;++i)
		AddEdge(in2,in2);
	for(register int i=1;i<=n;++i)
		if(find(i)!=1)
			WA1;
	dfs(1,1,1);
	register int root1=0;
	for(register int i=1;i<=n;++i)
		Relax(root1,i);
	dfs(root1,root1,1);
	register int root2=0;
	for(register int i=1;i<=n;++i)
		Relax(root2,i);
	if(!check(root1)||!check(root2))
		WA2;
	dfs(root1,root1,1);
	register int num=1;
	while(root2!=root1){
		++num;
		register int u=root2,v=fa[root2];
		G[1][u].push_back(v),G[1][v].push_back(u);
		root2=fa[root2];
	}
	Z.clear();
	dfs2(0,1,1);
	if(Z.size()>1)
		WA3;
	register int _G=Z[0];
	Z.clear();
	n=num;
	dfs2(1,root1,root1);
	if(Z.size()>1)
		WA4;
	if(_G==Z[0])
		WA5;
	AC;
}
inline void dfs2(int id,int u,int fa){
	sz[u]=1;
	register int max=0;
	for(register std::vector<int>::iterator it=G[id][u].begin();
	it!=G[id][u].end();++it){
		register int v=*it;
		if(v==fa)continue;
		dfs2(id,v,u);
		sz[u]+=sz[v];
		max=mx(max,sz[v]);
	}
	max=mx(max,n-sz[u]);
	if(max<=n/2)
		Z.push_back(u);
}
inline int mx(int x,int y){
	return x>y?x:y;
}
inline bool check(int root){
	dfs(root,root,1);
	register int maxdep=0,cnt=0;
	for(register int i=1;i<=n;++i)
		if(dep[i]>maxdep)
			maxdep=dep[i],cnt=1;
		else if(dep[i]==maxdep)
			cnt=2;
	return cnt==1;
}
inline void Relax(int&root,int u){
	if(dep[u]>dep[root])
		root=u;
}
inline void dfs(int u,int father,int depth){
	fa[u]=father,dep[u]=depth;
	for(register int i=head[u];i;i=s[i].next){
		register int v=s[i].to;
		if(v==father)continue;
		dfs(v,u,depth+1);
	}
}
inline void AddEdge(int u,int v){
	merge(u,v);
	G[0][u].push_back(v),
	G[0][v].push_back(u);
	s[++sLen].next=head[u];
	s[sLen].to=v;head[u]=sLen;
	s[++sLen].next=head[v];
	s[sLen].to=u;head[v]=sLen;
}
inline int find(int x){
	return x==fat[x]?x:fat[x]=find(fat[x]);
}
inline void merge(int u,int v){
	u=find(u),v=find(v);
	if(u<v)fat[v]=u;
	else fat[u]=v;
}
