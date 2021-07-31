#include <cstdio>
#include <iostream>

const int Maxn=25;
long long a[Maxn][Maxn];
long long max(long long x, long long y) { return x>y?x:y; }

int main(){
	int n, m, x, y;
	scanf("%d %d %d %d", &n, &m, &x, &y);
	n++; m++; x++; y++;
	a[1][1]=1;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++)
			if((i-x)*(j-y)==2 || (i-x)*(j-y)==-2 || (i==x && j==y))
				a[i][j]=0;
			else a[i][j] = max(a[i][j], a[i-1][j]+a[i][j-1]);
	}
	printf("%lld", a[n][m]);

	return 0;
}
