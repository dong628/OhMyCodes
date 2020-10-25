#include <cstdio>
#include <iostream>

int t, n, m, k;
inline int min(int x, int y) { return x<y?x:y; }

int main(){
	freopen("scramble.in", "r", stdin);
	freopen("scramble.out", "w", stdout);

	scanf("%d", &t);
	for(int i=0; i<t; i++){
		scanf("%d %d %d", &n, &m, &k);
		for(int j=0; j<k; j++){
			if(n<=m){
				m-=n; n+=n;
			}
			else{
				n-=m; m+=m;
			}
		}
		printf("%d\n", min(n, m));
	}

	return 0;
}
