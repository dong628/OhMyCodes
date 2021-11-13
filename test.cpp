#include <iostream>
#include <cstdio>
#include <algorithm>

int n, a[100], b;

int main(){
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
	}
	std::sort(a+1, a+n+1);
	for(int i=1; i<=n; i++){
		scanf("%d", &b);
		printf("%ld\n", std::lower_bound(a+1, a+n+1, b)-a);
	}

	return 0;
}
