#include <cstdio>
#include <iostream>
#include <vector>

const int Mod = 1e9+7, Maxn = 1e4+5;
std::vector <int> baka, tmpa;
int ans, n, m, w, d, b[Maxn];
bool mapp[Maxn];
void dfs(int);

int main(){
	freopen("data.in", "r", stdin);

	int t, ta;
	scanf("%d", &t);
	while(t --> 0){
		ans = 0;
		baka.clear();
		scanf("%d %d %d %d", &n, &m, &w, &d);
		for(int i=1; i<=n; i++){
			scanf("%d", &ta);
			baka.push_back(ta);
		}
		for(int i=1; i<=m; i++){
			scanf("%d", &b[i]);
		}
		dfs(0);
		printf("%d\n", ans);
	}


	return 0;
}

void dfs(int step){
	if(step == d){
		int tmp = 0;
		bool flag;
		tmpa = baka;
		for(auto i=tmpa.end()--; i!=tmpa.begin(); i--){
			if(mapp[*i]) tmpa.erase(i);
		}
		if(mapp[*tmpa.begin()]) tmpa.erase(tmpa.begin());
		if(tmpa.size() < m) return;
		for(int i=0; i<tmpa.size()-m+1; i++){
			flag = true;
			for(int j=0; j<m; j++){
				if(tmpa[i+j] != b[j+1]){
					flag = false;
					break;
				}
			}
			if(flag) tmp++;
		}
		ans += tmp;
		ans %= Mod;
		return;
	}
	for(int i=1; i<=w; i++){
		if(mapp[i]) continue;
		mapp[i] = true;
		dfs(step + 1);
		mapp[i] = false;
	}
}
