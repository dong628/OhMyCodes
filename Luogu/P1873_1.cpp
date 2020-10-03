#include <cstdio>
#include <iostream>

const int Max=1e6+5;
int maxx, a[Max], n;
long long m;
inline int mmax(int x, int y) { return x>y?x:y; }
long long calc(int);
inline int uf(int x) { return x&1?x/2+1:x/2; }

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
		maxx=maxx>a[i]?maxx:a[i];
	}
	int l=0, r=maxx, mid;
	while(l<r){
		mid=(l+r+1)>>1;
		if(calc(mid)<m) r=mid-1;
		else l=mid;
	}
//	if(calc(r)>=m) printf("%d", r);
//	else printf("%d", l);
	printf("%d", l);

	return 0;
}

long long calc(int h){
	long long sum=0;
	for(int i=0; i<n; i++){
		sum += mmax(a[i]-h, 0);
	}
	return sum;
}
