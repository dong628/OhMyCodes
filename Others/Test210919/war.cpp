#include <cstdio>
#include <iostream>
#include <algorithm>

const int Maxn=305;
int n, hp[Maxn], m, x, y, hp1[Maxn], k;
char tp;

int main(){
	freopen("war.in", "r", stdin);
	freopen("war.out", "w", stdout);

	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%d", &hp[i]);
	}
	scanf("%d\n", &m);
	for(int csm=1; csm<=m; csm++){
		tp = getchar();
		if(tp=='A'){
			scanf("%d %d\n", &x, &y);
			hp[x] -= y;
		}
		else if(tp=='C'){
			scanf("%d %d\n", &x, &y);
			hp[x] += y;
		}
		else{
			scanf("%d\n", &k);
			for(int ii=1; ii<=n; ii++) hp1[ii] = hp[ii];
			std::sort(hp1+1, hp1+n+1);
			if(hp1[n-k+1]<=0) printf("-1\n");
			else printf("%d\n", hp1[n-k+1]);
		}
	}
	for(int ii=1; ii<=n; ii++) hp1[ii] = hp[ii];
	std::sort(hp1+1, hp1+n+1);
	for(int i=1; i<=n; i++){
		if(hp1[i]>0){
			printf("%d\n", n-i+1);
			break;
		}
	}

	return 0;
}
