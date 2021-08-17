#include <cstdio>
#include <iostream>

typedef long long lol;
int n, cnt, t;
lol ans, base, k;
const int Mod=1e9+7;
lol xs(lol, lol);
lol getsum(lol, lol);

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d", &t);
	for(int cs=1; cs<=t; cs++){
		cnt=-1;
		ans=0;
		scanf("%d %lld", &n, &k);
		k--;
		ans += getsum(1, n);
		base = n+1;
		while(true){
			cnt++;
			base -= 2;
			if(k>2*base){
				if(cnt&1){
					k -= 2*base;
					ans += (xs(getsum(1, base-1)+1, base))%Mod;
					ans += (xs(getsum(1, base)+2, base))%Mod;
//					ans += (xs(getsum(1, base-1)+1, 2*base)-base-4)%Mod;
					ans -= 2*base+1;
//					ans %= Mod;
				}
				else{
					k -= 2*base;
					ans += (xs(getsum(1, base-1)+1, 2*base)-2*(base-1)-1)%Mod;
					ans %= Mod;
				}
			}
			else if(cnt&1){
				ans += xs(getsum(1, base-1)+1, (k+1)>>1)%Mod;
				ans %= Mod;
				ans += xs(getsum(1, base)+2, k>>1)%Mod;
				ans %= Mod;
				break;
			}
			else{
				ans += xs(getsum(1, base)-((k+1)>>1)+1, (k+1)>>1)%Mod;
				ans %= Mod;
				ans += xs(getsum(1, base+1)-(k>>1), k>>1)%Mod;
				ans %= Mod;
				break;
			}
		}
		printf("%lld\n", ans);
	}

	return 0;
}

lol getsum(lol l, lol r){
	return ((l+r)*(r-l+1))>>1;
}

lol xs(lol l, lol len){
	return (((l+l+len-1)%Mod)*(len%Mod))>>1;
}
