#include <bits/stdc++.h>
using namespace std;

#define ll long long
inline ll read(){
	ll x=0,sign=0; char s=getchar();
	while(s>'9'||s<'0')sign|=s=='-',s=getchar();
	while(s<='9'&&s>='0')x=(x<<1)+(x<<3)+s-'0',s=getchar();
	return sign?-x:x;
}

const int N=1e5+5;
const int mod=998244353;

int n,m,c,a[N],deg[N],func[N];
int tp[N],pos[N],val[N];
ll mu=1,mul[N],dp[N],add[N];
vector <int> e[N];
queue <int> q;

bool vis[N];
void dfs(int id){
	vis[id]=1,mul[id]=(tp[id]==2?val[id]:1);
	for(int it:e[id]){
		if(!vis[it])dfs(it);
		mul[id]=mul[id]*mul[it]%mod;
	}
}

int main(){
	freopen("data.in", "r", stdin);

	n=read(); for(int i=1;i<=n;i++)a[i]=read();
	m=read();
	for(int i=1;i<=m;i++){
		tp[i]=read();
		if(tp[i]==1)pos[i]=read(),val[i]=read();
		else if(tp[i]==2)val[i]=read();
		else{
			c=read();
			while(c--){
				int to=read();
				e[i].push_back(to),deg[to]++;
			}
		}
	} c=read();
	for(int i=1;i<=m;i++)if(!vis[i]&&!deg[i])dfs(i);
	for(int i=1;i<=c;i++)func[i]=read();
	for(int i=c,f=func[i];i;i--,f=func[i]){
		if(tp[f]==1)dp[f]=(dp[f]+mu);
		else if(tp[f]==2)mu=mu*val[f]%mod;
		else dp[f]=(dp[f]+mu),mu=mu*mul[f]%mod;
	} for(int i=1;i<=m;i++)if(!deg[i])q.push(i);
	while(!q.empty()){
		int t=q.front(); q.pop();
		if(tp[t]==1)add[pos[t]]=(add[pos[t]]+dp[t]*val[t])%mod;
		ll z=dp[t]; reverse(e[t].begin(),e[t].end());
		for(int p:e[t]){
			deg[p]--; if(!deg[p])q.push(p);
			dp[p]=(dp[p]+z)%mod,z=z*mul[p]%mod;
		}
	} for(int i=1;i<=n;i++)cout<<(a[i]*mu+add[i])%mod<<" ";
	return 0;
}
