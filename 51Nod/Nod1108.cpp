#include <cstdio>
#include <iostream>
#include <algorithm>
using std::sort;

const int Max=10005;
int n, a[Max], b[Max], c[Max];
long long ans;
inline int abs(int a) { return a<0?-a:a; }

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d%d%d", &a[i], &b[i], &c[i]);
	}
	sort(a, a+n);
	sort(b, b+n);
	sort(c, c+n);
	int mid=n>>1;
	for(int i=0; i<n; i++){
		ans+=abs(a[mid]-a[i]);
		ans+=abs(b[mid]-b[i]);
		ans+=abs(c[mid]-c[i]);
	}
	printf("%lld", ans);
	
	return 0;
}
