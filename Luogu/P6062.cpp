#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
using std::queue, std::min, std::vector;

const int Inf = 0x7fffffff, Maxn = 55;
struct Edge{
	int to, val, cur, fx;
};
vector <Edge> mapp[2*Maxn*Maxn];
int n, k, s, t, cnt[2*Maxn*Maxn], depth[2*Maxn*Maxn], cntx[Maxn], cnty[Maxn];
char ma[Maxn][Maxn];
bool vis[2*Maxn*Maxn];
bool bfs(void);
int dfs(int, int);
void addedge(int, int, int);

int main(){
	freopen("data.in", "r", stdin);

	int n, m, ans = 0, x, y;
	scanf("%d %d\n", &n, &m);
	s =  0; t = n*m*2+1;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			ma[i][j] = getchar();
			if(ma[i][j] == '.') continue;
			if(i>0 && ma[i-1][j]=='*'){
				y = cnty[j];
			}
			else{
				y = ++cnty[j];
			}
			if(j>0 && ma[i][j-1]=='*'){
				x = cntx[i];
			}
			else{
				x = ++cntx[i];
			}
			addedge(n*j+y, n*m+m*i+x, 1);
		}
		getchar();
	}
	for(int i=1; i<=n*m; i++){
		addedge(s, i, 1);
	}
	for(int i=n*m+1; i<=n*m*2; i++){
		addedge(i, t, 1);
	}
	while(bfs()){
		ans += dfs(s, Inf);
	}
	
	printf("%d", ans);

	return 0;
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
