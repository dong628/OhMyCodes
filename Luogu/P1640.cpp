#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
using std::queue, std::min, std::vector;

//const int Inf = 0x7fffffff, Maxn = 1e1+5;
const int Inf = 0x7fffffff, Maxn = 1e6+5;
struct Edge{
	int val, cur, to, fx;
};
vector <Edge> mapp[2*Maxn];
int n, s, t, cnt[2*Maxn], depth[2*Maxn];
bool vis[2*Maxn];
bool bfs(void);
int dfs(int, int);
void addedge(int, int, int);
bool calc(int);

int main(){
	freopen("data.in", "r", stdin);

	int a, b;
	scanf("%d", &n);
	s = 0; t = 2*n+1;
	for(int i=1; i<=n; i++){
		addedge(s, i, 1);
		addedge(i+n, t, 1);
	}
	for(int i=1; i<=n; i++){
		scanf("%d %d", &a, &b);
		if(a <= n) addedge(i, a+n, 1);
		if(b <= n) addedge(i, b+n, 1);
	}
	int l = 0, r = n, mid;
	while(l < r){
		mid = (l+r+1)>>1;
		if(calc(mid)) l = mid;
		else r = mid-1;
	}
	printf("%d", l);

	return 0;
}

bool calc(int x){
	int ans = 0;
	for(int i=x+1; i<=n; i++){
		mapp[i+n][0].cur = 1;
		mapp[t][i-1].cur = 0;
	}
	while(bfs()){
		ans += dfs(s, Inf);
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<cnt[i]; j++){
			mapp[i][j].cur = 0;
			mapp[mapp[i][j].to][mapp[i][j].fx].cur = 1;
		}
	}
	for(int i=0; i<=n; i++){
		mapp[s][i].cur = 0;
		mapp[mapp[s][i].to][mapp[s][i].fx].cur = 1;
		mapp[t][i].cur = 1;
		mapp[mapp[t][i].to][mapp[t][i].fx].cur = 0;
	}
	if(ans == x) return true;
	else return false;
}

bool bfs(void){
	int cur;
	Edge tar;
	queue <int> q;
	memset(vis, 0, sizeof(vis));
	memset(depth, 0, sizeof(depth));
	q.push(s);
	vis[s] = true;
	while(!q.empty()){
		cur = q.front(); q.pop();
		for(int i=0; i<cnt[cur]; i++){
			tar = mapp[cur][i];
			if((!vis[tar.to]) && tar.cur<tar.val){
				vis[tar.to] = true;
				depth[tar.to] = depth[cur]+1;
				q.push(tar.to);
			}
		}
	}
	return vis[t];
}

int dfs(int cur, int flow){
	if(cur==t || flow==0) return flow;
	Edge tar;
	int out = 0, tmp;
	for(int i=0; i<cnt[cur]; i++){
		tar = mapp[cur][i];
		if(depth[tar.to] == depth[cur]+1 && tar.cur < tar.val){
			tmp = dfs(tar.to, min(flow, tar.val-tar.cur));
			mapp[tar.to][tar.fx].cur -= tmp;
			mapp[cur][i].cur += tmp;
			out += tmp;
			flow -= tmp;
			if(flow == 0) break;
		}
	}
	if(out == 0) depth[cur] = 0;
	return out;
}

void addedge(int st, int to, int val){
	Edge tst, tto;
	tst.val = val; tto.val = val;
	tst.cur = 0; tto.cur = val;
	tst.to = to; tto.to = st;
	tst.fx = cnt[to]; tto.fx = cnt[st];
	mapp[st].push_back(tst);
	mapp[to].push_back(tto);
	cnt[st]++; cnt[to]++;
}
