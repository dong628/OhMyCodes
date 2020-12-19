#include <cstdio>
#include <iostream>

const int Max=10, INF=0x7fffffff;
int t, n, nu, x, k, a[Max], maxx, minn=INF, minid, maxid, mid;
void solve(void);

int main(){
	freopen("snakes.in", "r", stdin);
	freopen("snakes.out", "w", stdout);
	
	scanf("%d", &t);
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	solve();
	for(int i=0; i<t-1; i++){
		scanf("%d", &k);
		for(int j=0; j<k; j++){
			scanf("%d %d", &nu, &x);
			a[nu-1]=x;
		}
		solve();
	}

	return 0;
}

void solve(void){
	minn=INF;
	maxx=0;
	for(int i=0; i<n; i++){
		if(a[i]>=maxx) {maxx=a[i]; maxid=i;}
		if(a[i]<minn) {minn=a[i]; minid=i;}
	}
	for(int i=0; i<3; i++){
		if(i!=maxid && i!=minid) mid=i;
	}
	if(maxx-minn>a[mid]) printf("1\n");
	else if(maxx-minn<a[mid]) printf("3\n");
	else{
		if(maxid>mid) printf("1\n");
		else printf("3\n");
	}
}
