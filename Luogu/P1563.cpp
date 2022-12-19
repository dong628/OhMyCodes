#include <cstdio>
#include <iostream>

const int Maxn = 1e5+5;
int n, m, a[Maxn], face, b;
char s[Maxn][20];

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++){
		scanf("%d ", &a[i]);
		scanf("%s", s[i]);
	}
	int cur = 0;
	for(int i=0; i<m; i++){
		scanf("%d %d", &face, &b);
		cur += (face ^ a[cur]) ? b : -b;
		cur %= n;
		cur += n; cur %= n;
	}

	printf("%s", s[(cur+n)%n]);

	return 0;
}
