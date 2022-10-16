#include <iostream>
#include <cstdio>

const int Maxn = 2e5+5, Inf = 0x7fffffff;
int s[Maxn], n, m, k;

int main(){
	freopen("data.in", "r", stdin);

	int l, r, opt, a, b, ans, minn;
	bool flag;

	scanf("%d %d %d", &n, &m, &k);
	for(int i=0; i<n; i++){
		scanf("%d %d", &l, &r);
		for(int i=l; i<=r; i++) s[i] = 1;
	}
	while(m--){
		scanf("%d %d %d", &opt, &a, &b);
		if(opt == 0){
			flag = false;
			for(int j=0; j<=k; j++){
				if(s[j] == 0) flag = true;
			}
			if(!flag){
				printf("Death\n");
				continue;
			}
			ans = 0;
			for(int i=a; i<=b; i++){
				minn = Inf;
				for(int j=0; j<=k; j++){
					if(s[j] == 0 && minn > (i^j)){
						minn = i^j;
					}
				}
				ans += minn;
			}
			printf("%d\n", ans);
		}
		else if(opt == 1){
			for(int i=a; i<=b; i++) s[i] = 1;
		}
		else{
			for(int i=a; i<=b; i++) s[i] = 0;
		}
	}

	return 0;
}
