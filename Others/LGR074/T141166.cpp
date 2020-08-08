#include <cstdio>
#include <iostream>

const int Maxa=100005, Maxp=1000005;
int a[Maxa], power[Maxp], q, n, maxx;
int search(int);
void update(int);

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}

	int m; maxx=0;
	scanf("%d", &q);
	for(int i=0; i<q; i++){
		scanf("%d", &m);
		if(m>maxx) update(m);
		printf("%d\n", search(m));
	}

	return 0;
}

int search(int m){
	int ans=-1;
	for(int i=1; i<=maxx; i++){
		if(power[i]<=m) ans=i;
	}
	return ans;
}

void update(int m){
	for(int i=maxx+1; i<=m+maxx; i++){
		for(int j=0; j<n; j++) power[i]+=a[j]^i;
	}
	maxx=m+maxx;
}
