#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
using std::queue, std::min;

//const int Maxn = 4e1+5, Maxm = 1e2+5, Inf = 0x7fffffff;
const int Maxn = 1e5+5, Maxm = 2e5+5, Inf = 0x7fffffff;
struct Edge{
	int to, cur, val;
	Edge *nxt, *fx;
} eds[Maxm], endp, head[Maxn], *end[Maxn];
int cnt = 0, s, t, depth[Maxn];
bool vis[Maxn];
void init(void), addedge(int, int, int);
bool bfs(void);
int dfs(int, int);

int main(){
	freopen("data.in", "r", stdin);

	int ans = 0;
	init();
	while(bfs()){
		ans += dfs(s, Inf);
	}
	printf("%d", ans);

	return 0;
}

void init(void){
	int nb, nl, na, cntp, ml, ma, x, y;
	endp.to = -1;
	scanf("%d %d %d", &nb, &nl, &na);
	cntp = 2*nb+nl+na+2;
	s = 0; t = cntp-1;
	for(int i=0; i<=cntp; i++){
		end[i] = &head[i];
		head[i].nxt = &endp;
	}
	for(int i=1; i<=nl; i++){
		addedge(s, i, 1);
	}
	scanf("%d", &ml);
	for(int i=0; i<ml; i++){
		scanf("%d %d", &x, &y);
		addedge(y, x+nl, 1);
	}
	for(int i=1; i<=nb; i++){
		addedge(i+nl, i+nl+nb, 1);
	}
	scanf("%d", &ma);
	for(int i=0; i<ml; i++){
		scanf("%d %d", &x, &y);
		addedge(nb+nl+x, nb*2+nl+y, 1);
	}
	for(int i=1; i<=na; i++){
		addedge(nb*2+nl+i, t, 1);
	}
}

void addedge(int from, int to, int val){
	end[from] -> nxt = &eds[cnt];
	end[from] = &eds[cnt];
	eds[cnt].val = val; eds[cnt].cur = 0; eds[cnt].to = to;
	eds[cnt].fx = &eds[cnt+1]; eds[cnt].nxt = &endp; cnt++;
	end[to] -> nxt = &eds[cnt];
	end[to] = &eds[cnt];
	eds[cnt].val = val; eds[cnt].cur = val; eds[cnt].to = from;
	eds[cnt].fx = &eds[cnt-1]; eds[cnt].nxt = &endp; cnt++;
}

bool bfs(void){
	memset(depth, 0, sizeof(depth));
	memset(vis, 0, sizeof(vis));
	int cur;
	queue<int> q;
	q.push(s);
	vis[s] = true;
	while(!q.empty()){
		cur = q.front(); q.pop();
		for(Edge *e=head[cur].nxt; e->to!=-1; e=e->nxt){
			if(!vis[e->to] && e->val>e->cur){
				depth[e->to] = depth[cur]+1;
				vis[e->to] = true;
				q.push(e->to);
			}
		}
	}
	return vis[t];
}

int dfs(int cur, int flow){
	if(cur==t || flow==0) return flow;
	int tmp, out = 0;
	for(Edge *e=head[cur].nxt; e->to!=-1; e=e->nxt){
		if(depth[e->to]==depth[cur]+1 && e->cur<e->val){
			tmp = dfs(e->to, min(flow, e->val-e->cur));
			flow -= tmp;
			out += tmp;
			e -> cur += tmp; 
			e -> fx -> cur -= tmp;
			if(flow == 0) break;
		}
	}
	if(out == 0) depth[cur] = 0;
	return out;
}
