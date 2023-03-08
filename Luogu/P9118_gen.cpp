#include <cstdio>
#include <iostream>
#include <set>
#include <cmath>

typedef long long lol;
std::set <long long> s;

int main(){
//	freopen("data.in", "r", stdin);
//	freopen("power.out", "w", stdout);

	long long n, k, pre = 0;
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
	for(int x=1; x<=100; x++){
		s.clear();
		long long imax = pow(lol(x*1e16), double(1)/3)+1, logg, curv;
		for(int i=2; i<imax; i++){
			logg = (log(n)/log(i))+1;
			if(s.find(i) != s.end()) continue;
			curv = i*i;
			for(int j=3; j<=logg; j++){
				curv *= i;
				if(curv <= lol(x*1e16) && (lol(sqrt(curv))*lol(sqrt(curv))!=curv)) s.insert(curv);
			}
		}
		printf("%ld,", s.size());
		fflush(stdout);
	}

	return 0;
}
