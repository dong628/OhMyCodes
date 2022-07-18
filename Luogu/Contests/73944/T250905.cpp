#include <cstdio>
#include <iostream>
#include <cstring>

const int Maxn = 105, Maxx = 105;
int ans, n, m, op, l, r, x;
char xz1, xz2;
bool num[Maxn][Maxx], tmp[Maxx];

int main(){
	freopen("data.in", "r", stdin);

	scanf("%c%c\n", &xz1, &xz2);
	scanf("%d %d", &n, &m);
	for(int csm=0; csm<m; csm++){
		scanf("%d %d %d", &op, &l, &r);
		if(op == 1){
			scanf("%d", &x);
			for(int i=l; i<=r; i++){
				num[i][x] = true;
			}
		}
		if(op == 2){
			ans = 0;
			memset(tmp, 0, sizeof(tmp));
			for(int i=l; i<=r; i++){
				for(int j=0; j<Maxx; j++){
					if(num[i][j]) tmp[j] = true;
				}
			}
			for(int j=0; j<Maxx; j++){
				if(tmp[j]) ans += j;
			}
			printf("%d\n", ans);
		}
	}

	return 0;
}
