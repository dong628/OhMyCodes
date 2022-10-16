#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

const int Maxn = 2e5+5, Inf = 0x7fffffff;
int s[Maxn], minj[Maxn], n, m, k, cf[Maxn], tab4[Maxn];

int main(){
	freopen("data.in", "r", stdin);

	int l, r, opt, a, b, ans, minn, jmax;
	bool flag = false, flag4 = true, flag4z = true;

	scanf("%d %d %d", &n, &m, &k);
	for(int i=0; i<n; i++){
		scanf("%d %d", &l, &r);
		cf[l] += 1;
		cf[r+1] -= 1;
//		for(int i=l; i<=r; i++) s[i] = 1;
	}
	s[0] = cf[0];
	for(int i=1; i<=k; i++){
		s[i] = s[i-1]+cf[i];
	}
	for(int i=0; i<=k; i++){
		if(s[i]>=1){
			s[i] = 1;
		}
		else{
			flag4z = false;
		}
	}
	jmax = (log(k)/log(2)+1);
	for(int i=0; i<=k; i++){
		for(int j=0; j<(1<<jmax); j++){
			if(((i^j)<=k) && s[i^j] == 0){
				tab4[i] = j;
				break;
			}
		}
	}
	for(int i=1; i<=k; i++){
		tab4[i] += tab4[i-1];
	}
	
	while(m--){
		scanf("%d %d %d", &opt, &a, &b);
		if(opt == 0 || opt == 3){
/*
			for(int j=0; j<=k; j++){
				if(s[j] == 0) flag = true;
			}
			if(!flag){
				printf("Death\n");
				continue;
			}
*/
			if(flag4 && flag4z){
				printf("Death\n");
				continue;
			}
			else if(flag4){
				printf("%d\n", tab4[b]-tab4[a-1]);
				continue;
			}
			flag = false;
			ans = 0;
			for(int i=a; i<=b; i++){
				minn = -1;
				for(int j=0; j<(1<<jmax); j++){
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
			flag4 = false;
			for(int i=a; i<=b; i++) s[i] = 0;
		}
	}

	return 0;
}
