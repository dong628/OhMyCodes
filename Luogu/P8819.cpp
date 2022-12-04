#include <cstdio>
#include <iostream>

const int Maxn = 5e5+5;
int n, m, u, v, q, t;
long long pri[Maxn], spri, curs, maxx[Maxn], cur[Maxn];

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++){
		pri[i] = rand();
		spri += pri[i];
	}
	for(int i=0; i<m; i++){
		scanf("%d %d", &u, &v);
//		mapp[v].push_back(make_pair(u, true));
		curs += pri[u];
		maxx[v] += pri[u];
		cur[v] += pri[u];
	}
	scanf("%d", &q);
	while(q--){
		scanf("%d", &t);
		if(t == 1){
			scanf("%d %d", &u, &v);
			cur[v] -= pri[u];
			curs -= pri[u];
		}
		else if(t == 2){
			scanf("%d", &u);
			curs -= cur[u];
			cur[u] = 0;
		}
		else if(t == 3){
			scanf("%d %d", &u, &v);
			cur[v] += pri[u];
			curs += pri[u];
		}
		else{
			scanf("%d", &u);
			curs += maxx[u] - cur[u];
			cur[u] = maxx[u];
		}
		if(curs == spri){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}

	return 0;
}
