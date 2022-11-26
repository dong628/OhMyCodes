#include <cstdio>
#include <iostream>
using std::max;

const int Maxn = 4e5+5;
int a[Maxn], b[Maxn], c[Maxn];

int main(){
//	freopen("data.in", "r", stdin);

	int n, m, ans, over = 0;
	scanf("%d %d", &n, &m);
	int cnt = 0;
	for(int i=0; i<n; i++){
		scanf("%d", &a[n-i]);
	}
	for(int i=0; i<m; i++){
		scanf("%d", &b[m-i]);
	}
	for(int i=1; i<=max(n, m)+5; i++){
		ans = a[i]+b[i]+over;
		over = ans / (i+1);
		c[i] = ans % (i+1);
	}
	for(int i=1; i<=max(n, m)+5; i++){
		if(c[i]>0) cnt = i;
	}
	for(int i=cnt; i>=1; i--){
		printf("%d ", c[i]);
	}

	return 0;
}
