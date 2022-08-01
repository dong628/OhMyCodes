#include <cstdio>
#include <iostream>
#include <algorithm>
#define int long long
using std::sort;

const int Maxn = 3e5+5;
struct Edge{
	int l, t;
}edge[2*Maxn];
bool cmp(Edge x, Edge y) { return x.l<y.l; }
bool cmp1(int x, int y) { return x<y; }
int n, m, ai, bi, ans, t0, t1, cnt, a, b, prea[Maxn], preb[Maxn];

signed main(){
	freopen("data.in", "r", stdin);

	scanf("%lld %lld %lld %lld", &a, &b, &n, &m);
	for(int i=1; i<=n; i++){
		scanf("%lld", &prea[i]);
	}
	prea[n+1] = a; n++;
	for(int i=1; i<=m; i++){
		scanf("%lld", &preb[i]);
	}
	preb[m+1] = b; m++;
	sort(prea, prea+n+1, cmp1);
	sort(preb, preb+m+1, cmp1);

	for(int i=1; i<=n; i++){
		edge[i-1].l = prea[i]-prea[i-1]; edge[i-1].t = 0;
	}
	for(int i=n+1; i<m+n+1; i++){
		edge[i-1].l = preb[i-n]-preb[i-n-1]; edge[i-1].t = 1;
	}
	sort(edge, edge+m+n, cmp);
	for(int i=0; i<m+n; i++){
		if(edge[i].t == 0){
			t0++;
			if(t0 == 1 || t1 == 0){
				ans += edge[i].l*(m-1);
				cnt += m-1;
			}
			else{
				ans += edge[i].l*(m-t1);
				cnt += m-t1;
			}
		}
		else{
			t1++;
			if(t1 == 1 || t0 == 0){
				ans += edge[i].l*(n-1);
				cnt += n-1;
			}
			else{
				ans += edge[i].l*(n-t0);
				cnt += n-t0;
			}
		}
		if(cnt>=m*n-1) break;
	}
	printf("%lld", ans);

	return 0;
}
