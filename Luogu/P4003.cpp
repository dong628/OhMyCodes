#include <cstdio>
#include <iostream>

#include <cstring>
#include <queue>
#include <vector>
using std::min, std::queue;

//const int Maxn = 1e2+5, Inf = 0x3f3f3f3f;
const int Maxn = 6e3+5, Inf = 0x3f3f3f3f;
struct Edge{
	int from, to, val, cur, cos, fx;
} pre[Maxn], tmp;
std::vector<Edge> mapp[Maxn];
int n, m, s, t, flow[Maxn], dis[Maxn], mincost, maxflow, cnt[Maxn];
bool vis[Maxn];

bool spfa(void);
void addflow(void);
void connect(int, int, int, int);
void addedge(int, int, int, int);
int popcount(int x){
	int ans = 0;
	while(x){
		if(x&1) ans++;
		x >>= 1;
	}
	return ans;
}

int dec(int, int, int);

int main(){
	freopen("data.in", "r", stdin);

	int indp, tb, ppc, valid = 0, ipj;
	scanf("%d %d", &n, &m);
	s = 0, t = (n+2)*(m+2);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			scanf("%d", &tb);
			indp = i * (m + 2) + j;
			ipj = i + j;
			ppc = popcount(tb);
			if((ipj & 1) == 0) addedge(s, indp, ppc, 0);
			else addedge(indp, t, ppc, 0);
			if(ipj & 1) valid += ppc;
			m += 2;
			if(tb == 0){
				continue;
			}
			else if(tb == 1){
				connect(indp, dec(i, j, 0), 0, ipj & 1);
				connect(dec(i, j, 0), dec(i, j, 1), 1, ipj & 1);
				connect(dec(i, j, 0), dec(i, j, 3), 1, ipj & 1);
				connect(dec(i, j, 0), dec(i, j, 2), 2, ipj & 1);
			}
			else if(tb == 2){
				connect(indp, dec(i, j, 1), 0, ipj & 1);
				connect(dec(i, j, 1), dec(i, j, 2), 1, ipj & 1);
				connect(dec(i, j, 1), dec(i, j, 0), 1, ipj & 1);
				connect(dec(i, j, 1), dec(i, j, 3), 2, ipj & 1);
			}
			else if(tb == 3){
				connect(indp, dec(i, j, 0), 0, ipj & 1);
				connect(indp, dec(i, j, 1), 0, ipj & 1);
				connect(dec(i, j, 0), dec(i, j, 2), 1, ipj & 1);
				connect(dec(i, j, 1), dec(i, j, 3), 1, ipj & 1);
			}
			else if(tb == 4){
				connect(indp, dec(i, j, 3), 0, ipj & 1);
				connect(dec(i, j, 3), dec(i, j, 2), 1, ipj & 1);
				connect(dec(i, j, 3), dec(i, j, 0), 1, ipj & 1);
				connect(dec(i, j, 3), dec(i, j, 1), 2, ipj & 1);
			}
			else if(tb == 5){
				connect(indp, dec(i, j, 0), 0, ipj & 1);
				connect(indp, dec(i, j, 2), 0, ipj & 1);
			}
			else if(tb == 6){
				connect(indp, dec(i, j, 2), 0, ipj & 1);
				connect(indp, dec(i, j, 1), 0, ipj & 1);
				connect(dec(i, j, 2), dec(i, j, 0), 1, ipj & 1);
				connect(dec(i, j, 1), dec(i, j, 3), 1, ipj & 1);
			}
			else if(tb == 7){
				connect(indp, dec(i, j, 0), 0, ipj & 1);
				connect(indp, dec(i, j, 2), 0, ipj & 1);
				connect(indp, dec(i, j, 1), 0, ipj & 1);
				connect(dec(i, j, 1), dec(i, j, 3), 2, ipj & 1);
				connect(dec(i, j, 0), dec(i, j, 3), 1, ipj & 1);
				connect(dec(i, j, 2), dec(i, j, 3), 1, ipj & 1);
			}
			else if(tb == 8){
				connect(indp, dec(i, j, 3), 0, ipj & 1);
				connect(dec(i, j, 3), dec(i, j, 2), 1, ipj & 1);
				connect(dec(i, j, 3), dec(i, j, 0), 1, ipj & 1);
				connect(dec(i, j, 3), dec(i, j, 1), 2, ipj & 1);
			}
			else if(tb == 9){
				connect(indp, dec(i, j, 0), 0, ipj & 1);
				connect(indp, dec(i, j, 3), 0, ipj & 1);
				connect(dec(i, j, 0), dec(i, j, 2), 1, ipj & 1);
				connect(dec(i, j, 3), dec(i, j, 1), 1, ipj & 1);
			}
			else if(tb == 10){
				connect(indp, dec(i, j, 3), 0, ipj & 1);
				connect(indp, dec(i, j, 1), 0, ipj & 1);
			}
			else if(tb == 11){
				connect(indp, dec(i, j, 0), 0, ipj & 1);
				connect(indp, dec(i, j, 3), 0, ipj & 1);
				connect(indp, dec(i, j, 1), 0, ipj & 1);
				connect(dec(i, j, 0), dec(i, j, 2), 2, ipj & 1);
				connect(dec(i, j, 1), dec(i, j, 2), 1, ipj & 1);
				connect(dec(i, j, 3), dec(i, j, 2), 1, ipj & 1);
			}
			else if(tb == 12){
				connect(indp, dec(i, j, 2), 0, ipj & 1);
				connect(indp, dec(i, j, 3), 0, ipj & 1);
				connect(dec(i, j, 2), dec(i, j, 0), 1, ipj & 1);
				connect(dec(i, j, 3), dec(i, j, 1), 1, ipj & 1);
			}
			else if(tb == 13){
				connect(indp, dec(i, j, 0), 0, ipj & 1);
				connect(indp, dec(i, j, 2), 0, ipj & 1);
				connect(indp, dec(i, j, 3), 0, ipj & 1);
				connect(dec(i, j, 3), dec(i, j, 1), 2, ipj & 1);
				connect(dec(i, j, 0), dec(i, j, 1), 1, ipj & 1);
				connect(dec(i, j, 2), dec(i, j, 1), 1, ipj & 1);
			}
			else if(tb == 14){
				connect(indp, dec(i, j, 2), 0, ipj & 1);
				connect(indp, dec(i, j, 3), 0, ipj & 1);
				connect(indp, dec(i, j, 1), 0, ipj & 1);
				connect(dec(i, j, 2), dec(i, j, 0), 2, ipj & 1);
				connect(dec(i, j, 3), dec(i, j, 0), 1, ipj & 1);
				connect(dec(i, j, 1), dec(i, j, 0), 1, ipj & 1);
			}
			else{
				connect(indp, dec(i, j, 0), 0, ipj & 1);
				connect(indp, dec(i, j, 2), 0, ipj & 1);
				connect(indp, dec(i, j, 3), 0, ipj & 1);
				connect(indp, dec(i, j, 1), 0, ipj & 1);
			}
			m -= 2;
		}
	}

	while(spfa()){
		addflow();
	}

	if(maxflow == valid){
		printf("%d", mincost);
	}
	else printf("-1");

	return 0;
}

