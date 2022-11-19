#include <cstdio>
#include <iostream>
using std::swap;

const int Maxn = 1e3+5;
int n, m, l, r, a[Maxn];

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++) a[i] = i;
	while(m--){
		scanf("%d %d", &l, &r);
		for(int i=0; i<(r-l+1)>>1; i++){
			swap(a[l+i], a[r-i]);
		}
	}
	for(int i=1; i<=n; i++) printf("%d ", a[i]);

	return 0;
}
