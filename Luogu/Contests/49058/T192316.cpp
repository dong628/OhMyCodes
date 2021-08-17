#include <cstdio>
#include <iostream>

const int Maxn=205;
int n, m, mapp[Maxn][Maxn], dp[Maxn*2][Maxn][Maxn], dp1[Maxn*2][Maxn][Maxn];
int max(int xx, int yy) { return xx>yy?xx:yy; }
int min(int xx, int yy) { return xx<yy?xx:yy; }
int ju(int, int, int, int);
int ju1(int, int, int, int); bool judge(int);
int confrim(int);

int main(){
	freopen("data.in", "r", stdin);

	int l=0x7fffffff, r=0, mid;
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			scanf("%d", &mapp[i][j]);
			l = l<mapp[i][j]?l:mapp[i][j];
			r = r>mapp[i][j]?r:mapp[i][j];
		}
	}
//	if((2*(n+m)-4)&1){
		while(l<r){
			mid = (l+r+1)>>1;
//			if(dp[n+m-3][n][n-1]>dp1[n+m-3][n][n-1]){
			if(judge(mid)){
				l=mid;
			}
			else r=mid-1;
		}
		printf("%d", l);
	//}
/*	else{
		while(l<r){
			mid = (l+r)>>1;
			judge(mid);
			if(dp[n+m-3][n][n-1]>dp1[n+m-3][n][n-1]){
				l=mid+1;
			}
			else if(dp[n+m-3][n][n-1]<dp1[n+m-3][n][n-1]) r=mid;
			else {
				printf("%d", confrim(mid));
				return 0;
			}
		}
	}*/
//	printf("%d", l);

	return 0;
}

bool judge(int num){
	dp[0][1][1]=0;
	for(int step=1; step<=(n+m)-3; step++){
		for(int i=max(1, step-m+2); i<=min(n, step+1); i++){
			for(int j=max(1, step-m+2); j<=min(n, step+1); j++){
				if(i!=j){
					dp[step][i][j] = max(max(max(dp[step-1][i-1][j], dp[step-1][i][j-1]), dp[step-1][i][j]), dp[step-1][i-1][j-1]) + ju(step, num, i, j);
//					dp1[step][i][j] = max(max(max(dp1[step-1][i-1][j], dp1[step-1][i][j-1]), dp1[step-1][i][j]), dp1[step-1][i-1][j-1]) + ju1(step, num, i, j);
				}
			}
		}
	}
//	if(mapp[1][1]>=num)
//		dp[n+m-3][n][n-1]++;
	if(mapp[n][m]>=num)
		dp[n+m-3][n][n-1]++;
/*	if(mapp[1][1]<num)
		dp1[n+m-3][n][n-1]++;
	if(mapp[n][m]<num)
		dp1[n+m-3][n][n-1]++;
*/
/*	for(int step=1; step<=n+m-3; step++){
		printf("step=%d\n", step);
		for(int i=1; i<=n; i++){
			for(int j=1; j<=m; j++){
				printf("%d ", dp[step][i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}*/
//	return dp[n+m-3][n][n-1];
	if(dp[n+m-3][n][n-1]>=(2*(n+m)-4)/2){
		return true;
	}
	return false;
}

int ju(int step, int num, int i, int j){
	int xo=i, xt=j, ans=0;
	int yo=step-i+2, yt=step-j+2;
	if(mapp[xo][yo]>=num) ans++;
	if(mapp[xt][yt]>=num) ans++;
	return ans;
}
int ju1(int step, int num, int i, int j){
	int xo=i, xt=j, ans=0;
	int yo=step-i+2, yt=step-j+2;
	if(mapp[xo][yo]<num) ans++;
	if(mapp[xt][yt]<num) ans++;
	return ans;
}

int confrim(int num){
	int less=0x7fffffff, more=0x7fffffff;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(mapp[i][j]>=num && mapp[i][j]-num<=more) more=mapp[i][j]-num;
			if(mapp[i][j]<=num && mapp[i][j]-num<=less) less=mapp[i][j]-num;
		}
	}
	return (more-less)+num;
}
