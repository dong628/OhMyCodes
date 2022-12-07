#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>

const int Maxn = 55;
std::vector <int> rch[Maxn][Maxn], mapp[Maxn];
int dpm[Maxn], n, m, u, v, vrch[Maxn][Maxn][Maxn], mpn[Maxn][Maxn];

int main(){
	freopen("data.in", "r", stdin);

	memset(mpn, 0x3f, sizeof(mpn));
	scanf("%d %d", &n, &m);
	for(int i=0; i<m; i++){
		scanf("%d %d", &u, &v);
		mapp[u].push_back(v);
		mpn[u][v] = 1;
	}

	for(int i=1; i<=n; i++){
		for(int j=0; j<mapp[i].size(); j++){
			rch[i][0].push_back(mapp[i][j]);
		}
	}

	for(int i=1; i<=32; i++){
		for(int j=1; j<=n; j++){
			for(int k=0; k<rch[j][i-1].size(); k++){
				for(int l=0; l<rch[rch[j][i-1][k]][i-1].size(); l++){
					if(mpn[j][rch[rch[j][i-1][k]][i-1][l]] != 1){
						rch[j][i].push_back(rch[rch[j][i-1][k]][i-1][l]);
						mpn[j][rch[rch[j][i-1][k]][i-1][l]] = 1;
					}
				}
			}
		}
	}

	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				if(mpn[i][k]+mpn[k][j] < mpn[i][j]){
					mpn[i][j] = mpn[i][k]+mpn[k][j];
				}
			}
		}
	}

	printf("%d", mpn[1][n]);

	return 0;
}
