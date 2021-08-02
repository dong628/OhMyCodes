#include <cstdio>
#include <iostream>
#include <cstring>
using std::max;

const int Maxn=2e4+5;
bool flag;
int summ, cs, vsum, v[Maxn], w[Maxn], n[10], cnt, dp[Maxn];

int main(){
	freopen("data.in", "r", stdin);

	while(true){
		flag=false;
		cs++;
		summ=0; cnt=0;
		vsum=0;
		memset(dp, 0, sizeof(dp));
		for(int i=1; i<=6; i++){
			scanf("%d", &n[i]);
			summ += n[i];
			vsum += n[i]*i;
		}
		if(summ==0) break;
		if(vsum&1){
			printf("Collection #%d:\nCan't be divided.\n\n", cs);
			continue;
		}
		vsum >>= 1;
		for(int i=1; i<=6; i++){
			for(int j=0; n[i]>=(1<<j); j++){
				n[i] -= (1<<j);
				cnt++;
				w[cnt] = i*(1<<j);
				v[cnt] = 1<<j;
			}
			if(n[i]){
				cnt++;
				w[cnt] = i*n[i];
				v[cnt] = n[i];
			}
		}
		for(int i=1; i<=cnt; i++){
			for(int j=vsum; j>=v[i]; j--){
				dp[j] = max(dp[j], dp[j-v[i]]+w[i]);
				if(dp[j] == vsum){
					printf("Collection #%d:\nCan be divided.\n\n", cs);
					flag = true;
					break;
				}
			}
			if(flag) break;
		}
		if(!flag){
			printf("Collection #%d:\nCan't be divided.\n\n", cs);
		}
	}

	return 0;
}
