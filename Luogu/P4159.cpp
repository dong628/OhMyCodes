#include <cstdio>
#include <iostream>

typedef long long lol;
int n, numij;
lol t, cnt;
char cij;
const lol Mod=2009;
struct Matrix{
	lol n, m, val[105][105]={0};
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
		for(int i=0; i<n; i++) ans.val[i][i] = 1;
		while(b){
			if(b&1){
				ans = ans * base;
			}
			base = base * base;
			b >>= 1;
		}
		return ans;
	}
} graph;

int main(){
	freopen("data.in", "r", stdin);
	scanf("%d %lld\n", &n, &t);
	cnt = n*10;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%c", &cij);
			numij = cij-'0';
			if(numij == 0) continue;
			if(numij == 1){
				graph.val[i][j] = 1;
				continue;
			}
			graph.val[i][n+9*i] = 1;
			for(int k=0; k<numij-2; k++){
				graph.val[n+9*i+k][n+9*i+k+1] = 1;
			}
			graph.val[n+9*i+numij-2][j] = 1;
		}
		getchar();
	}
	graph.n = cnt; graph.m = cnt;
	graph = graph ^ t;
	printf("%lld", graph.val[0][n-1]);

	return 0;
}
