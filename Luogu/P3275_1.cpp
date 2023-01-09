#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
using std::make_pair, std::pair, std::min, std::max;

const int Maxn = 3e5+5;
//const int Maxn = 305;
int ts = 1, cnt;
int num[Maxn], low[Maxn], dfn[Maxn], sccno[Maxn], rb[Maxn], tp[Maxn];
long long dis[Maxn];
bool vis[Maxn];
std::vector < pair <int, int> > mp1[Maxn], mp2[Maxn];
std::vector < int > sets[Maxn];
std::stack < int > sccur;
void dfs(int), rebuild(void), topo(void);

int main(){
	freopen("data.in", "r", stdin);

	int n, k, x, a, b;
	scanf("%d %d", &n, &k);
/*
	for(int i=1; i<=n; i++){
		mp1[0].push_back(make_pair(i, 0));
	}
*/
	for(int i=1; i<=k; i++){
		scanf("%d %d %d", &x, &a, &b);
		if(x == 1){
			mp1[b].push_back(make_pair(a, 0));
			mp1[a].push_back(make_pair(b, 0));
		}
		else if(x == 2){
			mp1[a].push_back(make_pair(b, 1));
		}
		else if(x == 3){
			mp1[b].push_back(make_pair(a, 0));
		}
		else if(x == 4){
			mp1[b].push_back(make_pair(a, 1));
		}
		else{
			mp1[a].push_back(make_pair(b, 0));
		}
	}
/*
	for(int i=1; i<=n; i++){
		for(int j=0; j<mp1[i].size(); j++){
			printf("%d %d %d\n", i, mp1[i][j].first, mp1[i][j].second);
		}
	}
	putchar('\n');
*/
	for(int i=1; i<=n; i++){
		if(dfn[i] == 0) dfs(i);
	}

	for(int i=1; i<=n; i++){
		for(int j=0; j<mp1[i].size(); j++){
			if(mp1[i][j].second == 1 && sccno[mp1[i][j].first] == sccno[i]){
				printf("-1");
				return 0;
			}
		}
	}

	rebuild();
/*
	for(int i=1; i<=cnt; i++){
		for(int j=0; j<mp2[i].size(); j++){
			printf("%d %d %d\n", i, mp2[i][j].first, mp2[i][j].second);
		}
	}
*/
	memset(dis, 0, sizeof(dis));
	topo();

	dis[0] = 1;
	for(int i=0; i<cnt; i++){
		for(int j=0; j<mp2[tp[i]].size(); j++){
			dis[mp2[tp[i]][j].first] = max(dis[mp2[tp[i]][j].first], dis[tp[i]]+mp2[tp[i]][j].second);
		}
	}

	long long minn = 0, ans = 0;
	for(int i=1; i<=cnt; i++){
		ans += dis[i] * sets[i].size();
	}

	printf("%lld", ans);

	return 0;
}

void dfs(int cur){
	sccur.push(cur);
	dfn[cur] = low[cur] = ts++;

	pair <int, int> tar;
	for(int i=0; i<mp1[cur].size(); i++){
		tar = mp1[cur][i];
		if(dfn[tar.first] == 0){
			dfs(tar.first);
			low[cur] = min(low[cur], low[tar.first]);
		}
		else if(sccno[tar.first] == 0){
			low[cur] = min(low[cur], dfn[tar.first]);
		}
	}
	int tmp;
	if(low[cur] == dfn[cur]){
		cnt++;
		for( ; ; ){
			tmp = sccur.top(); sccur.pop();
			sets[cnt].push_back(tmp);
			sccno[tmp] = cnt;
			if(cur == tmp) break;
		}
	}
}

void rebuild(void){
	for(int i=1; i<=cnt; i++){
		mp2[0].push_back(make_pair(i, 0));
		for(int j=0; j<sets[i].size(); j++){
			for(int k=0; k<mp1[sets[i][j]].size(); k++){
				if(i == sccno[mp1[sets[i][j]][k].first]) continue;
				mp2[i].push_back(make_pair(sccno[mp1[sets[i][j]][k].first], mp1[sets[i][j]][k].second));
//				mp2[sccno[mp1[sets[i][j]][k].first]].push_back(make_pair(i, mp1[sets[i][j]][k].second));
			}
		}
	}
}

void topo(void){
	int top = 0, cur = 0;
	for(int i=0; i<=cnt; i++){
		for(int j=0; j<mp2[i].size(); j++){
			rb[mp2[i][j].first]++;
		}
	}
/*
	for(int i=1; i<=cnt; i++){
		if(rb[i] == 0){
			tp[top++] = i;
		}
	}
*/
	tp[top++] = 0;
	while(top < cnt){
		for(int i=0; i<mp2[tp[cur]].size(); i++){
			rb[mp2[tp[cur]][i].first]--;
			if(rb[mp2[tp[cur]][i].first] == 0) tp[top++] = mp2[tp[cur]][i].first;
		}
		cur++;
	}
}
