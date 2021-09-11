#include <cstdio>
#include <iostream>
#include <vector>

const int Maxn = 1000;
std::vector<int> mappl[Maxn], mappr[Maxn];
int n, m, e, u, v, cntl[Maxn], cntr[Maxn], matchr[Maxn], ans;
bool vis[Maxn], mapv[Maxn][Maxn];
bool binmatch(int);

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d %d %d", &n, &m, &e);
	for(int i=1; i<=e; i++){
		scanf("%d %d", &u, &v);
		if(mapv[u][v]) continue;
		mapv[u][v] = true;
		mappl[u].push_back(v);
		cntl[u]++;
//		mappr[v].push_back(u);
//		cntr[v]++;
	}

	for(int i=1; i<=n; i++){
		if(binmatch(i)) ans++;
	}
	printf("%d", ans);

	return 0;
}

bool binmatch(int point){
	int mt;
	for(int i=0; i<cntl[point]; i++){
		if(!vis[mappl[point][i]]){
			mt = matchr[mappl[point][i]];
			if(mt != 0){
				vis[mappl[point][i]] = true;
				if(binmatch(mt)){
					vis[mappl[point][i]] = false;
					matchr[mappl[point][i]] = point;
					return true;
				}
				else{
					vis[mappl[point][i]] = false;
				}
			}
			else{
				matchr[mappl[point][i]] = point;
				return true;
			}
		}
	}
	return false;
}
