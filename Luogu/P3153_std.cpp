# include <iostream>
# include <cstdio>
# include <cstring>
# define int long long
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1e6 + 5;
const int maxm = 50 + 5;
int n , k;

char c[maxm];
int S , T;
int like[maxm][maxm];
int cnt[maxn] , dis[maxn];
typedef struct {
	int x , y , z , next;
} Edge;
Edge edge[maxn];
int E = 1  , elast[maxn];
void add(int x , int y , int z) {
	E ++;
	edge[E].x = x;
	edge[E].y = y;
	edge[E].z = z;
	edge[E].next = elast[x];
	elast[x] = E;
}
void rebuild(int mid) {
	for (int i = 1 ; i <= n ; i ++) {
		add(i + 1 , n + 1 + ((i - 1) << 1) + 1, inf);
		add(n + 1 + ((i - 1) << 1) + 1 , i + 1 , 0);
		add(i + 1 , n + 1 + ((i - 1) << 1) + 2 , k);
		add(n + 1 + ((i - 1) << 1) + 2 , i + 1 , 0);
		for (int j = 1 ; j <= n ; j ++) {
			if (like[i][j] == 1) {
				add(n + 1 + ((i - 1) << 1) + 1 , n * 3 + 1 + (j << 1) - 1 , 1);
				add(n * 3 + 1 + (j << 1) - 1 , n + 1 + ((i - 1) << 1) + 1 , 0);
			} else {
				add(n + 1 + ((i - 1) << 1) + 2 , n * 3 + 1 + (j << 1) , 1);
				add(n * 3 + 1 + (j << 1) , n + 1 + ((i - 1) << 1) + 2 , 0);
			}
		}

	}
	for (int i = 1 ; i <= n << 1 ; i ++) {
		if (i & 1) {
			add(n * 3 + 1 + i , ((i + 1) >> 1) + n * 5 + 1 , inf);
			add(((i + 1) >> 1) + n * 5 + 1 , n * 3 + 1 + i , 0);
		} else {
			add(n * 3 + 1 + i , n * 5 + 1 + (i >> 1) , k);
			add(n * 5 + 1 + (i >> 1) , n * 3 + 1 + i , 0);
		}
	}
	for (int i = 1 ; i <= n ; i ++) {
		add(1 , i + 1 , mid);
		add(i + 1 , 1 , mid);
	}
	for (int i = n * 5 + 1 + 1 ; i <= T - 1 ; i ++) {
		add(i , T , mid);
		add(T , i , mid);
	}

}
int dfs(int u , int flow) {
	int temp , delta;
	delta = 0;
	if (u == T) return flow;
	for (int i = elast[u] ; i ; i = edge[i].next) {
		int v = edge[i].y;
		if (edge[i].z > 0 && dis[u] == dis[v] + 1) {
			temp = dfs(v , min(flow - delta , edge[i].z));
			edge[i].z -= temp;
			edge[i ^ 1].z += temp;
			delta += temp;
			if (delta == flow || dis[1] >= T) return delta;
		}
	}
	if (dis[1] >= T) return delta;
	cnt[dis[u]] --;
	if (cnt[dis[u]] == 0) dis[1] = T;
	dis[u] = dis[u] + 1;
	cnt[dis[u]] ++;
	return delta;
}
signed main() {
	freopen("data.in", "r", stdin);

	cin >> n >> k;
	for (int i = 1 ; i <= n ; i ++) {
		scanf("%s" , &c);
		for (int j = 0 ; j < n ; j ++) {
			if (c[j] == 'Y') {
				like[i][j + 1] = 1;
			} else {
				like[i][j + 1] = 0;
			}
		}
	}
	S = 1;
	T = n * 6 + 2;
	int ans;
	int l = 0 , r = n, Ans;
	while (l <= r) {
		int mid = l + r >> 1;
		E = 1;
		memset(elast , 0 , sizeof elast);
		memset(dis , 0 , sizeof dis);
		rebuild(mid);
		ans = 0;
		while (dis[1] < T) {
			ans += dfs(1 , inf + 1);
		}
		if (ans == n * mid){
			l = mid + 1;
			Ans = mid;
		} else {
			r = mid - 1;
		}
	}
	printf("%d\n" , Ans);
	return 0;
}
