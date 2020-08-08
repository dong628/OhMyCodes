#include <cstdio>
#include <iostream>

const int Maxa=100005, Maxp=1000005;
long long a[Maxa], power[Maxp], maxx;
int q, n;
long long search(int);
void update(int);

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%lld", &a[i]);
		maxx=maxx>a[i]?maxx:a[i];
	}
	for(long long i=1; i<=maxx; i++){
		power[i]=0;
		for(int j=0; j<n; j++){
			power[i]+=a[j]^i;
		}
	}
	int m;
	scanf("%d", &q);
	for(int i=0; i<q; i++){
		scanf("%d", &m);
		update(m);
		printf("%lld\n", search(m));
	}

	return 0;
}

long long search(int m){
	long long ans=-1;
	for(int i=1; i<=maxx; i++){
		if(power[i]<=m) ans=i;
	}
	return ans;
}

void update(int m){
	for(long long i=maxx+1; i<=maxx+m; i++){
		power[i]=0;
		for(int j=0; j<n; j++) power[i]+=a[j]^i;
	}
	maxx=maxx+m;
}
