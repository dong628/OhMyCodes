#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
using std::min;
using std::max;

const int Maxn=5e5+5, Maxlog=log(Maxn)/log(2)+5;
int stmin[Maxn][Maxlog], h[Maxn], a, b, maxx, minn, n, q;
void StPrework(void);
void StFind(int, int);

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d %d", &n, &q);
	for(int i=1; i<=n; i++){
		scanf("%d", &h[i]);
	}
	StPrework();
	for(int i=1; i<=q; i++){
		scanf("%d %d", &a, &b);
		StFind(a, b);
	}

	return 0;
}

void StPrework(void){
	memset(stmin, 0x3f, sizeof(stmin));

	int logg = log(n)/log(2)+1;
	for(int i=1; i<=n; i++){
		stmin[i][0]=h[i];
	}
	for(int j=1; j<=logg; j++){
		for(int i=1; i<=n; i++){
			stmin[i][j] = min(stmin[i][j-1], stmin[i+(1<<(j-1))][j-1]);
		}
	}
}

void StFind(int l, int r){
	int logg = log(r-l+1)/log(2);
	minn = min(stmin[l][logg], stmin[r-(1<<logg)+1][logg]);
	printf("%d ", minn);
}
