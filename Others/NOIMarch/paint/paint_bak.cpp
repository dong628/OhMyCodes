#include <cstdio>
#include <iostream>
#include <cstring>

const int Maxn = 1e5+5;
int row[Maxn], rowt[Maxn], col[Maxn], colt[Maxn];

int main(){
	freopen("paint.in", "r", stdin);
	int t, n, m, q, opt, x, c;

	scanf("%d", &t);
	while(t --> 0){
		memset(row, 0, sizeof(row));
		memset(col, 0, sizeof(col));
		memset(rowt, 0, sizeof(rowt));
		memset(colt, 0, sizeof(colt));
		scanf("%d %d %d", &n, &m, &q);
		for(int i=1; i<=q; i++){
			scanf("%d %d %d", &opt, &x, &c);
			if(opt == 1){
				col[x] = c;
				colt[x] = i;
			}
			else{
				row[x] = c;
				rowt[x] = i;
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=1; j<=m; j++){
				if(rowt[i] > colt[j]) printf("%d ", row[i]);
				else printf("%d ", col[j]);
			}
			printf("\n");
		}
	}

	return 0;
}
