#include <cstdio>
#include <iostream>
#include <set>
#include <cstring>
#include <queue>
#define int long long
using std::make_pair;

const int Maxn = 2505;
typedef std::pair <int, int> pii;
std::vector <int> mapp[Maxn];
std::set <pii> s[Maxn];
std::queue <int> q;
int cnt[Maxn], dis[Maxn][Maxn], val[Maxn];
bool vis[Maxn];

bool diff(int a, int b, int c, int d){
	if(a == b || b == c || c == d || a == c || a == d || b == d) return false;
	return true;
}

signed main(){
	freopen("data.in", "r", stdin);

	int n, m, k, x, y;
	scanf("%lld %lld %lld", &n, &m, &k);

	for(int i=2; i<=n; i++){
		scanf("%lld", &val[i]);
	}
	for(int i=1; i<=m; i++){
		scanf("%lld %lld", &x, &y);
		mapp[x].push_back(y); cnt[x]++;
		mapp[y].push_back(x); cnt[y]++;
	}
//	printf("flag: 35\n");
	int cur;
	memset(dis, 0x3f, sizeof(dis));
	for(int i=1; i<=n; i++){
		q.push(i);
		memset(vis, 0, sizeof(vis)); vis[i] = true;
		dis[i][i] = 0;
		while(!q.empty()){
			cur = q.front(); q.pop();
			for(int j=0; j<cnt[cur]; j++){
				if(vis[mapp[cur][j]]) continue;
				dis[i][mapp[cur][j]] = dis[i][cur] + 1;
				q.push(mapp[cur][j]);
				vis[mapp[cur][j]] = true;
			}
		}
	}
//	printf("flag: 50\n");

	for(int i=2; i<=n; i++){
		for(int j=2; j<=n; j++){
			if(i!=j && dis[i][j] <= k+1 && dis[j][1] <= k+1){
				s[i].insert(make_pair(-val[j], j));
			}
		}
	}
//	printf("flag: 59\n");

	int ans = 0, tmp, cnti, cntj;
	for(int i=2; i<=n; i++){
		if(s[i].empty()) continue;
		for(int j=i+1; j<=n; j++){
			if(dis[i][j] > k+1) continue;
			if(s[j].empty()) continue;
			cnti = 0;
			for(auto iteri=s[i].begin(); cnti<3 && iteri != s[i].end(); cnti++, iteri++){
				cntj = 0;
				for(auto iterj=s[j].begin(); cntj<3 && iterj != s[j].end(); cntj++, iterj++){
					if(diff(iteri -> second, iterj -> second, i, j)){
						tmp = - iteri -> first - iterj -> first + val[i] + val[j];
						ans = ans > tmp ? ans : tmp;
					}
				}
			}
		}
	}
	
	printf("%lld\n", ans);

	return 0;
}
