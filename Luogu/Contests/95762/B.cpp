#include <cstdio>
#include <iostream>

const int Maxn = 1e6+5;
int n, m;
bool f[Maxn], pre[Maxn];

int main(){
	freopen("data.in", "r", stdin);

	char ch;
	scanf("%d %d\n", &n, &m);
	for(int i=1; i<=m; i++){
		ch = getchar();
		if(ch == '0') f[i] = false;
		else f[i] = true;
	}
	int tmp = 0;
	for(int i=1; i<=m; i++){
		if(!f[i]) tmp = i;
		pre[i] = i - tmp;
	}

	int delta = 0, a;
	for(int i=1; i<=n; i++){
		scanf("%d", &a);
		if(pre[a-delta] > 0) delta++;
	}

	printf("%d", delta);

	return 0;
}
