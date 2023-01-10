#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using std::min, std::vector, std::pair, std::make_pair;

const int Maxn = 105;
int dis[Maxn];
bool vis[Maxn];
vector < pair <int, int> > mp[Maxn];

int main(){
	freopen("data.in", "r", stdin);

	int tt, n, m, cnt, s, t, v;
	bool flag;
	scanf("%d", &tt);
	while(tt --> 0){
		memset(vis, 0, sizeof(vis));
		scanf("%d %d", &n, &m);
		mp[0].clear();
		for(int i=1; i<=n+1; i++){
			mp[i].clear();
		}
		for(int i=0; i<m; i++){
			scanf("%d %d %d", &s, &t, &v);
			mp[s].push_back(make_pair(t+1, v));
			mp[t+1].push_back(make_pair(s, -v));
			vis[s] = true; vis[t+1] = true;
		}
		memset(dis, 0x3f, sizeof(dis));
		dis[0] = 0; cnt = 0;
		for(int i=1; i<=n+1; i++){
			if(vis[i]){
				cnt++;
				mp[0].push_back(make_pair(i, 0));
			}
		}

		for(int i=1; i<=cnt; i++){
			for(int j=0; j<=n+1; j++){
				for(int k=0; k<mp[j].size(); k++){
					dis[mp[j][k].first] = min(dis[mp[j][k].first], dis[j]+mp[j][k].second);
				}
			}
		}
		flag = true;
		for(int j=0; j<=n+1; j++){
			for(int k=0; k<mp[j].size(); k++){
				if(dis[mp[j][k].first] > dis[j]+mp[j][k].second) flag = false;
			}
		}
		printf(flag ? "true\n" : "false\n");
	}

	return 0;
}
