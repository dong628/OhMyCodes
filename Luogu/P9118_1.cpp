#include <cstdio>
#include <iostream>
#include <set>
#include <cmath>

typedef long long lol;
const lol Step = 1e16;
int tb1[101] = {
0,222609,278852,318292,349678,376178,399336,420045,438865,456175,472242,487273,501417,514795,527503,539619,551206,562321,573008,583305,593249,602864,612179,621217,629995,638534,646845,654948,662854,670570,678113,685489,692709,699781,706711,713506,720172,726716,733142,739457,745666,751771,757779,763691,769510,775244,780894,786463,791951,797355,802682,807938,813126,818247,823305,828301,833236,838113,842933,847698,852410,857070,861678,866238,870749,875215,879634,884010,888341,892631,896879,901087,905255,909386,913479,917535,921555,925539,929489,933406,937290,941142,944963,948752,952510,956240,959940,963612,967255,970872,974461,978024,981559,985071,988557,992017,995454,998868,1002258,1005625,1008969
};
std::set <long long> s;
lol qpow(lol, lol);

int main(){
	freopen("data.in", "r", stdin);
//	freopen("power.out", "w", stdout);

	long long n, k;
	scanf("%lld %lld", &n, &k);
	if(k == 1){
		printf("%lld", n);
		return 0;
	}

	s.insert(1);

	long long imax = pow(n, double(1)/k)+1, logg, curv;
	if(k >= 3){
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
	long long logmin, logmax, ns, cnt2;
	if(k == 2){
		ns = lol(n/Step)*Step;
		for(int i=2; i<imax; i++){
			logmax = (log(n)/log(i)) + 1;
			logmin = (log(ns)/log(i));
			curv = qpow(i, logmin);
			for(int j=logmin; j<=logmax; j++){
				if(curv <= n && curv > ns) s.insert(curv);
			}
		}
		cnt2 = lol(sqrt(n));
		printf("%lld", cnt2+s.size()+tb1[lol(n/Step)]);
	}

	return 0;
}

lol qpow(lol a, lol b){
	lol base = a, ans = 1;
	while(b){
		if(b&1) ans *= base;
		base *= base;
		b >>= 1;
	}
	return ans;
}
