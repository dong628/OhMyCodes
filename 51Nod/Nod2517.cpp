#include <cstdio>
#include <iostream>

const int Max=20005;
int a[Max], n, zero, one, last, qz[Max], hz[Max], minn=0x7fffffff;
char x;

int main(){
	scanf("%d\n", &n);
	for(int i=0; i<n; i++){
		scanf("%c", &x);
		a[i]=x-'0';
	}
	
	qz[1]=a[0]; hz[n-1]=!a[n-1];
	for(int i=1; i<n; i++){
		qz[i+1]=qz[i]+a[i];
		if(a[n-i-1]==0)
			hz[n-i-1]=hz[n-i]+1;
		else
			hz[n-i-1]=hz[n-i];
	}
	for(int i=0; i<=n; i++){
		minn=minn<qz[i]+hz[i+1]?minn:qz[i]+hz[i+1];
	}
	printf("%d", minn);
	
	return 0;
}
