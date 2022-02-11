#include <iostream>
#include <cstdio>

const int Maxn = 1e6+5;
int n, pi[Maxn], l, minn[Maxn];
long long ans;
char a[Maxn];

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d", &n);
	scanf("%s", a);

	for(int i=1; i<n; i++){
		l = pi[i-1];
		while(l>0 && a[i]!=a[l]) l = pi[l-1];
		if(a[i] == a[l]) l++;
		pi[i] = l;
	}
	
	for(int i=1; i<n; i++){
		l = pi[i];
		while(pi[l-1]>0){
			if(minn[l-1]){
				l = minn[l-1];
				break;
			}
			l = pi[l-1];
		}
		if((i-l+1)*2 >= i+1 && l != 0){
			minn[i] = l;
			ans += i-l+1;
		}
	}

	printf("%lld", ans);

	return 0;
}
