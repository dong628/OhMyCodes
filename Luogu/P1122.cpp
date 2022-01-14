#include <cstdio>
#include <iostream>
#include <vector>
using std::vector;

const int Maxn = 16005;
vector<int> mapp[Maxn];
bool vis[Maxn];
int n, maxx=-0x7fffffff, f[Maxn], a, b, cnt[Maxn];
void dfs(int);

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%d", &f[i]);
	}
	for(int i=1; i<n; i++){
		scanf("%d %d", &a, &b);
		mapp[a].push_back(b); cnt[a]++;
		mapp[b].push_back(a); cnt[b]++;
	}
	vis[1] = true;
	dfs(1);
	for(int i=1; i<=n; i++){
		maxx = maxx>f[i]?maxx:f[i];
	}
	printf("%d", maxx);

	return 0;
}

void dfs(int root){
	for(int i=0; i<cnt[root]; i++){
		if(!vis[mapp[root][i]]){
			vis[mapp[root][i]] = true;
			dfs(mapp[root][i]);
			vis[mapp[root][i]] = false;
			if(f[mapp[root][i]]>0){
				f[root] += f[mapp[root][i]];
			}
		}
	}
}
