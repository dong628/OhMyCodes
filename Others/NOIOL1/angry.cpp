#include <cstdio>
#include <iostream>

const int Max=505, Mod=1e9+7;
long long summ, base, a[Max], n;
char s;
int k;
bool calc(long long);

int main(){
	freopen("angry.in", "r", stdin);
	freopen("angry.out", "w", stdout);

	for( ; ; ){
		s=getchar();
		if(s=='\n') break;
		n<<=1;
		if(s=='1') n+=1;
	}
	scanf("%d", &k);
	for(int i=0; i<k; i++){
		scanf("%lld", &a[i]);
	}
//	dfs(0, n);
	for(long long i=0; i<n; i++){
		if(calc(i)){
			base=1;
			for(int j=0; j<k; j++){
				summ += (a[j]*base)%Mod;
				summ %= Mod;
				base *= i;
				base %= Mod;
			}
		}
	}
	printf("%lld", summ);

	return 0;
}

bool calc(long long num){
	int ans=0;
	while(num){
		ans+=(num&1);
		num>>=1;
	}
	if(ans&1) return true;
	else return false;
}
