#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int Max=100005;
int a[Max][Max], d[Max], b;
bool v[Max];
int aa, aj, n, m, o, s, t;

void dijkstra(int start) {
	memset(d, 0x3f, sizeof(d)); // dist数组
	memset(v, 0, sizeof(v)); // 节点标记
	d[start] = 0;
	for (int i = 1; i < n; i++) { // 重复进行n-1次
		int x = 0;
		// 找到未标记节点中dist最小的
		for (int j = 1; j <= n; j++)
			if (!v[j] && (x == 0 || d[j] < d[x])) x = j;
		v[x] = 1;
		// 用全局最小值点x更新其它节点
		for (int y = 1; y <= n; y++)
			d[y] = min(d[y], d[x] + a[x][y]);
	}
}

int main() {
	freopen("data.in", "r", stdin);

	scanf("%d", &t);
	for(int x=0; x<t; x++){
		scanf("%d %d %d %d", &n, &m, &o, &s);
		// 构建邻接矩阵
		memset(a, 0x3f, sizeof(a));
		for (int i = 1; i <= n; i++) a[i][i] = 0;
		for (int i = 1; i <= m; i++) {
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			a[x][y] = min(a[x][y], z*2);
			a[y][x] = min(a[y][x], z*2);
		}
		for(int i=1; i<=o; i++){
			scanf("%d %d", &aa, &b);
			for(int j=1; j<=aa; j++){
				scanf("%d", &aj);
				a[aj][n+i]=min(a[aj][n+i], b);
				a[n+i][aj]=min(a[n+i][aj], b);
			}
		}
		n+=o;
		// 求单源最短路径
		dijkstra(s);
		for (int i = 1; i <= n-o; i++)
			printf("%d ", d[i]/2);
		printf("\n");
	}
}

