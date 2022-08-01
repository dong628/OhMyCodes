#include <iostream>
#include <cstdio>

const int Mod = 2017, Maxn = 105;
struct Matrix{
        int n, m, val[Maxn][Maxn]={0};
        Matrix operator * (Matrix b){
                Matrix ans; ans.n = this->n; ans.m = b.m;
                for(int i=0; i<this->n; i++){
                        for(int j=0; j<b.m; j++){
                                for(int k=0; k<this->m; k++){
                                        ans.val[i][j] += (this->val[i][k]*b.val[k][j])%Mod;
                                        ans.val[i][j] %= Mod;
                                }
                        }
                }
                return ans;
        }
        Matrix operator ^ (int b){
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
} mapp, ans, xx;
int n, m, anss, t, u, v;

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d %d", &n, &m);
	for(int i=0; i<m; i++){
		scanf("%d %d", &u, &v);
		mapp.val[u][v]++; mapp.val[v][u]++;
	}
	scanf("%d", &t);
	for(int i=1; i<=n; i++){
		mapp.val[i][i] = 1;
		mapp.val[0][i] = 1;
	}
	mapp.val[0][0] = 1;
	mapp.n = n+1; mapp.m = n+1;
	xx.val[1][0] = 1;
	xx.n = n+1; xx.m = 1;
	mapp = mapp ^ t;
	ans = mapp * xx;
	for(int i=0; i<=n; i++){
		anss += ans.val[i][0];
	}
	anss %= Mod;
	printf("%d", anss);

	return 0;
}
