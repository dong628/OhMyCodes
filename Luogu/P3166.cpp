#include <cstdio>
#include <iostream>
using std::swap;

typedef unsigned long long lol;
const int Maxn = 1005;
lol tot, ans, xx, cur, m, n;
bool vis[Maxn][Maxn];
lol xl, yl, xp, yp, g;
lol gcd(lol, lol);
//lol calc(lol, lol);

int main(){
	scanf("%llu %llu", &m, &n);
	m++; n++;
	ans = (n*m)*(n*m-1)*(n*m-2)/6;
//	printf("%llu\n", ans);
	for(int i=1; i<m; i++){
		for(int j=1; j<n; j++){
			g = gcd(i, j);
			if(g<=1) continue;
			xp = i/g; yp = j/g;
//			if(vis[xp][yp]) continue;
			xl = (m-1)/xp+1; yl = (n-1)/yp+1;
			cur = (g-1)*(m-i)*(n-j);
			ans -= cur*2;
		}
	}
	ans -= m*n*(n-1)*(n-2)/6;
	ans -= n*m*(m-1)*(m-2)/6;
	printf("%llu", ans);

	return 0;
}

lol gcd(lol a, lol b){
	if(b==0) return a;
	return gcd(b, a%b);
}
/*
lol calc(lol x, lol y){
	if(x<3 || y<3) return 0;
	lol ret = 0;
	if(x>y) swap(x, y);
	ret += (y-x+2)*x*(x-1)*(x-2)/6;
	for(int i=x-1; i>=3; i--){
		ret += 2*i*(i-1)*(i-2)/6;
	}
	return ret;
}
*/
