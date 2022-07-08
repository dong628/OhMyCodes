#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>

const int Maxn = 2e5+5;
bool vis[Maxn];
int cnt, t, n, base;
int pow(int, int);

int main(){
//	freopen("data.in", "r", stdin);

	scanf("%d", &t);
	for(int cst=0; cst<t; cst++){
		cnt = 0;
		memset(vis, 0, sizeof(vis));
		scanf("%d", &n);
		printf("2\n");
		for(int x=1; x<=n/2; x++){
			base = x;
			for(int i=0; base<=n; i++){
				if(vis[base]) break;
				printf("%d ", base);
				vis[base] = true;
				base *= 2;
				cnt++;
			}
		}
		if(cnt==n){
			printf("\n");
			continue;
		}
		for(int i=1; cnt<n; i++){
			if(!vis[i]){
				printf("%d ", i);
				if((!vis[2*i]) && 2*i<=n){
					printf("%d ", 2*i);
					vis[2*i] = true;
					cnt++;
				}
				vis[i] = true;
				cnt++;
			}
		}
		printf("\n");
	}

	return 0;
}

int pow(int a, int b){
	int base = a, ans = 1;
	while(b){
		if(b&1) ans *= base;
		base *= base;
		b <<= 1;
	}
	return ans;
}
