#include <cstdio>
#include <string>
#include <iostream>
using std::string;

typedef long long lol;
const int Maxn = 1e6+5;
char n_c[Maxn], m_c[Maxn];
const int Mod = 1e9+7;
lol mmia, mmib, mmic, mmid, tmp;
lol mul(lol, lol, lol);
struct Matrix{
	lol n, m, val[2][2]={0};
	Matrix operator * (Matrix b){
		Matrix ans; ans.n = this->n; ans.m = b.m;
		for(int i=0; i<this->n; i++){
			for(int j=0; j<b.m; j++){
				for(int k=0; k<this->m; k++){
					ans.val[i][j] += ((this->val[i][k]%Mod)*(b.val[k][j]%Mod))%Mod;
					ans.val[i][j] = ans.val[i][j] >= Mod ? ans.val[i][j]-Mod : ans.val[i][j];
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
} base1, base2, x, aans;
Matrix qpow10(Matrix, string);
lol exgcd(lol, lol, lol&, lol&);

int main(){
	freopen("data.in", "r", stdin);

	lol a, b, c, d;
	base1.n = 2; base1.m = 2;
	base2.n = 2; base2.m = 2;
	base1.val[1][1] = 1;
	base2.val[1][1] = 1;
	x.n = 2; x.m = 1;
	x.val[0][0] = 1; x.val[1][0] = 1;

	scanf("%s %s %lld %lld %lld %lld", n_c, m_c, &a, &b, &c, &d);
	string n = n_c, m = m_c;
	for(int i=n.size()-1; i>=0; i--){
		if(n[i]=='0') n[i] = '9';
		else { n[i]--; break; }
	}
	for(int i=m.size()-1; i>=0; i--){
		if(m[i]=='0') m[i] = '9';
		else { m[i]--; break; }
	}
	base1.val[0][0] = a; base1.val[0][1] = b;
	base2.val[0][0] = c; base2.val[0][1] = d;

//	mmia /= exgcd(a, Mod, mmia, tmp); mmib /= exgcd(b, Mod, mmib, tmp);
//	mmic /= exgcd(c, Mod, mmic, tmp); mmid /= exgcd(c, Mod, mmid, tmp);

	base1 = qpow10(base1, m);
//	base1.val[0][0] *= mmia; base1.val[0][0] %= Mod; base1.val[0][1] -= b; base1.val[0][1] *= mmia; base1.val[0][1] %= Mod;
	if(n != "0"){
		base2 = base2 * base1;
		base2 = qpow10(base2, n);
		base1 = base1 * base2;
	}
	aans = base1 * x;
	
/*
	base1 = qpow10(base1, m);
	base1.val[0][0] *= mmia; base1.val[0][0] %= Mod; base1.val[0][1] -= b; base1.val[0][1] *= mmia; base1.val[0][1] %= Mod;
	base1 = base2 * base1;
	base1 = qpow10(base1, n);
	base1.val[0][0] *= mmic; base1.val[0][0] %= Mod; base1.val[0][1] -= d; base1.val[0][1] *= mmic; base1.val[0][1] %= Mod;
	aans = base1 * x;

	base2 = qpow10(base2, n);
	base2.val[0][0] /= c; base2.val[0][1] -= d; base2.val[0][1] /= c;
	base1 = qpow10(base1, m);
	base1.val[0][0] /= a; base1.val[0][1] -= b; base1.val[0][1] /= a;
	aans = base1 * aans;
*/
	printf("%lld", aans.val[0][0]);

	return 0;
}

lol mul(lol a, lol b, lol mod){
	lol anss = 0, basse = a;
	while(b){
		if(b&1) anss += basse;
		anss %= mod;
		basse += basse;
		basse %= mod;
		b >>= 1;
	}
	return anss;
}

Matrix qpow10(Matrix a, string b){
	Matrix base = a, ans;
	ans.n = a.n; ans.m = a.m;
	for(int i=0; i<ans.n; i++) ans.val[i][i] = 1;
	for(int i=b.size()-1; i>=0; i--){
		ans = ans * (base ^ lol(data(b)[i]-'0'));
		base = base ^ 10;
	}
	return ans;
}

lol exgcd(lol a, lol b, lol&x, lol&y){
	if(b == 0){
		x = 1; y = 0;
		return a;
	}
	lol gcd = exgcd(b, a%b, y, x);
	y -= a/b*x;
	return gcd;
}
