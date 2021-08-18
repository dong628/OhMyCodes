#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>

const int Maxn=205, Maxt=1e5+5, Inf=0x3f3f3f3f;
//const int Maxn=25, Maxt=1e2+5, Inf=0x3f3f3f3f;
int n, m, t, timn[Maxn], cnt[Maxt], mapp[Maxn][Maxn], dist[Maxn][Maxn], x, y, w, q;
int min(int xx, int yy) { return xx<yy?xx:yy; }
std::vector<int> tim[Maxt];
void floyd(int);

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++){
		scanf("%d", &t);
		timn[i] = t;
		tim[t].push_back(i);
		cnt[t]++;
	}
	memset(mapp, 0x3f, sizeof(mapp));
	for(int i=1; i<=m; i++){
		scanf("%d %d %d", &x, &y, &w);
		mapp[x][y] = min(w, mapp[x][y]);
		mapp[y][x] = min(w, mapp[y][x]);
	}
	memset(dist, 0x3f, sizeof(dist));
	for(int i=0; i<n; i++) mapp[i][i] = 0;
	scanf("%d", &q);
	int tn=0;
	floyd(0);
	for(int cs=1; cs<=q; cs++){
		scanf("%d %d %d", &x, &y, &t);
		while(tn<t){
			tn++;
			floyd(tn);
		}
		if(mapp[x][y]==Inf || timn[x]>t || timn[y]>t){
			printf("-1\n");
		}
		else{
			printf("%d\n", mapp[x][y]);
		}
	}

	return 0;
}

void floyd(int tm){
	int node;
	for(int i=0; i<cnt[tm]; i++){
		node = tim[tm][i];
		for(int j=0; j<n; j++){
			for(int k=0; k<n; k++){
				if(mapp[j][k]>mapp[j][node]+mapp[node][k]){
					mapp[j][k]=mapp[j][node]+mapp[node][k];
				}
			}
		}
	}
}
