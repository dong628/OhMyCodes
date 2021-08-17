#include <cstdio>
#include <iostream>

const int Maxn=1e5+5;
int n, a[Maxn], c[Maxn], ans, cur;

int main(){
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
		c[i] = a[i]-a[i-1];
	}
	for(int i=1; i<=n; i++){
		if(c[i]>0){
			ans += c[i];
			cur += c[i];
		}
		if(c[i]<0){
			cur -= c[i];
			if(cur<0){
				ans-=cur;
				cur=0;
			}
		}
	}
	printf("%d", ans);

	return 0;
}
