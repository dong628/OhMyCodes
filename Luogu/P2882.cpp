#include <cstdio>
#include <iostream>

const int Maxn=5005;
char facing;
int n, fac[Maxn], minn=0x7fffffff, cnt, maxk, cf[Maxn];
int turn(int);
int abs(int a) { return a>0?a:-a; }

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d\n", &n);
	for(int i=1; i<=n; i++){
		scanf("%c\n", &facing);
		if(facing == 'B') fac[i]=1;
		else fac[i]=0;
		cf[i] = fac[i]-fac[i-1];
	}
	for(int i=1; i<=n; i++){
		cnt = turn(i);
		if(minn>cnt){
			minn = cnt;
			maxk = i;
		}
	}
	printf("%d %d", maxk, minn);

	return 0;
}

int turn(int k){
	int moves=0;
	for(int i=1; i<=n; i++){
		cf[i] = fac[i]-fac[i-1];
	}
	for(int i=1; i<=n-k+1; i++){
		if(abs(cf[i])&1){
			cf[i]++;
			cf[i+k]--;
			moves++;
		}
	}
	for(int i=1; i<=n; i++){
		if(abs(cf[i])&1) return 0x7fffffff;
	}
	return moves;
}
