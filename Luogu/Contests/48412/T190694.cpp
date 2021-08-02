#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
using std::unique;

std::set<long long> ansa;
const int Maxn=61;
int n, mapp[Maxn][Maxn], cnt;
bool vi[Maxn], vis[Maxn];
char ch;
long long set[Maxn], ans, m;

long long dfs(int);

int main(){
//	freopen("data.in", "r", stdin);

	scanf("%d\n", &n);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			ch = getchar();
			mapp[i][j] = ch-'0';
		}
		scanf("\n");
	}
	for(int i=1; i<=n; i++){
		vis[i]=true;
		set[i] = (dfs(i)|(1<<(i-1)));
//		printf("%lld\n", set[i]);
		vi[i] = true;
		vis[i]=false;
	}
	m = std::unique(set+1, set+1+n)-(set+1);
	cnt=0;
	for(int i=0; i<(1<<m); i++){
		ans=0;
		for(int j=0; j<m; j++){
			if(i&(1<<j)) ans|=set[j+1];
		}
		ansa.insert(ans);
	}
//	for(int i=1; i<=m; i++) printf("%lld ", ansa[i]);
	printf("%lld", ansa.size());
	
/*	for(int i=1; i<=m; i++){
		for(int j=i+1; j<=m; j++){
			if(set[i]&set[j]==set[j] || set[i]&)
		}
	}*/

	return 0;
}

long long dfs(int point){
	long long anan=0;
	if(vi[point]){
		return set[point];
	}
	for(int i=1; i<=n; i++){
		if(mapp[point][i]==1 && vis[i]==false){
			vis[i]=true;
			anan|=(1<<(i-1));
			anan|=dfs(i);
			vis[i]=false;
		}
	}
	return anan;
}
