#include <cstdio>
#include <iostream>
#include <algorithm>

const int Maxn=5005, Maxm=2e5+5;
struct Edge{
	int x, y, z;
}edge[Maxm];
bool cmp(Edge x, Edge y){ return x.z<y.z; }
int tree[Maxn], n, m, cnt, ans;
void init(void);
int find(int);
void merge(int, int);

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d %d", &n, &m);
	for(int i=1; i<=m; i++){
		scanf("%d %d %d", &edge[i].x, &edge[i].y, &edge[i].z);
	}
	std::sort(edge+1, edge+m+1, cmp);
	init();
	for(int i=1; i<=m; i++){
		if(find(edge[i].x) != find(edge[i].y)){
			merge(edge[i].x, edge[i].y);
			ans+=edge[i].z;
			cnt++;
		}
	}
	if(cnt!=n-1) printf("orz");
	else printf("%d", ans);

	return 0;
}

void init(void){
	for(int i=1; i<=n; i++) tree[i]=i;
}

int find(int x){
	return x==tree[x] ? x:(tree[x]=find(tree[x]));
}

void merge(int x, int y){
	tree[find(x)]=find(y);
}
