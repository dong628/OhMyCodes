#include <cstdio>
#include <iostream>

const int Maxn=65;
int n, m, vis[Maxn][Maxn], kil[Maxn][2], cnt, ans, cnta;
char mapp[Maxn][Maxn];
bool viss[Maxn][Maxn];
void dfs(int);
void kd(int, int, int);

int main(){
	freopen("cmdo.in", "r", stdin);
	freopen("cmdo.out", "w", stdout);

	scanf("%d %d\n", &n, &m);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			mapp[i][j] = getchar();
			if(mapp[i][j]!='.' && mapp[i][j]!='#') cnta++;
		}
		getchar();
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			kd(i, j, 1);
/*			tmpi = i; tmpj = j;
			if(mapp[i][j]=='^'){
				for(int x=tmpi-1; x>=1; x--){
					if(mapp[x][tmpj]=='#') break;
					vis[x][tmpj]++;
				}
			} 
			else if(mapp[i][j]=='v'){
				for(int x=tmpi+1; x<=n; x++){
					if(mapp[x][tmpj]=='#') break;
					vis[x][tmpj]++;
				}
			}
			else if(mapp[i][j]=='<'){
				for(int x=tmpj-1; x>=1; x--){
					if(mapp[tmpi][x]=='#') break;
					vis[tmpi][x]++;
				}
			}
			else if(mapp[i][j]=='>'){
				for(int x=tmpj+1; x<=m; x++){
					if(mapp[tmpi][x]=='#') break;
					vis[tmpi][x]++;
				}
			}*/
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(mapp[i][j]!='#' && mapp[i][j]!='.' && vis[i][j]==0){
				kil[cnt][0] = i; kil[cnt][1] = j;
				cnt++;
			}
		}
	}
	if(cnt==0){
		printf("Impossible\n");
		return 0;
	}
	else{
//		for(int i=0; i<cnt; i++){
//			head=0; tail=0;
/*			for(int j=0; j<cnt; j++){
				if(j!=i){
					queue[tail][0]=kil[j][0];
					queue[tail][1]=kil[j][1];
					tail++;
				}
			}*/
//			viss[kil[i][0]][kil[i][1]] = true;
			dfs(cnta);
//			viss[kil[i][0]][kil[i][1]] = false;
//		}
	}
	if(ans!=0) printf("%d\n", ans);
	else printf("Impossible\n");

	return 0;
}

void dfs(int rem){
	if(rem==0){
		ans++; return;
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if((!viss[i][j]) && mapp[i][j]!='#' && mapp[i][j]!='.' && vis[i][j]==0){
				viss[i][j] = true;
				kd(i, j, -1);
				dfs(rem-1);
				kd(i, j, 1);
				viss[i][j] = false;
			}
		}
	}
}

void kd(int xx, int yy, int mo){
	int tmpi = xx, tmpj = yy;
	if(mapp[xx][yy]=='^'){
		for(int x=tmpi-1; x>=1; x--){
			if(mapp[x][tmpj]=='#') break;
			vis[x][tmpj]+=mo;
		}
	} 
	else if(mapp[xx][yy]=='v'){
		for(int x=tmpi+1; x<=n; x++){
			if(mapp[x][tmpj]=='#') break;
			vis[x][tmpj]+=mo;
		}
	}
	else if(mapp[xx][yy]=='<'){
		for(int x=tmpj-1; x>=1; x--){
			if(mapp[tmpi][x]=='#') break;
			vis[tmpi][x]+=mo;
		}
	}
	else if(mapp[xx][yy]=='>'){
		for(int x=tmpj+1; x<=m; x++){
			if(mapp[tmpi][x]=='#') break;
			vis[tmpi][x]+=mo;
		}
	}
}
