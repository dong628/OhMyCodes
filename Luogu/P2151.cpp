#include <cstdio>
#include <iostream>
#include <vector>
using std::vector;

typedef long long lol;
const int Maxm = 65, Maxn = 55;
int n, m, a, b, s, e, cnte, cntend, end[Maxm], eg[2*Maxm][2], cnt[Maxn];
vector<int> edge[Maxn];
lol t, ans;
const lol Mod=45989;
struct Matrix{
	lol n, m, val[2*Maxm][2*Maxm]={0};
	Matrix operator * (Matrix b){
		Matrix ans; ans.n = this->n; ans.m = b.m;
		for(int i=0; i<this->n; i++){
			for(int j=0; j<b.m; j++){
				for(int k=0; k<this->m; k++){
					ans.val[i][j] += this->val[i][k] * b.val[k][j];
					ans.val[i][j] %= Mod;
				}
			}
		}
		return ans;
	}
	Matrix operator ^ (lol b){
		Matrix ans, base = *this; ans.n = n; ans.m = m;
		for(int i=0; i<this->n; i++) ans.val[i][i] = 1;
				for(int i=0; i<ans.n; i++){
					for(int j=0; j<ans.m; j++){
						printf("%d ", ans.val[i][j]);
					}
					printf("\n");
				}
				printf("--------------------------\n");
		while(b){
			if(b&1){
				ans = ans * base;
				for(int i=0; i<ans.n; i++){
					for(int j=0; j<ans.m; j++){
						printf("%d ", ans.val[i][j]);
					}
					printf("\n");
				}
				printf("--------------------------\n");
			}
			base = base * base;
			b >>= 1;
		}
		return ans;
	}
} graph, x, aans;

int main(){
	freopen("data.in", "r", stdin);
	scanf("%d %d %lld %d %d", &n, &m, &t, &s, &e);
	graph.n = n; graph.m = n;
	for(int i=0; i<m; i++){
		scanf("%d %d", &a, &b);
		cnt[a]++; cnt[b]++;
		eg[cnte][0] = a; eg[cnte][1] = b;
		if(a == s) x.val[cnte][0]++;
		if(b == e) end[cntend++] = cnte;
		edge[a].push_back(cnte++);
		eg[cnte][0] = b; eg[cnte][1] = a;
		if(b == s) x.val[cnte][0]++;
		if(a == e) end[cntend++] = cnte;
		edge[b].push_back(cnte++);
	}
	for(int i=0; i<cnte; i++){
		for(int j=0; j<cnt[eg[i][1]]; j++){
			if(eg[edge[eg[i][1]][j]][1] != eg[i][0]){
				graph.val[edge[eg[i][1]][j]][i]++;
				graph.val[edge[eg[i][1]][j]][i] %= Mod;
			}
		}
	}
	graph.n = cnte; graph.m = cnte;
	x.n = cnte; x.m = 1;

	for(int i=0; i<graph.n; i++){
		for(int j=0; j<graph.m; j++){
			printf("%d ", graph.val[i][j]);
		}
		printf("\n");
	}
	for(int i=0; i<x.n; i++){
		printf("%d", x.val[i][0]);
		printf("\n");
	}

	aans = graph ^ (t-1);
	printf("--------------------------\n");
	for(int i=0; i<aans.n; i++){
		for(int j=0; j<aans.m; j++){
			printf("%d ", aans.val[i][j]);
		}
		printf("\n");
	}
	x = aans * x;

	for(int i=0; i<x.n; i++){
		printf("%d", x.val[i][0]);
		printf("\n");
	}
/*
	for(int i=0; i<cntse; i++){
		for(int j=0; j<cntee; j++){
			ans += anss.val[s][i]
		}
	}
*/
	
	for(int i=0; i<cntend; i++){
		ans += x.val[end[i]][0];
		ans %= Mod;
	}
	printf("%lld", ans);

	return 0;
}
