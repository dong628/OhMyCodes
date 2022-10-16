#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

const int Maxn = 2e5+5, Inf = 0x7fffffff;
int s[Maxn], minj[Maxn], n, m, k;

int main(){
	freopen("data.in", "r", stdin);

	int l, r, opt, a, b, ans, minn, jmax;
	bool flag = false, flag4 = true;

	scanf("%d %d %d", &n, &m, &k);
	for(int i=0; i<n; i++){
		scanf("%d %d", &l, &r);
		for(int i=l; i<=r; i++) s[i] = 1;
	}
	jmax = (log(k)/log(2)+1);

	while(m--){
		scanf("%d %d %d", &opt, &a, &b);
		if(opt == 0){
/*
			for(int j=0; j<=k; j++){
				if(s[j] == 0) flag = true;
			}
			if(!flag){
				printf("Death\n");
				continue;
			}
*/
			if(flag){
				printf("Death\n");
				continue;
			}
			ans = 0;
			for(int i=a; i<=b; i++){
				minn = -1;
				for(int j=minj[i]; j<(1<<jmax); j++){
					if(((i^j)<=k) && s[i^j] == 0){
						minn = j;
						break;
					}
				}
				if(minn == -1){
					flag = true;
					printf("Death\n");
					break;
				}
				ans += minn;
			}
			if(!flag){
				printf("%d\n", ans);
			}
		}
		else if(opt == 1){
			flag4 = false;
			for(int i=a; i<=b; i++) s[i] = 1;
		}
		else{
			flag = false;
			flag4 = false;
			for(int i=a; i<=b; i++) s[i] = 0;
		}
	}

	return 0;
}
