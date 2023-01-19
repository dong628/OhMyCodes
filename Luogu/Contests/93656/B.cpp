#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
using std::max;

const int Maxn = 505;

struct Node{
	int u, v, w;
	Node(const int &uu, const int &vv, const int &ww) : u(uu), v(vv), w(ww) {}
	inline bool operator< (const Node &b) const { return w < b.w; }
} cur(0, 0, 0);
//std::priority_queue < Node, std::vector <Node>, std::greater <Node> > edges;
std::multiset <Node> edges;
std::vector <int> vecu, vecv;
int a[Maxn], b[Maxn], bset[Maxn];

int find(int x){
	if(bset[x] == x) return x;
	else return bset[x] = find(bset[x]);
}

void merge(int x, int y){
	bset[find(y)] = find(bset[x]);
}

int main(){
	freopen("data.in", "r", stdin);

	int n;
	long long val = 0;
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
	}
	for(int i=1; i<=n; i++){
		scanf("%d", &b[i]);
	}
	for(int i=1; i<=n; i++){
		for(int j=i+1; j<=n; j++){
			edges.insert(Node(i, j, max(a[i], a[j])+max(b[i], b[j])));
		}
	}
	for(int i=1; i<=n; i++) bset[i] = i;
	for(int cnt = 1; cnt < n; ){
		cur = *edges.begin(); edges.erase(edges.begin());
		if(find(cur.u) == find(cur.v)) continue;
		merge(cur.u, cur.v);
		vecu.push_back(cur.u); vecv.push_back(cur.v);
		cnt++; val += cur.w;
	}
	printf("%lld\n", val);
	for(int i=0; i<n-1; i++){
		printf("%d %d\n", vecu[i], vecv[i]);
	}

	return 0;
}
