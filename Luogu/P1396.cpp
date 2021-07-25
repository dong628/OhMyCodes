#include <cstdio>
#include <iostream>
#include <algorithm>

const int Maxm=2e4+5, Maxn=1e4+5;
struct Edge{
	int u, v, w;
}e[Maxm];
int n, m, s, t, tree[Maxn], l, r, mid;
bool cmp(Edge x, Edge y) { return x.w<y.w; }
int find(int);
void init(void);
void merge(int, int);
bool calc(int);

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d %d %d %d", &n, &m, &s, &t);
	for(int i=1; i<=m; i++){
		scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);
	}
	std::sort(e+1, e+m+1, cmp);
	l=e[1].w; r=e[m].w;
	while(l<r){
		mid = (l+r)>>1;
		if(calc(mid)) r=mid;
		else l=mid+1;
	}

	printf("%d", l);

	return 0;
}

bool calc(int maxv){
	init();
	for(int i=1; i<=m; i++){
		if((find(e[i].u) != find(e[i].v)) && e[i].w<=maxv){
			merge(e[i].u, e[i].v);
		}
		else if(e[i].w>maxv) break;
	}
	if(find(s) == find(t)) return true;
	else return false;
}

void init(void){
	for(int i=1; i<=n; i++) tree[i]=i;
}

void merge(int a, int b){
	tree[find(a)]=find(b);
}

int find(int a){
	return tree[a]==a ? a:tree[a]=find(tree[a]);
}
