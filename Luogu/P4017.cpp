#include <cstdio>
#include <iostream>

const int Maxn=5005, Mod=80112002;
int n, m, a, b, ma[Maxn][Maxn], sc[Maxn], xf[Maxn], cnt[Maxn], ans;
int data[Maxn];
int dfs(int);

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d %d", &n, &m);
	for(int i=1; i<=m; i++){
		scanf("%d %d", &a, &b);
		ma[a][b]=1;
		sc[a]=1; xf[b]=1;
	}
	for(int i=1; i<=n; i++){
		if(!sc[i]){
			cnt[i]=dfs(i);
		}
	}
	for(int i=1; i<=n; i++){
		if(!sc[i]){
			ans+=cnt[i];
			ans%=Mod;
		}
	}
	printf("%d", ans);


	return 0;
}

int dfs(int nu){
	if(!xf[nu]) return 1;
	if(data[nu]) return data[nu];
	int tot=0;
	for(int i=1; i<=n; i++){
		if(ma[i][nu]) {
			tot+=dfs(i)%Mod;
			tot%=Mod;
		}
	}
	data[nu]=tot;
	return tot;
}
