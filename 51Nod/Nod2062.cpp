#include <cstdio>
#include <iostream>
#include <algorithm>

const int Max=20005;
int n, cnt, a[Max];

int main(){
	freopen("data.in", "r", stdin);
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &a[cnt++]);
	}
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &a[cnt++]);
	}
	std::sort(a, a+cnt);
	for(int i=0; i<cnt; i++){
		printf("%d\n", a[i]);
	}

	return 0;
}
