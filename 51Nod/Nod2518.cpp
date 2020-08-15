#include <cstdio>
#include <iostream>

const int Max=30005;
int n, a[Max], b[Max], c[Max], ans, s;

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	scanf("%d", &s);
	b[0]=a[0]; c[b[0]]++;
	for(int i=1; i<n; i++){
		b[i]=b[i-1]+a[i];
		c[b[i]]++;
	}
	for(int i=0; i<n; i++){
		if(s==0){
			ans+=c[b[i]+s-a[i]+1]-1;
		}
		else
			ans+=c[b[i]+s-a[i]];
		if(c[b[i]+s-a[i]]==0) break;
	}
	printf("%d", ans);

	return 0;
}
