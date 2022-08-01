#include <cstdio>
#include <iostream>

typedef long long lol;
const int Maxn = 505, Mod = 998244353;
int n, m, mapp[Maxn][Maxn];
int dir[8][2] = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
int vis[Maxn][Maxn];
int cross[Maxn][Maxn];
lol blocks[Maxn][2];
lol qpow(lol, lol);
void dfs(int, int, int);

int main(){
	freopen("data.in", "r", stdin);

	char ch;
	int s, cntdot = 0;
	bool yk = false;
	scanf("%d %d %d\n", &s, &n, &m);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			ch = getchar();
			if(ch == '.'){
				mapp[i][j] = 0;
				cntdot++;
			}
			else{
				mapp[i][j] = 1;
			}
		}
		getchar();
	}
	if(s==3){
		lol ans = qpow(2, cntdot)*2;
		ans %= Mod;
		printf("%lld", ans);
		return 0;
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(mapp[i][j] == 0){
				mapp[i][j] = 2;
				for(int k=0; k<8; k++){
					if(mapp[i+dir[k][0]][j+dir[k][1]] == 1){
					 	mapp[i][j] = 0;
						break;
					}
				}
			}
		}
	}
	for(int i=0; i<=n+1; i++){
		mapp[i][0] = -1;
		mapp[i][m+1] = -1;
	}
	for(int i=0; i<=m+1; i++){
		mapp[0][i] = -1;
		mapp[n+1][i] = -1;
	}

	int id = 1;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if((vis[i][j]==0) && mapp[i][j] == 2){
				dfs(i, j, id);
				id++;
			}
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if((vis[i][j]==0) && mapp[i][j] == 0){
				dfs(i, j, id);
				id++;
			}
		}
	}

/*
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			printf("%d ", vis[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			printf("%d ", cross[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for(int i=1; i<id; i++){
		printf("%d %d %lld\n", blocks[i][0], blocks[i][1], qpow(2, blocks[i][1]));
	}
	printf("\n");
*/
	
	

/*
	lol sum = 1, ans = 0, tot = 0;

	for(int i=1; i<id; i++){
		tot += blocks[i][1];
	}
	ans += qpow(2, tot);
	for(int i=1; i<id; i++){
		if(blocks[i][0] != 0) sum *= qpow(2, tot-blocks[i][1]);
		sum %= Mod;
	}
	for(int i=1; i<id; i++){
		for(int j=1; j<id; j++){
			if(cross[i][j]!=0){
				ans -= qpow(2, tot-)
			}
		}
	}
*/

	for(int i=1; i<id; i++){
		ans = qpow(2, blocks[i][1]);
		if(blocks[i][0] != 0)
			ans++;
		sum *= ans;
		sum %= Mod;
	}
	sum *= 2; sum %= Mod;

	printf("%lld", sum);

	return 0;
}

void dfs(int x, int y, int block){
	vis[x][y] = block;
	int curx, cury;
	if(mapp[x][y] == 0){
		blocks[block][1]++;
		return;
	}
	blocks[block][0]++;
	for(int i=0; i<8; i++){
		curx = x+dir[i][0]; cury = y+dir[i][1];
		if((vis[curx][cury]==0) && (mapp[curx][cury] == 0 || mapp[curx][cury] == 2)){
			dfs(curx, cury, block);
		}
		else if((vis[curx][cury]!=0) && mapp[curx][cury]==0 && vis[curx][cury]!=block){
			cross[block][vis[curx][cury]]++;
			cross[vis[curx][cury]][block]++;
			dfs(curx, cury, block);
		}
	}
}

lol qpow(lol x, lol y){
	lol ans = 1, base = x;
	while(y){
		if(y&1) ans *= base;
		ans %= Mod;
		base *= base;
		base %= Mod;
		y >>= 1;
	}
	return ans;
}
