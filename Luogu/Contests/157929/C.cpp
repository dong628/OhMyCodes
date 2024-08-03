#include <cstdio>
#include <iostream>

const int Maxn = 2e5+5;
int n, m, ti, tm[Maxn], timax, tb[Maxn], maxx, cur;

int main(){
	scanf("%d %d", &n, &m);

	for(int i=1; i<=n; i++){
		scanf("%d", &ti);
		tm[ti]++;
		tm[ti+m]--;
		timax = ti>timax?ti:timax;
	}
	for(int i=1; i<=timax+m; i++){
		tm[i] += tm[i-1];
		if(tm[i] == 2)
			tb[i] = 1;
		if(tm[i] == 1){
			cur++;
			tb[i] = -1;
		}
	}
	for(int i=1; i<=timax+m; i++){
		tb[i] += tb[i-1];
	}
	maxx = -m;
	for(int i=0; i<=timax+m; i++){
		if(tm[i+1] != tm[i]){
			maxx = maxx>tb[i+m]-tb[i]?maxx:tb[i+m]-tb[i];
		}
	}
	printf("%d", maxx+m+cur);
	

	return 0;
}
