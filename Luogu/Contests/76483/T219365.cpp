#include <cstdio>
#include <iostream>

const int Inf = 0x7fffffff, Maxn = 250;
struct Xz{
	int i, j, x, y;
} xz[Maxn];
int n, k, q, a[Maxn], ans = Inf, lj[Maxn], rj[Maxn];
void dfs(int);
int minn(int l, int r){
	int min = Inf;
	for(int i=l; i<=r; i++){
		min = a[i]<min?a[i]:min;
	}
	return min;
}

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d %d %d", &n, &k, &q);
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
	}
	for(int i=1; i<=k; i++){
		lj[i] = 1; rj[i] = n;
	}
	for(int i=1; i<=q; i++){
		scanf("%d %d %d %d", &xz[i].i, &xz[i].j, &xz[i].x, &xz[i].y);
	}
	dfs(1);
	printf("%d", ans);

	return 0;
}

void dfs(int id){
	int tmp, summ = 0;
	if(id > q){
		for(int i=1; i<=k; i++){
			summ += minn(lj[i], rj[i]);
		}
		ans = ans<summ?ans:summ;
		return;
	}
	if(lj[xz[id].i] <= xz[id].x){
		tmp = rj[xz[id].i];
		rj[xz[id].i] = xz[id].x;
		dfs(id+1);
		rj[xz[id].i] = tmp;
	}
	if(rj[xz[id].j] >= n-xz[id].y+1){
		tmp = lj[xz[id].j];
		lj[xz[id].j] = n-xz[id].y+1;
		dfs(id+1);
		lj[xz[id].j] = tmp;
	}
}
