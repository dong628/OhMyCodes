#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int Maxn=1e5+5;
struct Node{
	int v, w;
}tmp;
typedef pair<int, int> pii;
void dijkstra(void);
priority_queue< pii, vector<pii>, greater<pii> > st; //first:dist[i] second:i;
vector<Node> mapp[Maxn];
int dist[Maxn], cnt[Maxn], n, m, s, ui, vi, wi;
bool vis[Maxn];


int main(){
	freopen("data.in", "r", stdin);

	scanf("%d %d %d", &n, &m, &s);
	for(int i=1; i<=m; i++){
		scanf("%d %d %d", &ui, &vi, &wi);
		tmp.v=vi; tmp.w=wi;
		mapp[ui].push_back(tmp);
		cnt[ui]++;
	}
	dijkstra();
	for(int i=1; i<=n; i++){
		if(dist[i] != 0x3f3f3f3f){
			printf("%d ", dist[i]);
		}
		else{
			printf("2147483647 ");
		}
	}

	return 0; 
}

void dijkstra(void){
	memset(dist, 0x3f, sizeof(dist));
	memset(vis, 0, sizeof(vis));
	dist[s] = 0;
	int x;
	st.push(make_pair(0, s));
	while(st.size()){
		x=st.top().second; st.pop();
		vis[x] = true;
		for(int i=0; i<cnt[x]; i++){
			if(!vis[mapp[x][i].v] && dist[mapp[x][i].v]>dist[x]+mapp[x][i].w){
				dist[mapp[x][i].v] = dist[x]+mapp[x][i].w;
//				vis[mapp[x][i].v] = true;
				st.push(make_pair(dist[mapp[x][i].v], mapp[x][i].v));
			}
		}
	}
}
