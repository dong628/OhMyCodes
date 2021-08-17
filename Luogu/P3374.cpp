#include <cstdio>
#include <iostream>

const int Maxn=5e5+5;
int lowbit(int xx) { return xx & -xx; }
int sum(int);
void add(int, int);
int n, m, a[Maxn], t, x, y, c[Maxn];

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
		add(i, a[i]);
	}
	for(int i=1; i<=m; i++){
		scanf("%d %d %d", &t, &x, &y);
		if(t==1) add(x, y);
		else{
			printf("%d\n", sum(y)-sum(x-1));
		}
	}

	return 0;
}

int sum(int r){
	int ans=0;
	while(r>0){
		ans+=c[r];
		r-=lowbit(r);
	}
	return ans;
}

void add(int ind, int num){
	while(ind<=n){
		c[ind]+=num;
		ind+=lowbit(ind);
	}
}
