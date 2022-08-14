#include <cstdio>
#include <iostream>

typedef long long lol;
//const int Maxn = 1e2+5, Maxa = 2e2+5;;
const int Maxn = 1e6+5, Maxa = 2e2+5;;
const lol Inf = 0x7fffffffffffffff;
int n;
bool xzb = true;
lol c, a[Maxn], s[Maxn], tmp, maxa, ans = Inf;
lol f[Maxa], minn = Inf;
lol calc(lol, lol);

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d %lld", &n, &c);
	for(int i=1; i<=n; i++){
		scanf("%lld", &a[i]);
		if(a[i]<=a[i-1]) xzb = false;
		maxa = a[i]>maxa?a[i]:maxa;
	}
	if(c==0){
		printf("0");
		return 0; 
	}
	if(xzb){
		for(int i=1; i<=n; i++){
			s[i] = s[i-1] + a[i];
		}
		for(int i=1; i<=n; i++){
			tmp = i*a[i]-s[i]+(n-i)*c;
			ans = tmp<ans?tmp:ans;
		}
	}
	else if(maxa <= 1e2){
		for(int i=0; i<=2*maxa; i++){
			if(i>=a[1]) f[i] = i-a[1];
			else f[i] = c;
		}
		for(int i=2; i<=n; i++){
			minn = Inf;
			for(int j=2*maxa; j>=0; j--){
				minn = minn<f[j]?minn:f[j];
				f[j] = minn + calc(a[i], j);
			}
		}
		for(int i=0; i<=2*maxa; i++){
			ans = ans<f[i]?ans:f[i];
		}
	}
	printf("%lld", ans);

	return 0;
}

lol calc(lol s, lol e){
	if(e < s) return c;
	else return e - s;
}
