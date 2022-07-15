#include <cstdio>
#include <iostream>
typedef unsigned long long lol;
int n, k;
const lol Inf = 0xffffffffffffffff;
lol mul(lol, lol, lol);
struct Matrix{
	lol n, m, val[105][105]={0};
	Matrix operator * (Matrix b){
		Matrix ans; ans.n = this->n; ans.m = b.m;
		for(int i=0; i<this->n; i++){
			for(int j=0; j<b.m; j++){
				for(int k=0; k<this->m; k++){
					ans.val[i][j] |= (this->val[i][k] & b.val[k][j]);
				}
			}
		}
		return ans;
	}
	Matrix operator ^ (lol b){
		Matrix ans, base = *this; ans.n = this->n; ans.m = this->m;
		for(int i=0; i<this->n; i++) ans.val[i][i] = Inf;
		while(b){
			if(b&1){
				ans = ans * base;
			}
			base = base * base;
			b >>= 1;
		}
		return ans;
	}
} a, base, aans;
Matrix qpow(Matrix, lol);

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d %d", &n, &k);
	for(int i=0; i<k; i++) scanf("%llu", &a.val[i][0]);
	for(int i=0; i<k; i++) scanf("%llu", &base.val[k-1][i]);
	
	a.n = k; a.m = 1;
	base.n = k; base.m = k;
	for(int i=0; i<k-1; i++) base.val[i][i+1] = Inf;

	base = base ^ (n-k+1);
	aans = base * a;

	printf("%llu", aans.val[k-1][0]);

	return 0;
}
