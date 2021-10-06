#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int Maxn=1e5+5;
const long long Mod = 1e9+7;
int n, sm[Maxn], su[Maxn];
long long dp[Maxn][2];
bool flag;
char sen[Maxn][15];

int main(){
	freopen("foot.in", "r", stdin);
	freopen("foot.out", "w", stdout);

	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%s", sen[i]);
	}
	for(int i=2; i<=n; i++){
		flag = true;
		for(int j=0; j<10; j++){
			if(sen[i][j]!=sen[i-1][j]){
				flag = false;
				sm[i] = 1;
				break;
			}
		}
		if(flag){
			sm[i] = 0;
		}
	}
	
/*	for(int i=2; i<=n; i++){
		su[i] = su[i-1]+sm[i];
	}*/

	dp[1][0] = 1; dp[1][1] = 0;

	for(int i=2; i<=n; i++){
		if(sm[i]==1){
			dp[i][0] = dp[i-1][1]+dp[i-1][0];
			dp[i][1] = dp[i-1][0];
			dp[i][0] %= Mod;
			dp[i][1] %= Mod;
		}
		else{
			dp[i][0] = dp[i-1][1]+dp[i-1][0];
			dp[i][1] = 0;
			dp[i][0] %= Mod;
			dp[i][1] %= Mod;
		}
	}

	printf("%lld\n", (dp[n][0]+dp[n][1])%Mod);

//	for(int i=2; i<=n; i++){
//		printf("%d ", sm[i]);
//	}

/*	for(int i=1; i<=n; i++){
		printf("%s ", sen[i]);
//		printf("%d ", int(sen[i]==sen[i-1]));
	}
*/

	return 0;
}
