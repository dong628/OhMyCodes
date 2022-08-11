#include <cstdio>
#include <iostream>
#include <queue>
using std::min, std::queue;

const int Maxn = 155;
struct Edge{
	int to, val, cur;
	Edge* fx;
} mapp[Maxn][Maxn];
int n, k, s, t, cnt[Maxn], depth[Maxn];
bool vis[Maxn];
bool calc(int), bfs(void);
void input(void), addedge(int, int, int);
int dfs(int, int);

int main(){
	input();
	int l = 0, r = n, mid;
	while(l<r){
		mid = (l+r+1)>>1;
		if(calc(mid)) l = mid;
		else r = mid-1;
	}
	printf("%d", l);

	return 0;
}

void input(void){
	scanf("%d %d\n", &n, &k);
	s = 0; t = 1;
	for(int i=1; i<=n; i++){
		addedge(s, 3*i, 0);
		addedge(3*i, 3*i+1, Inf);
		addedge(3*i, 3*i+2, k);
	}
	for(int j=n+1; j<=2*n; j++){
		addedge(3*j, t, 0);
		addedge(3*j, 3*j+1, Inf);
		addedge(3*j, 3*j+2, k);
	}
	for(int i=1; i<=n; i++){
		for(int j=n+1; j<=2*n; j++){
			scanf("%c", &ch);
		}
		getchar();
	}
}

void addedge(int from, int to, int val){
	Edge e, ne;
	e.to = to; e.val = val; e.cur = 0; e.fx = &mapp[e.to][cnt[e.to]];
	ne.to = from; ne.val = val; ne.cur = cur; ne.fx = &mapp[ne.to][cnt[ne.to]];
	mapp[from][cnt[from]++] = e;
	mapp[to][cnt[to]++] = ne;
}

bool calc(int num){
	int ans = 0;
	for(int i=0; i<cnt[s]; i++){
		mapp[s][i].val = num;
		mapp[s][i].fx -> val = num;
		mapp[s][i].fx -> cur = num;
	}
	for(int i=0; i<cnt[e]; i++){
		mapp[s][i].val = num;
		mapp[s][i].cur = num;
		mapp[s][i].fx -> val = num;
	}
	while(bfs()){
		ans += dfs(s, Inf);
	}
	return ans==n*num;
}

bool bfs(){
	queue<int> q;
	Edge tar;
	memset(depth, 0, sizeof(depth));
	memset(vis, 0, sizeof(vis));
	vis[s] = true;
	q.push(s);
	while(!q.empty()){
		cur = q.front(); q.pop();
		for(int i=0; i<cnt[cur]; i++){
			tar = mapp[cur][i];
			if((!vis[tar.to]) && tar.cur<tar.val){
				vis[tar.to] = true;
				q.push(tar.to);
				depth[tar.to] = depth[cur]+1;
			}
		}
	}
	return vis[t];
}

int dfs(int cur, int flow){
	if(cur==t || flow == 0) return flow;
	int out = 0, tmp;
	Edge tar;
	for(int i=0; i<cnt[cur]; i++){
		tar = mapp[cur][i];
		if(depth[tar.to]==depth[cur]+1 && tar.cur<tar.val){
			tmp = dfs(tar.to, min(flow, tar.val-tar.cur));
			flow -= tmp;
			out += tmp;
			if(flow == 0) break;
		}
	}
	if(out==0) depth[cur] = 0;
	return out;
}
