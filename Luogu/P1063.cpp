#include <cstdio>
#include <iostream>

const int Maxn = 305;
int n, maxx[Maxn][Maxn], a[Maxn], mans, ans;
int max(int xx, int yy) { return xx>yy?xx:yy; }

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
		a[i+n] = a[i];
	}
	a[n+n+1] = a[1];
	
	for(int len=2; len<=n; len++){
		for(int st=1; st<=2*n-len+1; st++){
			for(int k=st; k<st+len-1; k++){
				ans = maxx[st][k]+maxx[k+1][st+len-1]+a[st]*a[k+1]*a[st+len];
				maxx[st][st+len-1] = max(maxx[st][st+len-1], ans);
			}
		}
	}

	for(int st=1; st<=n; st++){
		mans = max(mans, maxx[st][st+n-1]);
	}
	printf("%d", mans);

	return 0;
}
