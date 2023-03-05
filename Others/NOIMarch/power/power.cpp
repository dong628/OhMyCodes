#include <cstdio>
#include <iostream>
#include <set>
#include <cmath>

std::set <long long> s;

int main(){
	freopen("power.in", "r", stdin);
//	freopen("power.out", "w", stdout);

	long long n, k;
	scanf("%lld %lld", &n, &k);
	if(k == 1){
		printf("%lld", n);
		return 0;
	}

	s.insert(1);
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
	printf("%ld", s.size());

	return 0;
}
