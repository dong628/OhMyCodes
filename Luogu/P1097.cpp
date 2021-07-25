#include <cstdio>
#include <iostream>
#include <algorithm>

const int Maxn=2e5+5;
int n, a[Maxn], cnt;

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	std::sort(a, a+n);
	for(int i=0; i<n; i++){
		if(i!=0 && a[i]!=a[i-1]){
			printf("%d %d\n", a[i-1], cnt);
			cnt=1;
		}
		else cnt++;
	}
	printf("%d %d", a[n-1], cnt);

	return 0;
}
