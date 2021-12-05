#include <cstdio>
#include <iostream>
#include <vector>

const int Maxn = 6e3+5;
std::vector<int> mapp[Maxn];
int n, a[Maxn], l, k, cnt[Maxn], root, f[Maxn][2];
bool av[Maxn];
int dfs(int, int);
int max(int xx, int yy) { return xx>yy?xx:yy; }

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
	}
	for(int i=1; i<=n-1; i++){
		scanf("%d %d", &l, &k);
		av[l] = true;
		mapp[k].push_back(l);
		cnt[k]++;
	}
	for(int i=1; i<=n; i++){
		if(!av[i]) root=i;
	}
	printf("%d", max(dfs(root, 1), dfs(root, 0)));

	return 0;
}

int dfs(int nod, int type){
	int ans = 0;
	if(f[nod][type]!=0) return f[nod][type];
	for(int i=0; i<cnt[nod]; i++){
		if(type == 1){
			ans += dfs(mapp[nod][i], 0);
		}
		else{
			ans += max(dfs(mapp[nod][i], 0), dfs(mapp[nod][i], 1));
		}
	}
	if(type == 1) ans+=a[nod];
	f[nod][type] = ans;
	return ans;
}
