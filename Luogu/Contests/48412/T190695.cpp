#include <cstdio>
#include <iostream>

const int Maxn=205;
void dfs(int, int);
bool vis[Maxn][Maxn];
int cnt, n, m, maxx, mapp[Maxn][Maxn], mt[Maxn*Maxn][2];
char ch;

int main(){
//	freopen("data.in", "r", stdin);

	scanf("%d %d\n", &n, &m);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			scanf("%c", &ch);
			if(ch=='.'){
				mapp[i][j]=0;
				mt[cnt][0] = i;
				mt[cnt][1] = j;
				cnt++;
			}
			else if(ch=='#') mapp[i][j] = 1;
			else mapp[i][j] = -1;
		}
		scanf("\n");
	}
	dfs(0, 0);
	printf("%d", maxx);
/*	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			dp[i][j] = dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
			if(mapp[i][j]==0 && ){
				dp[]
			}
		}
	}*/

	return 0;
}

void dfs(int step, int cho){
	if(step == cnt){
		maxx=maxx>cho?maxx:cho;
		return;
	}
	dfs(step+1, cho);
	int xx = mt[step][0], yy=mt[step][1];
	if(!vis[xx][yy]){
		for(int i=xx-1; i>0; i--){
			if(mapp[i][yy]==1) break;
			vis[i][yy]=true;
		}
		for(int i=xx; i<=n; i++){
			if(mapp[i][yy]==1) break;
			vis[i][yy]=true;
		}
		for(int i=yy-1; i>0; i--){
			if(mapp[xx][i]==1) break;
			vis[xx][i]=true;
		}
		for(int i=yy; i<=m; i++){
			if(mapp[xx][i]==1) break;
			vis[xx][i]=true;
		}

		dfs(step+1, cho+1);

		for(int i=xx-1; i>0; i--){
			if(mapp[i][yy]==1) break;
			vis[i][yy]=false;
		}
		for(int i=xx; i<=n; i++){
			if(mapp[i][yy]==1) break;
			vis[i][yy]=false;
		}
		for(int i=yy-1; i>0; i--){
			if(mapp[xx][i]==1) break;
			vis[xx][i]=false;
		}
		for(int i=yy; i<=m; i++){
			if(mapp[xx][i]==1) break;
			vis[xx][i]=false;
		}
	}
}
