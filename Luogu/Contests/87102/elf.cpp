#include <cstdio>
#include <iostream>
#include <map>
#include <algorithm>
#define int long long
using std::make_pair, std::min;

const int Maxn = 5e5+5;
//const int Maxn = 5e1+5;
typedef std::pair <int, int> pii;
pii ptemp;
std::map <pii, pii> elfs;
int r[5], maxr, n, maxi, max1, mixed[Maxn][5], cnt, maxid;

int calc(int x){
	return (x*x*x)/4;
}

signed main(){
//	freopen("data.in", "r", stdin);

	scanf("%lld", &n);
	for(int i=1; i<=n; i++){
		scanf("%lld %lld %lld", &r[0], &r[1], &r[2]);
		std::sort(r, r+3);
		if(r[0] > maxr){
			maxr = r[0];
			maxid = i;
		}
		ptemp = make_pair(r[1], r[2]);
		if(elfs.find(ptemp) == elfs.end()){
			elfs[ptemp] = make_pair(r[0], i);
		}
		else{
			mixed[cnt][0] = min(min(r[0]+elfs[ptemp].first, r[1]), r[2]);
			mixed[cnt][1] = elfs[ptemp].second;
			mixed[cnt][2] = i;
			if(mixed[cnt][0] > maxi){
				maxi = mixed[cnt][0];
				max1 = cnt;
			}
			cnt++;
		}
	}

	if(maxi > maxr){
		printf("1\n%lld %lld\n%lld", mixed[max1][1], mixed[max1][2], calc(mixed[max1][0]));
	}
	else{
		printf("0\n%lld\n%lld", maxid, calc(maxr));
	}

	return 0;
}
