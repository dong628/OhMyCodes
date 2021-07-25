#include <cstdio>
#include <iostream>

const int Max=1e5+5;
int n, q, a[Max], b[Max], l, r, c, d, cnt;
int minn(int, int);

int main(){
	freopen("island.in", "r", stdin);
	freopen("island.out", "w", stdout);

	scanf("%d %d", &n, &q);
	for(int i=1; i<=n; i++){
		scanf("%d %d", &a[i], &b[i]);
	}
	for(int i=0; i<q; i++){
		cnt=0;
		scanf("%d %d %d %d", &l, &r, &c, &d);
		for(int i=l; i<=r; i++){
			if((a[i]^c)<=minn(b[i], d)){
				cnt++;
			}
		}
		printf("%d\n", cnt);
	}

	return 0;
}

int minn(int x, int y){
	return x>y?y:x;
}
