#include <cstdio>
#include <algorithm>
#include <iostream>

const int Maxn = 1e4+5;
struct Quest{
	long long op, x, y;
} q[Maxn];
long long lsmp[Maxn];
int mapp[Maxn][Maxn];

int main(){
	freopen("data.in", "r", stdin);

	int n, m, cnt = 0;
	long long x, y;
	char op;
	scanf("%d\n", &n);
	for(int i=0; i<n; i++){
		scanf("%c", &op);
		if(op == 'a'){
			getchar(); getchar();
			scanf("%lld %lld\n", &x, &y);
			q[i].op = 0; q[i].x = x; q[i].y = y;
			lsmp[cnt++] = x; lsmp[cnt++] = y;
		}
		if(op == 'f'){
			getchar(); getchar(); getchar();
			scanf("%lld %lld\n", &x, &y);
			q[i].op = 1; q[i].x = x; q[i].y = y;
		}
		if(op == 'r'){
			getchar(); getchar(); getchar(); getchar(); getchar();
			scanf("%lld %lld\n", &x, &y);
			q[i].op = 2; q[i].x = x; q[i].y = y;
		}
	}
	std::sort(lsmp, lsmp+cnt);
	m = std::unique(lsmp, lsmp+cnt) - lsmp;
	bool flag;
	for(int i=0; i<n; i++){
		x = std::upper_bound(lsmp, lsmp+m, q[i].x)-lsmp-1;
		y = std::upper_bound(lsmp, lsmp+m, q[i].y)-lsmp-1;
		if(q[i].op == 0){
			mapp[x][y]++;
		}
		else if(q[i].op == 2){
			mapp[x][y]--;
		}
		else{
			flag = false;
			for(int j=x+1; j<=m; j++){
				for(int k=y+1; k<=m; k++){
					if(mapp[j][k] > 0){
						printf("%d %d\n", lsmp[j], lsmp[k]);
						flag = true;
						break;
					}
				}
				if(flag) break;
			}
			if(!flag) printf("-1\n");
		}
	}

	return 0;
}
