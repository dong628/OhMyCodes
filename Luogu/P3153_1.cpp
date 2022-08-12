#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
using std::min, std::queue;

const int Maxn = 355, Inf = 0x7fffffff;
//const int Maxn = 50, Inf = 0x7fffffff;
struct Edge{
	int to, val, cur;
	Edge *fx;
} mapp[Maxn][Maxn];
Edge *e1[Maxn*Maxn], *ek[Maxn], *einf[Maxn];
int n, k, s, t, cnt[Maxn], depth[Maxn], c1, cinf, ck;
bool vis[Maxn];
bool calc(int), bfs(void);
void input(void);
Edge* addedge(int, int, int);
int dfs(int, int);

int main(){
	freopen("data.in", "r", stdin);

	input();
	int l = 0, r = n, mid;
	while(l<r){
		mid = (l+r+1)>>1;
		if(calc(mid)) l = mid;
		else r = mid-1;
	}
	printf("%d\n", l);

	return 0;
}

void input(void){
	char ch;
	scanf("%d %d\n", &n, &k);
	s = 0; t = 1;
	for(int i=1; i<=n; i++){
		addedge(s, 3*i, 0);
		einf[cinf++] = addedge(3*i, 3*i+1, Inf);
		ek[ck++] = addedge(3*i, 3*i+2, k);
	}
	for(int j=n+1; j<=2*n; j++){
		addedge(3*j, t, 0);
		einf[cinf++] = addedge(3*j+1, 3*j, Inf);
		ek[ck++] = addedge(3*j+2, 3*j, k);
	}
	for(int i=1; i<=n; i++){
		for(int j=n+1; j<=2*n; j++){
			scanf("%c", &ch);
			if(ch == 'Y'){
				e1[c1++] = addedge(3*i+1, 3*j+1, 1);
			}
			else{
				e1[c1++] = addedge(3*i+2, 3*j+2, 1);
			}
		}
		scanf("\n");
	}
}

Edge* addedge(int from, int to, int val){
	Edge e, ne;
	e.to = to; e.val = val; e.cur = 0; e.fx = &mapp[e.to][cnt[e.to]];
	ne.to = from; ne.val = val; ne.cur = val; ne.fx = &mapp[ne.to][cnt[ne.to]];
	mapp[from][cnt[from]++] = e;
	mapp[to][cnt[to]++] = ne;
	return &mapp[from][cnt[from]-1];
}

bool calc(int num){
	int ans = 0;
	for(int i=0; i<cnt[s]; i++){
		mapp[s][i].val = num;
		mapp[s][i].cur = 0;
		mapp[s][i].fx -> val = num;
		mapp[s][i].fx -> cur = num;
	}
	for(int i=0; i<cnt[t]; i++){
		mapp[t][i].val = num;
		mapp[t][i].cur = num;
		mapp[t][i].fx -> val = num;
		mapp[t][i].fx -> cur = 0;
	}
	for(int i=0; i<c1; i++){
		e1[i] -> cur = 0;
		e1[i] -> fx -> cur = 1;
	}
	for(int i=0; i<ck; i++){
		ek[i] -> cur = 0;
		ek[i] -> fx -> cur = k;
	}
	for(int i=0; i<ck; i++){
		einf[i] -> cur = 0;
		einf[i] -> fx -> cur = Inf;
	}
/*
	for(int i=3; i<=3*n; i+=3){
		for(int j=0; j<cnt[i+1]; j++){
			if(mapp[i+1][j].to%3==1 && mapp[i+1][j].to!=1){
				mapp[i+1][j].cur = 0;
				mapp[i+1][j].fx -> cur = 1;
			}
			if(mapp[i+1][j].to%3==2){
				mapp[i+1][j].cur = 0;
				mapp[i+1][j].fx -> cur = 1;
			}
		}
		for(int j=0; j<cnt[i+2]; j++){
			if(mapp[i+2][j].to%3==1 && mapp[i+2][j].to!=1){
				mapp[i+2][j].cur = 0;
				mapp[i+2][j].fx -> cur = 1;
			}
			if(mapp[i+2][j].to%3==2){
				mapp[i+2][j].cur = 0;
				mapp[i+2][j].fx -> cur = 1;
			}
		}
	}
*/
	while(bfs()){
		ans += dfs(s, Inf);
	}
	return ans==n*num;
}

bool bfs(){
	int cur;
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
			mapp[cur][i].cur += tmp;
			tar.fx -> cur -= tmp;
			flow -= tmp;
			out += tmp;
			if(flow == 0) break;
		}
	}
	if(out==0) depth[cur] = 0;
	return out;
}
