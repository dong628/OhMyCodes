#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

inline int read() {
	int x = 0, f = 1; char s = getchar();
	while (s < '0' || s > '9') { if (s == '-') f = -f; s = getchar(); }
	while (s >= '0' && s <= '9') { x = x * 10 + s - '0'; s = getchar(); }
	return x * f;
}

const int N = 100100;
const int mod = 998244353;

int n;

int a[N];

int m;

struct operation {
	int opt;
	int pos, val;
	vector<int> g;
} T[N];

int mul[N];

void calc(int u) {
	if (mul[u] != -1) return;

	switch (T[u].opt) {
		case 1: {
			mul[u] = 1;

			break;
		}

		case 2: {
			mul[u] = T[u].val;

			break;
		}

		case 3: {
			mul[u] = 1;
			for (int i = 0; i < (int)T[u].g.size(); i ++) {
				int v = T[u].g[i];
				calc(v);
				mul[u] = 1ll * mul[u] * mul[v] % mod;
			}

			break;
		}
	}
}

int Q;
int idx[N];

int b;
int f[N];

int deg[N];

int k[N];

void topsort() {
	queue<int> q;

	for (int i = 1; i <= m; i ++)
		if (deg[i] == 0) q.push(i);

	while (q.size()) {
		int u = q.front(); q.pop();

		switch (T[u].opt) {
			case 1: {
				k[T[u].pos] = (k[T[u].pos] + 1ll * f[u] * T[u].val) % mod; 

				break;
			}

			case 2: {
				break;
			}

			case 3: {
				for (int j = T[u].g.size() - 1; j >= 0; j --) {
					int v = T[u].g[j];
					f[v] = (f[v] + f[u]) % mod;
					f[u] = 1ll * f[u] * mul[v] % mod;
					if (-- deg[v] == 0) q.push(v);
				}

				break;
			}
		}
	}
}

int main() {
	freopen("data.in", "r", stdin);

	n = read();

	for (int i = 1; i <= n; i ++)
		a[i] = read();

	m = read();

	for (int i = 1; i <= m; i ++) {
		T[i].opt = read();

		switch (T[i].opt) {
			case 1: {
				T[i].pos = read(), T[i].val = read();

				break;
			}

			case 2: {
				T[i].val = read();

				break;
			}

			case 3: {
				int C = read();
				for (int j = 1; j <= C; j ++) {
					int x = read();
					T[i].g.push_back(x);
				}

				break;
			}
		} 
	}

	memset(mul, -1, sizeof(mul));
	for (int i = 1; i <= m; i ++)
		if (mul[i] == -1) calc(i); 

	Q = read();

	for (int i = 1; i <= Q; i ++)
		idx[i] = read();

	b = 1;
	for (int i = Q; i >= 1; i --) {
		switch (T[idx[i]].opt) {
			case 1: {
				f[idx[i]] = (f[idx[i]] + b) % mod;

				break;
			}

			case 2: {
				b = 1ll * b * T[idx[i]].val % mod;

				break;
			}

			case 3: {
				f[idx[i]] = (f[idx[i]] + b) % mod;
				b = 1ll * b * mul[idx[i]] % mod;

				break;
			}
		}
	}

	for (int u = 1; u <= m; u ++) {
		if (T[u].opt != 3) continue;

		for (int j = 0; j < (int)T[u].g.size(); j ++) {
			int v = T[u].g[j];
			deg[v] ++;
		} 
	}

	topsort();

	for (int i = 1; i <= n; i ++)
		printf("%d ", (1ll * a[i] * b + k[i]) % mod);
	puts("");

	return 0;
}
