#include <cstdio>
#include <iostream>

int main(){
	int n, a, minn = 0x7fffffff;

	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &a);
		minn = minn<a?minn:a;
	}
	printf("%d", minn);

	return 0;
}
