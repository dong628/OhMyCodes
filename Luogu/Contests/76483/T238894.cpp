#include <cstdio>
#include <iostream>

const int Maxn = 1005;
int t[Maxn][Maxn], ans[Maxn][Maxn];

int main(){
	freopen("data.in", "r", stdin);

	char opt;
	int n, m, curx, cury;
	scanf("%d %d %d %d\n", &n, &m, &cury, &curx);
	while(m--){
		opt = getchar();
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				t[i][j]++;
			}
		}
		t[curx][cury] = 0;
		switch(opt){
			case 'N': curx++; break;
			case 'S': curx--; break;
			case 'W': cury--; break;
			case 'E': cury++; break;
		}
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				ans[i][j] += t[i][j];
			}
		}
	}
	for(int i=n; i>=1; i--){
		for(int j=1; j<=n; j++){
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}

	return 0;
}
