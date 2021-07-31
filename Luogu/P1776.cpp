#include <cstdio>
#include <iostream>
#include <cmath>
using std::max;

const int Maxn=1e5+5;
int n, maxw, v[Maxn], w[Maxn], m[Maxn], logm, maxv, dp[Maxn];
int vv, ww, mm, cnt;

int main(){
	scanf("%d %d", &n, &maxw);
	for(int i=1; i<=n; i++){
		scanf("%d %d %d", &vv, &ww, &mm);
		for(int j=0; mm; j++){
			if(mm>=(1<<j)){
				++cnt;
				mm -= (1<<j);
				v[cnt] = vv*(1<<j);
				w[cnt] = ww*(1<<j);
			}
			else{
				++cnt;
				v[cnt] = vv*mm;
				w[cnt] = ww*mm;
				mm=0;
			}
		}
/*		logm = log(mm)/log(2);
		for(int j=0; j<logm; j++){
			v[cnt] = vv*(1<<j);
			w[cnt] = ww*(1<<j);
			++cnt;
		}
		v[cnt] = vv*(mm-(1<<logm)+1);
		w[cnt] = ww*(mm-(1<<logm)+1);
		++cnt;*/
	}
	for(int i=1; i<=cnt; i++){
		for(int j=maxw; j>=w[i]; j--){
			dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
		}
	}

/*	for(int i=1; i<=n; i++){
		for(int j=0; j<=maxw; j++){
			for(int k=0; k<=logm[i]; k++){
				if(j>=w[i]*(1<<k))
					dp[j] = max(dp[j], dp[j-w[i]*(1<<k)]+v[i]*(1<<k));
			}
			if(j>=w[i]*(m[i]-(1<<logm[i])))
				dp[j] = max(dp[j], dp[j-w[i]*(m[i]-(1<<logm[i]))]+
				v[i] * ((m[i]-(1<<logm[i]))));
		}
	}*/
	for(int i=1; i<=maxw; i++){
		maxv = maxv>dp[i]?maxv:dp[i];
	}
	printf("%d", maxv);

	return 0;
}
