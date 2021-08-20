#include <cstdio>
#include <cstring>
#include <iostream>

const int Maxn=305, Inf=0x3f3f3f3f;
int n, m, t, mapp[Maxn][Maxn], ai, bi, si, ei, hi;
int max(int xx, int yy) { return xx>yy?xx:yy; }
int min(int xx, int yy) { return xx<yy?xx:yy; }

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d %d %d", &n, &m, &t);
	memset(mapp, 0x3f, sizeof(mapp));
	for(int i=1; i<=n; i++) mapp[i][i] = 0;
	for(int i=1; i<=m; i++){
		scanf("%d %d %d", &si, &ei, &hi);
		mapp[si][ei] = min(mapp[si][ei], hi);
	}
	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				mapp[i][j] = min(max(mapp[i][k], mapp[k][j]), mapp[i][j]);
			}
		}
	}
	for(int i=1; i<=t; i++){
		scanf("%d %d", &ai, &bi);
		if(mapp[ai][bi]!=Inf){
			printf("%d\n", mapp[ai][bi]);
		}
		else printf("-1\n");
	}

	return 0;
}
