#include <cstdio>
#include <iostream>

const int Max=105;
int n, m, x, y, mapp[Max][Max][Max], cnt;
int ways[5][3]={{1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};
void dfs(int, int, int);

int main(){
//	freopen("data.in", "r", stdin);

	scanf("%d %d", &n, &m);
	for(int t=0; t<n; t++){
		for(int i=0; i<m; i++){
			for(int j=0; j<m; j++){
				scanf("%d", &mapp[t][i][j]);
			}
		}
	}
	scanf("%d %d", &x, &y);
	if(mapp[0][x-1][y-1]==1){
		printf("0");
	}
	else{
		dfs(0, x-1, y-1);
		printf("%d", cnt);
	}

	return 0;
}

void dfs(int z, int x, int y){
	cnt++;
	mapp[z][x][y]=1;
	int xw, yw, zw;
	for(int i=0; i<5; i++){
		xw=x+ways[i][1], yw=y+ways[i][2], zw=z+ways[i][0];
		if(xw<m && xw>=0 && yw<m && yw>=0 && zw<n && zw>=0 && mapp[zw][xw][yw]==0){
			dfs(zw, xw, yw);
		}
	}
}
