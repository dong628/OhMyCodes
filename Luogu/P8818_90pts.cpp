#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using std::min;
using std::max;

const int Maxn = 2e5+5, Maxst = 20, Inf = 0x7fffffff;
int n, m, q;
int staneg[Maxn][Maxst], stapos[Maxn][Maxst];
int stamax[Maxn][Maxst], stbmax[Maxn][Maxst];
int stamin[Maxn][Maxst], stbmin[Maxn][Maxst], a[Maxn], b[Maxn];
void prework(void);
int amax(int, int), bmax(int, int), amin(int, int), bmin(int, int), posmin(int, int), negmax(int, int);

int main(){
//	freopen("game.in", "r", stdin);
	freopen("data.in", "r", stdin);
//	freopen("game.out", "w", stdout);
	
	scanf("%d %d %d", &n, &m, &q);
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
	}
	for(int i=1; i<=m; i++){
		scanf("%d", &b[i]);
	}
	prework();
	
	bool dbg;
	int la, ra, lb, rb;
	long long ansa, ansb, bda, bxc;
	for(int cs=1; cs<=q; cs++){
//		dbg = false;
//		if(cs == 102){
//			dbg = true;
//		}
		scanf("%d %d %d %d", &la, &ra, &lb, &rb);
		
		bda = bmax(lb, rb); bxc = bmin(lb, rb);
		if(bda>0 && bxc<0){
			ansa = posmin(la, ra)*bxc;
			ansb = negmax(la, ra)*bda;
			printf("%lld\n", max(ansa, ansb));
		}
		else if(bda>0 && bxc>=0){
			ansa = amax(la, ra);
			if(ansa < 0) ansa *= bda;
			else ansa *= bxc;
			printf("%lld\n", ansa);
/*
			if(dbg){
				for(int i=la; i<=ra; i++){
					printf("%d ", a[i]);
				}
				printf("\n");
			}
*/
		}
		else if(bda<=0 && bxc<0){
			ansa = amin(la, ra);
			if(ansa < 0) ansa *= bda;
			else ansa *= bxc;
			printf("%lld\n", ansa);
/*
			if(dbg){
				for(int i=la; i<=ra; i++){
					printf("%d ", a[i]);
				}
				printf("\n");
			}
*/
		}
		else{
			printf("0\n");
		}
	}
	
	return 0;
}

void prework(void){
	int lga = log(n)/log(2), lgb = log(m)/log(2);
	for(int i=1; i<=n; i++){
		 stamax[i][0] = a[i];
		 stamin[i][0] = a[i];
		 if(a[i] > 0){
		 	stapos[i][0] = a[i];
		 	staneg[i][0] = -Inf;
		 } 
		 if(a[i] < 0){
		 	stapos[i][0] = Inf;
		 	staneg[i][0] = a[i];
		 }
	}
	for(int i=1; i<=lga; i++){
		for(int j=1; j<=n; j++){
			stamax[j][i] = max(stamax[j][i-1], stamax[j+(1<<(i-1))][i-1]);
			stamin[j][i] = min(stamin[j][i-1], stamin[j+(1<<(i-1))][i-1]);
			stapos[j][i] = min(stapos[j][i-1], stapos[j+(1<<(i-1))][i-1]);
			staneg[j][i] = max(staneg[j][i-1], staneg[j+(1<<(i-1))][i-1]);
		}
	}
	for(int i=1; i<=m; i++){
		 stbmax[i][0] = b[i];
		 stbmin[i][0] = b[i]; 
	}
	for(int i=1; i<=lgb; i++){
		for(int j=1; j<=m; j++){
			stbmax[j][i] = max(stbmax[j][i-1], stbmax[j+(1<<(i-1))][i-1]);
			stbmin[j][i] = min(stbmin[j][i-1], stbmin[j+(1<<(i-1))][i-1]);
		}
	}
}

int amax(int l, int r){
	int lg = log(r-l+1)/log(2);
	return max(stamax[l][lg], stamax[r-(1<<lg)+1][lg]);
}
int bmax(int l, int r){
	int lg = log(r-l+1)/log(2);
	return max(stbmax[l][lg], stbmax[r-(1<<lg)+1][lg]);
}
int amin(int l, int r){
	int lg = log(r-l+1)/log(2);
	return min(stamin[l][lg], stamin[r-(1<<lg)+1][lg]);
}
int bmin(int l, int r){
	int lg = log(r-l+1)/log(2);
	return min(stbmin[l][lg], stbmin[r-(1<<lg)+1][lg]);
}
int posmin(int l, int r){
	int lg = log(r-l+1)/log(2);
	return min(stapos[l][lg], stapos[r-(1<<lg)+1][lg]);
}
int negmax(int l, int r){
	int lg = log(r-l+1)/log(2);
	return max(staneg[l][lg], staneg[r-(1<<lg)+1][lg]);
}
