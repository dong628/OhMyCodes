#include <cstdio>
#include <iostream>
#include <algorithm>

const int Max=1000005;
int n, summ, ss, z, a[Max], s[Max];
long long ans;
inline int abs(int a) { return a>0?a:-a; }

int main(){
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
		summ+=a[i];
	}
	ss=summ/n;
	s[0]=a[0]-ss;
	for(int i=1; i<n; i++){
		s[i]=s[i-1]+(a[i]-ss);
	}
	std::sort(s, s+n);
	z=s[n/2];
	for(int i=0; i<n; i++){
		ans+=(long long)(abs(s[i]-z));
	}
	printf("%lld", ans);


	return 0;
}
