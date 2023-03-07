#include <cstdio>
#include <iostream>
#include <set>
#include <cmath>

std::set <long long> s;

int main(){
	freopen("data.in", "r", stdin);
//	freopen("power.out", "w", stdout);

	long long n, k, pre = 0;
	scanf("%lld %lld", &n, &k);
	if(k == 1){
		printf("%lld", n);
		return 0;
	}

	s.insert(1);
/*
	if(k == 2){
		pre += (long long)(sqrt(n));
		pre += (long long)(pow(n, double(1)/3));
		k = 4;
	}
	else if(k == 3){
		pre += (long long)(pow(n, double(1)/3));
		k = 4;
	}
*/
	long long imax = pow(n, double(1)/k)+1, logg, curv;
	for(int i=2; i<imax; i++){
		logg = (log(n)/log(i))+1;
		if(s.find(i) != s.end()) continue;
		curv = pow(i, k-1);
		for(int j=k; j<=logg; j++){
			curv *= i;
			if(curv <= n) s.insert(curv);
		}
	}
	printf("%lld", s.size()+pre);

	return 0;
}
