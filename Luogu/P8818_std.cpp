#include<cstdio>
#include<algorithm>
#include<iostream>
#define re register
#define il inline
using namespace std;
namespace io{
	template<class T>il void read(T &x){
		x=0;int f=0;char ch=getchar();
		while(!isdigit(ch))f|=ch=='-',ch=getchar();
		while(isdigit(ch))x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
		x=f?-x:x;
	}
}
typedef long long LL;
const int N=1e5+5;
const LL inf=1e18;
int n,m,q,a[N],a1[N],a2[N],b[N],lg[N];
il void init(){
	io::read(n),io::read(m),io::read(q);
	for(re int i=1;i<=n;++i){
		io::read(a[i]);
		if(a[i]>0)a1[i]=a[i],a2[i]=2e9;
		else a1[i]=2e9,a2[i]=a[i];
	}
	for(re int i=1;i<=m;++i)io::read(b[i]);
	for(re int i=2;i<=max(n,m);++i)lg[i]=lg[i>>1]+1;
}
struct stbiao{
	int tot,st[2][20][N];
	il void build(int n,int *a){
		tot=n;
		for(re int i=1;i<=n;++i){
			if(a[i]==2e9)st[0][0][i]=2e9,st[1][0][i]=-2e9;
			else st[0][0][i]=st[1][0][i]=a[i];
		}
		for(re int i=1;i<=lg[n];++i)
			for(re int j=1;j+(1<<i)-1<=n;++j){
				st[0][i][j]=min(st[0][i-1][j],st[0][i-1][j+(1<<(i-1))]);
				st[1][i][j]=max(st[1][i-1][j],st[1][i-1][j+(1<<(i-1))]);
			}
	}
	il int query(int tp,int l,int r){int v=lg[r-l];
		if(!tp)return min(st[0][v][l],st[0][v][r-(1<<v)+1]);
		else return max(st[1][v][l],st[1][v][r-(1<<v)+1]);
	}
}A1,A2,B;
il void solve(){
//	for(re int i=1;i<=n;++i)cout<<a1[i]<<" ";cout<<endl;
//	for(re int i=1;i<=n;++i)cout<<a2[i]<<" ";cout<<endl;
//	for(re int i=1;i<=m;++i)cout<<b[i]<<" ";cout<<endl;
	A1.build(n,a1),A2.build(n,a2),B.build(m,b);
	for(re int l1,r1,l2,r2;q;--q){
		io::read(l1),io::read(r1),io::read(l2),io::read(r2);LL ans=-inf;
		int bmin=B.query(0,l2,r2),bmax=B.query(1,l2,r2);
//		cout<<bmin<<" "<<bmax<<" ";
		if(A1.query(0,l1,r1)!=2e9){
			if(bmin<0)ans=max(ans,1ll*bmin*A1.query(0,l1,r1));
			else ans=max(ans,1ll*bmin*A1.query(1,l1,r1));
		}
//		cout<<ans<<" ";
		if(A2.query(0,l1,r1)!=2e9){
			if(bmax>0)ans=max(ans,1ll*bmax*A2.query(1,l1,r1));
			else ans=max(ans,1ll*bmax*A2.query(0,l1,r1));
		}
		printf("%lld\n",ans);
	}
}
int main(){
	freopen("data.in", "r", stdin);
	init(),solve();
	return 0;
}
