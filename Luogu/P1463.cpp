#include <cstdio>
#include <iostream>

long long powp[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
long long p[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
long long x[10];
long long n, cmax, valmin = 0x7fffffff, c = 1, v = 1;
void dfs(int);

int main(){
	scanf("%lld", &n);
	dfs(0);
	printf("%lld", valmin);

	return 0;
}

void dfs(int wz){
	if(c > cmax){
		cmax = c;
		valmin = v;
	}
	else if(c == cmax){
		if(valmin > v) valmin = v;
	}
	if(wz >= 10) return;
	long long vor = v;
	for(int i=0; i<=30; i++){
		if(wz==0 || x[wz]<x[wz-1]){
			v *= p[wz];
			if(v > n){
				v = vor;
				x[wz] = 0;
				return;
			}
			x[wz]++;
			c *= x[wz]+1;
			dfs(wz+1);
			c /= x[wz]+1;
		}
		if(wz!=0 && x[wz] >= x[wz-1]){
			v = vor;
			x[wz] = 0;
			return;
		}
	}
}
