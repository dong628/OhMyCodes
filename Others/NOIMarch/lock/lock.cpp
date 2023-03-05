#include <iostream>
#include <cstdio>

const int Maxn = 2e5+5, Maxk = 5, Inf = 0x3f3f3f3f;
//const int Maxn = 3e4+5, Maxk = 5;
int book[Maxn], t, k, n, a[Maxk][Maxn], ans;
void dfs(int);

int main(){
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);

	scanf("%d %d", &t, &k);
	while(t --> 0){
		ans = Inf;
		scanf("%d", &n);
		for(int i=1; i<=k; i++){
			for(int j=1; j<=n; j++){
				scanf("%d", &a[i][j]);
			}
		}

		dfs(1);
		printf("%d\n", ans);
	}

	return 0;
}

void dfs(int step){
	if(step == n+1){
		int maxx = 0, minn = Inf, maxc = 0;
		for(int i=1; i<=k; i++){
			minn = Inf; maxx = 0;
			for(int j=1; j<=n; j++){
				minn = minn < a[((book[j]+i)%k)+1][j] ? minn : a[((book[j]+i)%k)+1][j];
				maxx = maxx > a[((book[j]+i)%k)+1][j] ? maxx : a[((book[j]+i)%k)+1][j];
			}
			maxc = maxc > maxx - minn ? maxc : maxx - minn;
		}
		ans = maxc < ans ? maxc : ans;
		return;
	}

	for(int i=0; i<k; i++){
		book[step] = i;
		dfs(step+1);
	}
}
