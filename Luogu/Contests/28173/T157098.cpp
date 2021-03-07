#include <cstdio>
#include <iostream>

long long ans;
const int Max=1e6+5, Mod=998244353;
int a[Max], n, p;
long long qpow(int, int);
void dfs(int, int);

int main(){
	scanf("%d %d", &n, &p);
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	dfs(0, 0);
	printf("%d", ans);

	return 0;
}

void dfs(int x, int sum){
	if(x==n){
		ans += int(qpow(2, sum)%Mod);
		ans %= Mod;
	}
	else{
		dfs(x+1, sum);
		dfs(x+1, sum+a[x]);
	}
}

long long qpow(int x, int y){
	long long base=x, anss=1;
	while(y){
		if(y&1){
			anss*=base;
			anss%=Mod;
		}
		y>>=1; base*=base;
		base%=Mod;
	}
	return anss;
}