void connect(int u, int v, int cos, int rev){
	Edge tmp;
//	if(!rev) printf("%d %d 1 %d\n", u, v, cos);
//	else printf("%d %d 1 %d\n", v, u, cos);

	tmp.cos = rev ? -cos : cos;
	tmp.from = u; tmp.to = v;
	tmp.val = 1; tmp.cur = rev;
	tmp.fx = cnt[v];
	mapp[u].push_back(tmp);
	
	tmp.cos = rev ? cos : -cos;
	tmp.from = v; tmp.to = u;
	tmp.val = 1; tmp.cur = !rev;
	tmp.fx = cnt[u];
	mapp[v].push_back(tmp);

	cnt[u]++; cnt[v]++;
}

void addedge(int u, int v, int val, int cos){
	Edge tmp;
//	printf("%d %d %d %d\n", u, v, val, cos);

	tmp.cos = cos;
	tmp.from = u; tmp.to = v;
	tmp.val = val; tmp.cur = 0;
	tmp.fx = cnt[v];
	mapp[u].push_back(tmp);
	
	tmp.cos = -cos;
	tmp.from = v; tmp.to = u;
	tmp.val = val; tmp.cur = val; 
	tmp.fx = cnt[u];
	mapp[v].push_back(tmp);

	cnt[u]++; cnt[v]++;
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
				pre[tar.to] = mapp[tar.to][tar.fx];
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
//		printf("%d ", i.to);
		mapp[i.to][i.fx].cur += flow[t];
		mapp[i.from][mapp[i.to][i.fx].fx].cur -= flow[t];
	}
//	printf("\n");
	mapp[i.to][i.fx].cur += flow[t];
	mapp[i.from][mapp[i.to][i.fx].fx].cur -= flow[t];
}

int dec(int x, int y, int face){
	int ans;
	if(face == 0){
		ans = (n+1)*(y-1)+x+t;
	}
	else if(face == 1){
		ans = (m+1)*(x-1)+y+(n+1)*m+t+1;
	}
	else if(face == 2){
		ans = (n+1)*(y-1)+x+t+1;
	}
	else{
		ans = (m+1)*(x-1)+y+(n+1)*m+t;
	}
	return ans;
}
