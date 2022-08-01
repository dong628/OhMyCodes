#include <cstdio>
#include <iostream>

typedef long long lol;
const int Maxn = 5e6+5;
int n;
int p, k, a[Maxn], maxa, ans, mmia, kp[Maxn], s[Maxn], mmi[Maxn];
int qpow(int a, int b, int mod);
int read()
{
	int x=0,flag=1;char c;
	while((c=getchar())<'0' || c>'9') if(c=='-') flag=-1;
	while(c>='0' && c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x*flag;
}

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d %d %d", &n, &p, &k);
	kp[0] = 1;
	for(int i=1; i<=n; i++){
		a[i] = read();
		kp[i] = (lol(kp[i-1])*lol(k))%p;
		kp[i] %= p;
	}
	s[0] = 1;
	for(int i=1; i<=n; i++){
		s[i] = (lol(s[i-1])*lol(a[i]))%p;
	}
	mmi[n] = qpow(s[n], p-2, p);
	for(int i=n-1; i>=1; i--){
		mmi[i] = (lol(mmi[i+1])*lol(a[i+1]))%p;
	}
	for(int i=1; i<=n; i++){
		ans += ((lol(kp[i])*lol(mmi[i]))%p*lol(s[i-1]))%p;
		ans %= p;
	}
	printf("%d", ans);

	return 0;
}

int qpow(int a, int b, int mod){
	int ans = 1, base = a;
	while(b){
		if(b&1) ans = (lol(ans)*lol(base))%p;
		base = (lol(base)*lol(base))%p;
		b >>= 1;
	}
	return ans;
}
