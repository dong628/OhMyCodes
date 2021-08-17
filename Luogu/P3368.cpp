#include <cstdio>
#include <iostream>

const int Maxn=5e5+5;
int tp, x, y, k, n, m, a[Maxn], cf[Maxn], c[Maxn];
int lowbit(int xx) { return xx & -xx ; }
void add(int, int);
int sum(int);

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
		cf[i] = a[i]-a[i-1];
		add(i, cf[i]);
	}
	for(int cs=1; cs<=m; cs++){
		scanf("%d", &tp);
		if(tp==1){
			scanf("%d %d %d", &x, &y, &k);
			add(x, k);
			add(y+1, -k);
		}
		else{
			scanf("%d", &x);
			printf("%d\n", sum(x));
		}
	}

	return 0;
}

void add(int ind, int del){
	while(ind<=n){
		c[ind]+=del;
		ind+=lowbit(ind);
	}
}

int sum(int ind){
	int ans=0;
	while(ind>0){
		ans+=c[ind];
		ind-=lowbit(ind);
	}
	return ans;
}
