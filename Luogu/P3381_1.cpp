#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
using std::min, std::queue;

//const int Maxn = 1e1+5, Inf = 0x3f3f3f3f;
const int Maxn = 5e3+5, Inf = 0x3f3f3f3f;
struct Edge{
	int from, to, val, cur, cos;
	Edge* fx;
} pre[Maxn], tmp;
std::vector<Edge> mapp[Maxn];
int n, m, s, t, flow[Maxn], dis[Maxn], mincost, maxflow, cnt[Maxn];
bool vis[Maxn];

bool spfa(void);
void addflow(void);

int main(){
	freopen("data.in", "r", stdin);
	
	int u, v, w, c;
	scanf("%d %d %d %d", &n, &m, &s, &t);
	for(int i=0; i<m; i++){
		scanf("%d %d %d %d", &u, &v, &w, &c);
		mapp[u].push_back(tmp);
		mapp[v].push_back(tmp);
		mapp[u][cnt[u]].from = u;
		mapp[v][cnt[v]].from = v;
		mapp[u][cnt[u]].to = v;
		mapp[v][cnt[v]].to = u;
		mapp[u][cnt[u]].val = w;
		mapp[v][cnt[v]].val = w;
		mapp[v][cnt[v]].cur = w;
		mapp[u][cnt[u]].cos = c;
		mapp[v][cnt[v]].cos = -c;
		mapp[u][cnt[u]].fx = mapp[v].at(cnt[v]);
		mapp[v][cnt[v]].fx = mapp[u].at(cnt[u]);
		cnt[u]++; cnt[v]++;
	}

	while(spfa()){
		addflow();
	}
	printf("%d %d", maxflow, mincost);

	return 0;
}

bool spfa(void){
	queue<int> q;
	int cur;
	Edge tar;
	q.push(s);
	flow[s] = Inf;
	memset(vis, 0, sizeof(vis));
	memset(dis, 0x3f, sizeof(dis));
	dis[s] = 0;
	while(!q.empty()){
		cur = q.front(); q.pop();
		vis[cur] = true;
		for(int i=0; i<cnt[cur]; i++){
			tar = mapp[cur][i];
			if(tar.val>tar.cur && dis[cur]+tar.cos<dis[tar.to]){
				dis[tar.to] = dis[cur]+tar.cos;
				flow[tar.to] = min(flow[cur], tar.val-tar.cur);
				pre[tar.to] = *tar.fx;
				q.push(tar.to);
			}
		}
	}
	return dis[t]!=Inf;
}

void addflow(void){
	maxflow += flow[t];
	mincost += flow[t]*dis[t];
	Edge i;
	for(i=pre[t]; i.to!=s; i=pre[i.to]){
		i.fx -> cur += flow[t];
		i.fx -> fx -> cur -= flow[t];
	}
	i.fx -> cur += flow[t];
	i.fx -> fx -> cur -= flow[t];
}
