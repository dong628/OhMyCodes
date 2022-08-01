#include <cstdio>
#include <iostream>
#include <vector>
#define int long long
using std::vector;

const int Maxn = 5e5+5;
vector<int> tr[Maxn];
int n, ans, fa[Maxn], cnt[Maxn], s[Maxn], top, cur[Maxn], sum[Maxn];
bool ti[Maxn];
void dfs(int);

signed main(){
	freopen("data.in", "r", stdin);

	char ch;
	scanf("%lld\n", &n);
	for(int i=1; i<=n; i++){
		ch = getchar();
		if(ch == '(') ti[i] = false;
		else ti[i] = true;
	}
	for(int i=2; i<=n; i++){
		scanf("%lld", &fa[i]);
		tr[fa[i]].push_back(i); cnt[fa[i]]++;
	}
	dfs(1);
	for(int i=1; i<=n; i++){
		ans ^= sum[i]*i;
	}
	printf("%lld", ans);

	return 0;
}

void dfs(int root){
	int t = 0;
	if(ti[root] && top != 0){
		t = s[top-1];
		cur[root] = cur[fa[t]]+1;
		top--;
	}
	else if(!ti[root]){
		s[top++] = root;
	}
	sum[root] = sum[fa[root]]+cur[root];
	for(int i=0; i<cnt[root]; i++){
		dfs(tr[root][i]);
	}
	if(t != 0) s[top++] = t;
	else if(top!=0) top--;
}
