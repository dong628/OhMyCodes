#include <cstdio>
#include <iostream>
#include <vector>
using std::make_pair;

const int Maxn = 5e5+5;
std::vector < std::pair<int, long long> > mapp[Maxn];
bool vis[Maxn];
long long sub[Maxn], t;
int n, s, cnt[Maxn], a, b;
long long dfs(int);

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d %d", &n, &s);
	for(int i=1; i<n; i++){
		scanf("%d %d %lld", &a, &b, &t);
		mapp[a].push_back(make_pair(b, t));
		mapp[b].push_back(make_pair(a, t));
		cnt[a]++; cnt[b]++;
	}
	printf("%lld", dfs(s));

	return 0;
}

long long dfs(int node){
	vis[node] = true;
	if(cnt[node]==1 && node!=s){
		return 0;
	}
	long long anss=0, maxx=0, tmp;
	int fa=-1;
	for(int i=0; i<cnt[node]; i++){
		if(vis[mapp[node][i].first] == false){
			anss += dfs(mapp[node][i].first);
			tmp = sub[mapp[node][i].first]+mapp[node][i].second;
			maxx = maxx>tmp?maxx:tmp;
		}
		else{
			fa = i;
		}
	}
	for(int i=0; i<cnt[node]; i++){
		if(i!=fa){
			anss += maxx-(sub[mapp[node][i].first]+mapp[node][i].second);
		}
	}
	sub[node] = maxx;
	return anss;

}
