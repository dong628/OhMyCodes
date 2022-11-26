#include <iostream>
#include <cstdio>
#include <algorithm>

int n, m, a[1005];
int abs(int x) { return x>0?x:-x; }

int main(){
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	std::sort(a, a+n);
	if(m>=n-1){
		printf("0");
		return 0;
	}
	int minn = 0x7fffffff, tmp;
	for(int i=0; i<m; i++){
		tmp = abs(a[i] - a[n-m+i-1]);
		minn = minn<tmp?minn:tmp;
	}
	printf("%d", minn);

	return 0;
}
