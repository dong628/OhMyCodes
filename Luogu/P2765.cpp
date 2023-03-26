#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <cmath>
using std::max, std::min;

const int Maxn = 1e5+5, Inf = 0x7fffffff;

struct Edge{
	int from, to, fx, cur, val;
};
std::vector <Edge> edges[Maxn];
int next[Maxn], depth[Maxn], s, t;
bool judge(int x) { return int(sqrt(x))*int(sqrt(x)) == x; }
void addedge(int, int, int);
bool bfs(void);
int dfs(int, int);

int main(){
//	freopen("data.in", "r", stdin);

	int n;
	scanf("%d", &n);

	s = 0; t = 1;
	int ans = 0, cur = 0, sum = 0;
	std::vector <int> firsts;
	for(int i=1; ; i++){
		addedge(s, i*2, 1);
		addedge(i*2+1, t, 1);
		for(int j=1; j<i; j++){
			if(judge(j+i)) addedge(j*2, i*2+1, 1);
		}
		cur = 0;
		while(bfs()){
			cur += dfs(s, Inf);
		}
//		printf("cur = %d\n", cur);
		if(cur != 0){
			for(int j=0; j<edges[i*2+1].size(); j++){
				if(edges[i*2+1][j].to != t && edges[i*2+1][j].cur == 0){
					next[edges[i*2+1][j].to/2] = i;
				}
			}
		}
		else{
			sum++;
			if(sum > n) break;
			firsts.push_back(i);
		}
		ans += cur;
	}

	printf("%d\n", ans+n);
	for(int i=0; i<firsts.size(); i++){
		for(int j=firsts[i]; j!=0; j=next[j]){
			printf("%d ", j);
		}
		putchar('\n');
	}


	return 0;
}

void addedge(int u, int v, int w){
	Edge t1, t2;
	t1.from = u; t1.to = v;
	t1.cur = 0; t1.val = w;
	t1.fx = edges[v].size();
	t2.from = v; t2.to = u;
	t2.cur = w; t2.val = w;
	t2.fx = edges[u].size();
	edges[u].push_back(t1);
	edges[v].push_back(t2);
//	printf("%d -> %d, w = %d\n", u, v, w);
}

bool bfs(void){
	memset(depth, 0, sizeof(depth));
	depth[s] = 1;
	std::queue <int> q;
	q.push(s);
	int tar;
	while(!q.empty()){
		tar = q.front(); q.pop();
		for(int i=0; i<edges[tar].size(); i++){
			if(edges[tar][i].val > edges[tar][i].cur && depth[edges[tar][i].to] == 0){
				q.push(edges[tar][i].to);
				depth[edges[tar][i].to] = depth[tar] + 1;
			}
		}
	}
	return depth[t];
}

int dfs(int cur, int flow){
	if(cur == t || flow == 0) return flow;
	int tmp, out = 0;
	Edge tar;
	for(int i=0; i<edges[cur].size(); i++){
		tar = edges[cur][i];
		if(depth[tar.to] != depth[cur] + 1) continue;
		tmp = dfs(tar.to, min(flow, tar.val - tar.cur));
		flow -= tmp;
		out += tmp;
		edges[cur][i].cur += tmp;
		edges[tar.to][tar.fx].cur -= tmp;
		if(flow == 0) break;
	}
	if(out == 0) depth[cur] = -1;
	return out;
}
