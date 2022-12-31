#include <cstdio>
#include <iostream>

const int Maxn = 1e6+5;
long long a[Maxn], b[Maxn];

void print(__int128 x){
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x<10)
	{
		putchar(x+48);
		return;
	}
	print(x/10);
	putchar(x%10+48);
}

int main(){
	freopen("data.in", "r", stdin);
	int n;

	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%lld", &a[i]);
	}
	for(int i=1; i<=n; i++){
		scanf("%lld", &b[i]);
	}

	__int128 cur = 0, maxx = 0, s = 0, tmp;
	for(int j=1; j<=n; j++){
		s += b[j];
	}
	for(int j=1; j<=n; j++){
		cur += n*__int128(b[j]*b[j]);
	}
	maxx = cur - s * s;

	for(int i=1; i<=n; i++){
		s -= b[i]; s += a[i]; 
		cur -= n*__int128(b[i]*b[i]); cur += n*__int128(a[i]*a[i]);
		tmp = cur - s*s;
		maxx = tmp > maxx ? tmp : maxx;
	}

	print(maxx);

	return 0;
}
