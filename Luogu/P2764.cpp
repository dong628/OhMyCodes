#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
using std::queue, std::min;

const int Inf = 0x7fffffff, Maxn = 35;
struct Edge{
	int to, cur, val;
	Edge *fx;
} mapp[Maxn][Maxn];
void addedge(int, int, int);
bool bfs(void);
int dfs(int, int);
int s, t, depth[Maxn], cnt[Maxn];
int ansi[Maxn], ansj[Maxn][Maxn], cnta[Maxn], fa[Maxn];
bool vis[Maxn];
int head(int a){
	if(fa[a] == a) return a;
	return head(fa[a]);
}
void merge(int a, int b){
	fa[head(a)] = head(b);
}

int main(){
	freopen("data.in", "r", stdin);

	int n, m, ans = 0, a, b;
	scanf("%d %d", &n, &m);
	s = 0; t = 2*n+1;
	for(int i=1; i<=n; i++){
		addedge(s, 2*i-1, 1);
		addedge(2*i, t, 1);
	}
	for(int i=0; i<m; i++){
		scanf("%d %d", &a, &b);
		addedge(2*a-1, 2*b, 1);
	}
	while(bfs()){
		ans += dfs(s, Inf);
	}
	for(int i=1; i<=n; i++){
		fa[i] = i;
	}
	for(int i=1; i<=n; i++){
		for(int j=0; j<cnt[2*i-1]; j++){
			if(mapp[2*i-1][j].cur == 1){
				merge(i, (mapp[i][j].to+1)/2);
			}
		}
	}
	for(int i=1; i<=n; i++){
		ansi[i] = head(i);
		ansj[ansi[i]][cnta[ansi[i]]++] = i;
	}
	for(int i=1; i<=n; i++){
		if(cnta[ansi[i]] == 0) continue;
		for(int j=0; j<cnta[ansi[i]]; j++){
			printf("%d ", ansj[i][j]);
		}
		printf("\n");
	}
	printf("%d", n-ans);

	return 0;
}

void addedge(int a, int b, int val){
	mapp[a][cnt[a]].to = b;
	mapp[b][cnt[b]].to = a;
	mapp[a][cnt[a]].val = val;
	mapp[b][cnt[b]].val = val;
	mapp[a][cnt[a]].cur = 0;
	mapp[b][cnt[b]].cur = val;
	mapp[a][cnt[a]].fx = &mapp[b][cnt[b]];
	mapp[b][cnt[b]].fx = &mapp[a][cnt[a]];
	cnt[a]++; cnt[b]++;
}

bool bfs(void){
	memset(depth, 0, sizeof(depth));
	memset(vis, 0, sizeof(vis));
	queue <int> q;
	int cur;
	q.push(s);
	vis[s] = true;
	while(!q.empty()){
		cur = q.front(); q.pop();
		for(int i=0; i<cnt[cur]; i++){
			if(mapp[cur][i].val > mapp[cur][i].cur && !vis[mapp[cur][i].to]){
				vis[mapp[cur][i].to] = true;
				q.push(mapp[cur][i].to);
				depth[mapp[cur][i].to] = depth[cur] + 1;
			}
		}
	}
	return vis[t];
}

int dfs(int cur, int flow){
	if(cur == t || flow == 0) return flow;
	int out = 0, tmp;
	for(int i=0; i<cnt[cur]; i++){
		if(mapp[cur][i].val > mapp[cur][i].cur && depth[mapp[cur][i].to] == depth[cur]+1){
			tmp = dfs(mapp[cur][i].to, min(flow, mapp[cur][i].val - mapp[cur][i].cur));
			mapp[cur][i].cur += tmp;
			mapp[cur][i].fx -> cur -= tmp;
			out += tmp;
			flow -= tmp;
			if(flow == 0) break;
		}
	}
	if(out == 0) depth[cur] = 0;
	return out;
}
