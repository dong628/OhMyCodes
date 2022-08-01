#include <cstdio>
#include <cstring>
#include <iostream>

const int Maxn = 105, Mod = 1e9+7;
int t;
char s[Maxn];
long long f[26*Maxn];
long long calc(int, int);

int main(){
	freopen("data.in", "r", stdin);

	int len, sum = 0;
	scanf("%d\n", &t);
	while(t--){
		sum = 0;
		scanf("%s", s);
		len = strlen(s);
		for(int i=0; i<len; i++){
			sum += s[i]-'a';
		}
		printf("%lld\n", calc(sum, len)-1);
	}

	return 0;
}

long long calc(int x, int len){
	memset(f, 0, sizeof(f));
	f[0] = 1;
	for(int i=0; i<len; i++){
		for(int j=x; j>=0; j--){
			for(int k=1; k<=25; k++){
				if(j<k) break;
				f[j] += f[j-k];
			}
			f[j] %= Mod;
		}
	}
	return f[x] % Mod;
}
