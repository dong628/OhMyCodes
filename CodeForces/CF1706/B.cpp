#include <cstdio>
#include <iostream>
#include <cstring>

const int Maxn = 1e2+5;
int cnt[Maxn], maxx, last[Maxn], lg[Maxn], fill[2][Maxn], n, t, ci;
bool enable[3][Maxn];

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d", &t);
	while(t--){
		memset(cnt, 0, sizeof(cnt));
		memset(last, 0, sizeof(last));
		memset(fill, 0, sizeof(fill));
		memset(lg, 0, sizeof(lg));
		memset(enable, 0, sizeof(enable));
		scanf("%d", &n);
		for(int i=0; i<n; i++){
			scanf("%d", &ci);
			if(i%2 == (last[ci]+1)%2)fill[i%2][ci]++;
			if(last[ci] == i-1){
				lg[ci]++;
			}
			else{
				if(lg[ci]>fill[(last[ci]+1)%2][ci]){
					fill[(last[ci]+1)%2][ci] = lg[ci];
					if(i%2 == (last[ci]+1)%2) fill[i%2][ci]++;
				}
				lg[ci] = 1;
			}
			last[ci] = i;
		}
		for(int i=1; i<=n; i++){
			maxx = 0;
			for(int j=0; j<2; j++){
				maxx = maxx>fill[j][i]?maxx:fill[j][i];
			}
			maxx = maxx>lg[i]?maxx:lg[i];
			printf("%d ", maxx);
		}
		printf("\n");
	}

	return 0;
}
