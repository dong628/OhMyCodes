#include<bits/stdc++.h>
#define int long long
#include<vector>
using namespace std;
const int N=5e5+1,blocks=710;
int n,m,lastans,len; 
int a[N],b[N],st[blocks],ed[blocks],bel[N];
int p[N],f[blocks][blocks],sum[N];
vector<int> pos[N];
inline int read(){
	int s=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') s=(s<<1)+(s<<3)+ch-'0',ch=getchar();
	return s;
}
inline void init(){
	len=ceil((double)n/blocks);
	for(register int i=1;i<=len;i++) st[i]=ed[i-1]+1,ed[i]=i*blocks;
	ed[len]=n;
	for(int i=1;i<=len;i++) for(int j=st[i];j<=ed[i];j++) bel[j]=i;
	for(int i=1;i<=len;i++){
		for(int j=i;j<=len;j++){
			f[i][j]=f[i][j-1];
			for(int k=st[j];k<=ed[j];k++) f[i][j]=max(f[i][j],++sum[a[k]]);
		}
		for(int j=st[i];j<=n;j++) if(sum[a[j]]) sum[a[j]]=0;
	}
}
inline int ask(int l,int r){
	int qa=bel[l],qb=bel[r];
	if(qa==qb){
		int maxn=0;
		for(int i=l;i<=r;i++) maxn=max(maxn,++sum[a[i]]);
		for(int i=l;i<=r;i++) if(sum[a[i]]) sum[a[i]]=0;
		return maxn;
	}
	int maxn=f[qa+1][qb-1];
	for(int i=l;i<=ed[qa];i++) while(maxn+p[i]<pos[a[i]].size()&&pos[a[i]][maxn+p[i]]<=r) maxn++;
	for(int i=st[qb];i<=r;i++) while(p[i]-maxn>=0&&pos[a[i]][p[i]-maxn]>=l) maxn++;
	return maxn; 
}
signed main(){
	freopen("data.in", "r", stdin);
	freopen("std.out", "w", stdout);

//	n=read(),m=read();
	scanf("%lld %lld", &n, &m);
	for(int i=1;i<=n;i++) scanf("%lld", &a[i]),b[i]=a[i];
	sort(b+1,b+n+1);
	int num=unique(b+1,b+n+1)-b-1;
	for(int i=1;i<=n;i++) a[i]=lower_bound(b+1,b+num+1,a[i])-b,pos[a[i]].push_back(i),p[i]=pos[a[i]].size()-1;
	init();
	while(m--){
		int l,r;
		scanf("%lld %lld", &l, &r);
		
//		l^=lastans,r^=lastans;
		if(l>r) swap(l,r);
		lastans=ask(l,r);
		printf("%lld\n",lastans);
	}
}

