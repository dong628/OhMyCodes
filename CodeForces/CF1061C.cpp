#include <cstdio>
#include <iostream>
#include <algorithm>
using std::sort;

const int Maxn = 1e6+5, Mod = 1e9+7;
int a[Maxn], arr[Maxn], f[Maxn], n, ans, cnt;
void sep(int);

int main(){
//	freopen("data.in", "r", stdin);

	scanf("%d", &n);
	for(int i=1; i<=n; i++) scanf("%d", &a[i]);
	f[0] = 1;
	for(int i=1; i<=n; i++){
		sep(a[i]);
		for(int k=cnt-1; k>=0; k--){
			f[arr[k]] += f[arr[k]-1];
			f[arr[k]] %= Mod;
		}
	}
	for(int i=1; i<=n; i++){
		ans += f[i];
		ans %= Mod;
	}
	printf("%d", ans);

	return 0;
}

void sep(int x){
	cnt = 0;
	for(int i=1; i*i<=x; i++){
		if(x%i == 0){
			arr[cnt++] = i;
			if(i*i != x){
				arr[cnt++] = x/i;
			}
		}
	}
	sort(arr, arr+cnt);
}
