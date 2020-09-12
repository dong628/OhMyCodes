#include <cstdio>
#include <iostream>

const int Max=200005;
long long s[Max], p[Max], cnt, k;
int a[Max], n;

int main(){
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);

	scanf("%d %lld", &n, &k);
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	s[0]=a[0]; p[0]=a[0];
	for(int i=1; i<n; i++){
		s[i]=s[i-1]+a[i];
		p[i]=p[i-1]*a[i];
	}
	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){
			if(p[j]/p[i]*a[i]==(s[j]-s[i]+a[i])*k) cnt++;
		}
	}
	printf("%lld", cnt);


	return 0;
}
