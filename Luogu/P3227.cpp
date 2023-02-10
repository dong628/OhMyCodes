#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int Maxn = 64005, Inf = 0x3f3f3f3f, Ctrl = 10000;
//const int Maxn = 64, Inf = 0x3f3f3f3f;
struct Edge{
	int from, to, cur, val, fx;
};

vector <Edge> edges[Maxn];
int p, q, r, d, s, t, v, depth[Maxn];
bool vis[Maxn];
int encode(int, int, int);
bool bfs(void);
int dfs(int, int);
void addedge(int, int, int);

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d %d %d", &p, &q, &r);
	scanf("%d", &d);
	for(int z=1; z<=r; z++){
		for(int x=1; x<=p; x++){
			for(int y=1; y<=q; y++){
				scanf("%d", &v);
				addedge(encode(x, y, z), encode(x, y, z+1), v + Ctrl);
				if(z + d <= r){
					if(y+1 <= q) addedge(encode(x, y+1, z+d+1), encode(x, y, z+1), Inf);
					if(y-1 >= 1) addedge(encode(x, y-1, z+d+1), encode(x, y, z+1), Inf);
					if(x+1 <= p) addedge(encode(x+1, y, z+d+1), encode(x, y, z+1), Inf);
					if(x-1 >= 1) addedge(encode(x-1, y, z+d+1), encode(x, y, z+1), Inf);
				}
			}
		}
	}
	s = 0; t = p * q * (r + 1) + 1;
	for(int x=1; x<=p; x++){
		for(int y=1; y<=q; y++){
			addedge(encode(x, y, r+1), t, Inf);
			addedge(s, encode(x, y, 1), Inf);
		}
	}

	int maxflow = 0;
	while(bfs()){
		maxflow += dfs(s, Inf);
	}

	printf("%d", maxflow - Ctrl * p * q);

	return 0;
}

int encode(int x, int y, int z){
	return (z-1)*p*q + (x-1)*q + y;
}

bool bfs(void){
	memset(vis, 0, sizeof(vis));
	memset(depth, 0, sizeof(depth));
	queue <int> q;
	q.push(s);
	vis[s] = true;
	int cur;
	Edge tar;
	while(!q.empty()){
		cur = q.front(); q.pop();
		for(int i=0; i<edges[cur].size(); i++){
			tar = edges[cur][i];
			if(tar.val > tar.cur && !vis[tar.to]){
				depth[tar.to] = depth[cur] + 1;
				vis[tar.to] = true;
				q.push(tar.to);
			}
		}
	}

	return vis[t];
}

int dfs(int cur, int flow){
	if(cur == t || flow == 0) return flow;
	Edge tar;
	int out = 0, tmp;
	for(int i=0; i<edges[cur].size(); i++){
		tar = edges[cur][i];
		if(depth[tar.to] != depth[cur] + 1) continue;
		tmp = dfs(tar.to, min(flow, tar.val - tar.cur));
		edges[cur][i].cur += tmp;
		edges[tar.to][tar.fx].cur -= tmp;
		flow -= tmp;
		out += tmp;
		if(flow == 0) break;
	}

	if(out == 0) depth[cur] = -1;
	return out;
}

void addedge(int from, int to, int val){
	Edge tmp;
	tmp.from = from; tmp.to = to;
	tmp.val = val; tmp.cur = 0;
	tmp.fx = edges[to].size();
//	printf("addedge: %d %d %d\n", from, to, val);
	edges[from].push_back(tmp);

	tmp.from = to; tmp.to = from;
	tmp.val = val; tmp.cur = val;
	tmp.fx = edges[from].size()-1;
	edges[to].push_back(tmp);
}
