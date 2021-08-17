#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>

const int Maxn=5e4+5, Maxlog=20;
int st[Maxn][Maxlog], mapp[Maxn], a[Maxn], mx, my, x, y, n, m;
void Prework(void);
int Query(int, int);
int findmax(int);
int findmin(int);
int max(int xx, int yy) { return xx>yy?xx:yy; }

int main(){
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);

	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%d %d", &mapp[i], &a[i]);
	}
	Prework();
	scanf("%d", &m);
	for(int i=1; i<=m; i++){
		scanf("%d %d", &y, &x);
		mx = findmin(x);
		my = findmax(y);
		if(mx-my<=1){
			if(mapp[mx]==x && mapp[my]==y){
				if(mx-my==x-y){
					if(a[mx]<=a[my]) printf("true\n");
					else printf("false\n");
				}
				else{
					if(a[mx]<=a[my]) printf("maybe\n");
					else printf("false\n");
				}
			}
			else printf("false\n");
/*			if(mapp[mx]!=x || mapp[my]!=y || mx-my!=x-y)
				printf("maybe\n");
			else if(a[mx]<=a[my]) printf("true\n");
			else printf("false\n");
*/
			continue;
		}
		if(mapp[mx]!=x || mapp[my]!=y || mx-my!=x-y){
			if((Query(my+1, mx-1)>=a[mx])) printf("false\n");
			else printf("maybe\n");
		}
		else if(Query(my+1, mx-1)<a[mx] && a[mx]<=a[my]){
			printf("true\n");
		}
		else printf("false\n");
	}

	return 0;
}

void Prework(void){
	int logg = log(n)/log(2);
	for(int i=1; i<=n; i++){
		st[i][0] = a[i];
	}
	for(int i=1; i<=logg; i++){
		for(int j=1; j<=n; j++){
			st[j][i] = max(st[j][i-1], st[j+(1<<(i-1))][i-1]);
		}
	}
}

int Query(int l, int r){
	int logg = log(r-l+1)/log(2);
	if(l==r) return st[l][logg];
	return max(st[l][logg], st[r-(1<<logg)+1][logg]);
}

int findmax(int num){
	int l=1, r=n, mid;
	while(l<r){
		mid=(l+r+1)>>1;
		if(mapp[mid]<=num) l=mid;
		else r=mid-1;
	}
	return l;
}

int findmin(int num){
	int l=1, r=n, mid;
	while(l<r){
		mid=(l+r)>>1;
		if(mapp[mid]<num) l=mid+1;
		else r=mid;
	}
	return l;
}
