#include <cstdio>
#include <iostream>

int n, tmp, ans;

int main(){
	freopen("rune.in", "r", stdin);
	freopen("rune.out", "w", stdout);

	scanf("%d", &n);
	for(int i=0; i<n; i++) scanf("%d", &tmp);
	for(int i=0; i<n; i++){
		scanf("%d", &tmp);
		ans+=tmp;
	}
	printf("%d", ans);

	return 0;
}
