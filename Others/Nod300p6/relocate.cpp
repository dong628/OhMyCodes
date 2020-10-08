#include <cstdio>
#include <cstring>
#include <iostream>

int t, n, a, b, p;

int main(){
	freopen("relocate.in", "r", stdin);
	freopen("relocate.out", "w", stdout);
	scanf("%d", &t);
	for(int x=0; x<t; x++){
		scanf("%d %d %d", &n, &a, &b);
		for(int i=1; i<=n; i++){
			scanf("%d", &p);
		}
		if(n&1) printf("NO\n");
		else printf("YES\n");
	}

	return 0;
}
