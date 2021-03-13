#include <cstdio>
#include <iostream>

const int Max=1e6+5;
int t, tim, a[Max], b[Max], tm[Max], n;

int main(){
//	freopen("data.in", "r", stdin);

	scanf("%d", &t);
	for(int casenum=0; casenum<t; casenum++){
		tim=0;
		scanf("%d", &n);
		for(int i=1; i<=n; i++)
			scanf("%d %d", &a[i], &b[i]);
		for(int i=1; i<=n; i++)
			scanf("%d", &tm[i]);
		for(int i=1; i<n; i++){
			tim += a[i]-b[i-1]+tm[i];
			if(tim+(b[i]-a[i]+1)/2 < b[i]) tim=b[i];
			else tim += (b[i]-a[i]+1)/2;
		}
		tim += a[n]-b[n-1]+tm[n];
		printf("%d\n", tim);
	}

	return 0;
}
