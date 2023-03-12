#include <cstdio>
#include <iostream>

const int Maxn = 1e6+5;
//const int Maxn = 1e6+5;
int n, a[Maxn], ba[Maxn];

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%d", &ba[i]);
	}
	for(int i=1; i<=n; i++){
		a[i] = ba[i];
	}
	int l = 1, r = 1, ans1 = 0, lnext = 0;
	bool flag = false;
	while(r <= n){
		ans1 = ans1 > (r-l+1) ? ans1:(r-l+1);
		if(a[r+1]>a[r]){
			r++;
		}
		else{
			if(flag) l = lnext;
			else flag = true;
			lnext = r+1;
//			mem = a[r];
			if(a[r+1]-1>a[r-1]) a[r] = a[r+1]-1;
			else a[r+1] = a[r]+1;
		}
	}
	for(int i=1; i<=n; i++){
		a[i] = ba[i];
	}
	l = n; r = n;
	int ans2 = 0, rnext = n+1;
	flag = false;
	while(l >= 1){
		ans2 = ans2 > (r-l+1) ? ans2:(r-l+1);
		if(a[l-1]<a[l]){
			l--;
		}
		else{
			if(flag) r = rnext;
			else flag = true;
			rnext = l-1;
//			mem = a[r];
			if(a[l-1]+1<a[l+1]) a[l] = a[l-1]+1;
			else a[l-1] = a[l]-1;
		}
	}
	printf("%d", std::max(ans1, ans2));

	return 0;
}
