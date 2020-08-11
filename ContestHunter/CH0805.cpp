#include <cstdio>
#include <iostream>
#include <cmath>
using std::min;

int fin(int);
int calc(int, int);
void solve(int, int);
const int Max=200005;
int s[Max], e[Max], d[Max];
int t, n;

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d", &t);
	int l, r;
	for(int k=0; k<t; k++){
		l=0x7fffffff; r=0;
		scanf("%d", &n);
		for(int i=0; i<n; i++){
			scanf("%d %d %d", &s[i], &e[i], &d[i]);
			l=s[i]<l?s[i]:l;
			r=e[i]>r?e[i]:r;
		}
		solve(l, r);
	}

	return 0;
}

void solve(int l, int r){
	int mid;
	while(l<r){
		mid=(l+r)>>1;
		if(calc(l, mid)&1) r=mid;
		else l=mid+1;
	}
	int ans=fin(l);
	if(ans&1) printf("%d %d\n", l, ans);
	else printf("There's no weakness.\n");
}

int calc(int l, int r){
	int ans=0;
	for(int i=0; i<n; i++){
		if(s[i]<=r){
			ans += (min(e[i],r)-s[i])/d[i]+1;
		}
	}
	return ans;
}

int fin(int x){
	int ans=0;
	for(int i=0; i<n; i++){
		if(x-s[i]>=0 && x<=e[i] && (x-s[i])%d[i]==0) ans++;
	}
	return ans;
}
