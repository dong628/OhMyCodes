#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

const int Maxn=105, Maxai=50005;
int a[Maxn], f[Maxai], n, t, ans;

int main(){
	scanf("%d", &t);
	for(int cst=1; cst<=t; cst++){
		ans = 0;
		scanf("%d", &n);
		for(int i=1; i<=n; i++){
			scanf("%d", &a[i]);
		}
		std::sort(a+1, a+n+1);
		memset(f, 0, sizeof(f));
		for(int i=1; i<=n; i++){
			f[a[i]]++;
			for(int j=1; j<=a[n]; j++){
				if(f[j]==0) continue;
				f[j+a[i]]+=f[j];
			}
		}
		for(int i=1; i<=n; i++){
			if(f[a[i]]==1) ans++;
		}
		printf("%d\n", ans);
	}

	return 0;
}
