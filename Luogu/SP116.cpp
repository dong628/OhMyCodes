#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using std::min, std::vector, std::pair, std::make_pair;

const int Maxn = 5e4+5;
int dis[Maxn], cntrd[Maxn];
bool vis[Maxn], inq[Maxn];
vector < pair <int, int> > mp[Maxn];

int main(){
	freopen("data.in", "r", stdin);

	int tt, n, m, cnt, s, t, v, cur, maxx;
	bool flag;
	scanf("%d", &tt);
	while(tt --> 0){
		maxx = 0;
		memset(vis, 0, sizeof(vis));
		memset(inq, 0, sizeof(inq));
		memset(cntrd, 0, sizeof(cntrd));
		mp[0].clear();
		scanf("%d", &n);
		for(int i=1; i<Maxn; i++){
			mp[i].clear();
		}
		for(int i=0; i<n; i++){
			scanf("%d %d %d", &s, &t, &v);
			mp[s].push_back(make_pair(t+1, v));
			mp[t+1].push_back(make_pair(s, -v));
//			vis[s] = true; vis[t+1] = true;
			maxx = maxx > t+1 ? maxx : t+1;
		}
		for(int i=2; i<=maxx; i++){
			mp[i].push_back(make_pair(i-1, 0));
			mp[i-1].push_back(make_pair(i, 1));
		}
		memset(dis, 0x3f, sizeof(dis));
		dis[0] = 0; cnt = 0;
		for(int i=1; i<=maxx; i++){
//			if(vis[i]){
			cnt++;
			mp[0].push_back(make_pair(i, 0));
//			}
		}

		std::queue <int> q;
		q.push(0);
		cntrd[0]++;
		while(!q.empty()){
			cur = q.front(); q.pop();
			inq[cur] = false;
			for(int i=0; i<mp[cur].size(); i++){
				if(dis[mp[cur][i].first] > dis[cur]+mp[cur][i].second){
					dis[mp[cur][i].first] = dis[cur]+mp[cur][i].second;
					if(!inq[mp[cur][i].first]){
						inq[mp[cur][i].first] = true;
						q.push(mp[cur][i].first);
						cntrd[mp[cur][i].first]++;
					}
				}
			}
		}
		printf("%d\n", dis[maxx]-dis[1]);

/*
		for(int i=maxx; i>0; i--){
			if(vis[i]){
				printf("%d\n", dis[i]);
				break;
			}
		}
		for(int i=1; i<=maxx; i++){
			printf("%d ", dis[i]);
		}
*/
	}

	return 0;
}
