#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

const int Maxn = 1e6+5, Mod = 1e9+7, Maxlog = 55;
//const int Maxn = 1e2+5, Mod = 1e9+7, Maxlog = 55;
int n, pi[Maxn][Maxlog], l, minn[Maxn], logi, cnt[Maxn];
long long ans=1;
char a[Maxn];
std::string str;

void prework(void);

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d", &n);
	for(int cst=0; cst<n; cst++){
		ans = 1;
		scanf("%s", a);
		str = a;
		str = " " + str;
//		lena = strlen(a);
		memset(cnt, 0, sizeof(cnt));
		memset(pi, 0, sizeof(pi));
		prework();

		for(int i=2; i<str.size(); i++){
			l = i;
			logi = log(i)/log(2);
			for(int j=logi; j>=0; j--){
				if(pi[l][j] != 0 && pi[l][j]*2 > i){
					l = pi[l][j];
					cnt[i] += 1<<j;
					cnt[i] %= Mod;
				}
//				else if(pi[i][j] != 0) break;
			}
			for(int j=0; j<=logi; j++){
				if(pi[l][j] != 0 && pi[l][j]*2 <= i){
					l = pi[l][j];
					cnt[i] += 1<<j;
					cnt[i] %= Mod;
					break;
				}
			}
/*
			while(l*2 > i+1 && l != 0){
				l = pi[l-1];
				cnt[i]++;
			}
*/
			cnt[i] += cnt[l];
			cnt[i] %= Mod;
			if(cnt[i] != 0){
				ans *= (cnt[l]+2);
			}
			ans %= Mod;
		}

		printf("%lld\n", ans);
	}

	return 0;
}

void prework(void){
	for(int i=2; i<str.size(); i++){
		l = pi[i-1][0];
		while(l>0 && str[i]!=str[l+1]) l = pi[l][0];
		if(str[i] == str[l+1]) l++;
		pi[i][0] = l;
	}
	int logg = log(str.size())/log(2);
	for(int j=1; j<str.size(); j++){
		for(int i=1; i<=logg; i++){
			pi[j][i] = pi[pi[j][i-1]][i-1];
			if(pi[j][i] == 0) break;
		}
	}
}
