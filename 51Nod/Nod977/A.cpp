#include <cstdio>
#include <iostream>
#include <algorithm>
using std::sort;

typedef long long lol;
const int Maxn = 1e5+5;
//const int Maxn = 1e2+5;
struct Mount{
	lol a, b;
} mnt[Maxn];
lol n;
bool cmp(Mount a, Mount b){ return a.a<b.a; }
bool calc(lol);
int m;

int main(){
	freopen("data.in", "r", stdin);

	scanf("%lld %d", &n, &m);
	for(int i=0; i<m; i++){
		scanf("%lld %lld", &mnt[i].a, &mnt[i].b);
	}
	sort(mnt, mnt+m, cmp);
//	for(int i=0; i<m; i++){
//		printf("%d %d\n", mnt[i].a, mnt[i].b);
//	}
	lol l = 1, r = (mnt[m-1].b+1)/n, mid;
	while(l<r){
		mid = (l+r+1)>>1;
		if(calc(mid)) l = mid;
		else r = mid-1;
//		printf("%d", l);
	}
	printf("%lld", l);

	return 0;
}

bool calc(lol dis){
	lol nowp = mnt[0].a, nowm = 0, nc;
	for(nc=1; nc<n && nowp<=mnt[m-1].b; nc++){
		if(mnt[nowm].b >= nowp+dis){
			nowp += dis;
		}
		else{
			while(mnt[nowm].b < nowp+dis) nowm++;
			nowp = std::max(nowp+dis, mnt[nowm].a);
		}
//		printf("%d %d\n", nowp, nowm);
	}
	if(nc==n && nowp<=mnt[m-1].b) return true;
	else return false;
}
