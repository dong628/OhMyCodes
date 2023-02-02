#include <cstdio>
#include <iostream>
#include <cmath>
#include <set>
using std::make_pair, std::next, std::min;

const int Maxq = 
struct Edge{
	int from, to, val, cur, fx;
};
vector <Edge> edges[Maxp];
void stinit(void);
std::set < std::pair <int, int> > seg[Maxk];
int n, k, q, a[Maxn], c[Maxq], d[Maxq], x[Maxq], y[Maxq], cnt;
int s, t, st[Maxn][Maxlog];

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d %d %d", &n, &k, &q);

	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
	}
	stinit();
	cnt = 1;
	for(int i=1; i<=q; i++){
		scanf("%d %d %d %d", &c[i], &d[i], &x[i], &y[i]);
		seg[c[i]].push(make_pair(x[i], cnt++));
		seg[d[i]].push(make_pair(y[i], cnt++));
		addedge(cnt-2, cnt-1, Inf);
	}
	t = cnt++; s = 0;
	for(int i=1; i<=k; i++){
		addedge(s, seg[i].begin() -> second, query(1, seg[i].begin() -> first));
		for(auto itr=seg[i].begin(); itr!=prev(seg[i].end); itr++){
			addedge(itr -> second, next(itr) -> second, query(next(itr) -> first, itr -> first));
		}
		addedge(seg[i].rbegin() -> second, t, query(n, seg[i].rbegin() -> first));
	}

	return 0;
}

void stinit(void){
	int logg = log(n) / log(2);
	for(int i=1; i<=n; i++) st[i][0] = a[i];
	for(int i=1; i<=logg; i++){
		for(int j=1; j<=n-(1<<i)+1; j++){
			st[j][i] = min(st[j][i-1], st[j+(1<<(i-1))][i-1]);
		}
	}
}

int query(int l, int r){
	int logg = log(r-l+1) / log(2);
	return min(st[l][logg], st[r-(1<<logg)+1][logg]);
}

void addedge(int from, int to, int val){
	Edge tmp1, tmp2;

	tmp1.to = to; tmp1.from = from;
	tmp1.val = val; tmp1.cur = 0;
	tmp1.fx = edges[to].size();

	tmp2.to = from; tmp2.from = to;
	tmp2.val = val; tmp2.cur = val;
	tmp2.fx = edges[from].size();

	edges[from].push_back(tmp1);
	edges[to].push_back(tmp2);
}
