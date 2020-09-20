#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

int aa, aj, o, s, t, b;
const int N = 1000010, M = 2000010;
int head[N], ver[M], edge[M], Next[M], d[N];
bool v[N];
int n, m, tot;
priority_queue< pair<int, int> > q;
priority_queue< pair<int, int> > cle;

void add(int x, int y, int z) {
	ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot;
}

void dijkstra(int start) {
	memset(d, 0x3f, sizeof(d)); // dist数组
	memset(v, 0, sizeof(v)); // 节点标记
	d[start] = 0;
	q.push(make_pair(0, start));
	while (q.size()) {
		// 取出堆顶
		int x = q.top().second; q.pop();
		if (v[x]) continue;
		v[x] = 1;
		// 扫描所有出边
		for (int i = head[x]; i; i = Next[i]) {
			int y = ver[i], z = edge[i];
			if (d[y] > d[x] + z) {
				// 更新，把新的二元组插入堆
				d[y] = d[x] + z;
				q.push(make_pair(-d[y], y));
			}
		}
	}
}


int main() {
//	freopen("data.in", "r", stdin);

	scanf("%d", &t);
	for(int xxx=0; xxx<t; xxx++){
		tot=0;
		memset(head, 0, sizeof(head));
		memset(v, 0, sizeof(v));
		memset(ver, 0, sizeof(ver));
		memset(edge, 0, sizeof(edge));
		memset(Next, 0, sizeof(Next));
		memset(d, 0, sizeof(d));
		q=cle;
		
		scanf("%d %d %d %d", &n, &m, &o, &s);
		for (int i = 1; i <= m; i++) {
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			add(x, y, z*2);
			add(y, x, z*2);
		}
		for(int i=1; i<=o; i++){
			scanf("%d %d", &aa, &b);
			for(int j=1; j<=aa; j++){
				scanf("%d", &aj);
				add(aj, n+i, b);
				add(n+i, aj, b);
			}
		}
		n+=o;
		// 求单源最短路径
		dijkstra(s);
		for (int i = 1; i <= n-o-1; i++)
			printf("%d ", d[i]/2);
		printf("%d\n", d[n-o]/2);
	}
}

