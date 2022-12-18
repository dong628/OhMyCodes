#include <cstdio>
#include <iostream>
#include <cstring>

const int Inf = 0x3f3f3f3f, Maxn = 1e5+5;
int n, k, cow[Maxn];
char sol[Maxn];
void solve(void);

int main(){
//	freopen("data.in", "r", stdin);
	
	char ch;
	int t, l, r, mid;
	scanf("%d", &t);
	while(t-->0){
		scanf("%d %d\n", &n, &k);
		for(int i=1; i<=n; i++){
			ch = getchar();
			cow[i] = (ch == 'G' ? 1 : 2);
		}
/*
		l = 0; r = n;
		while(l < r){
			mid = (l + r) >> 1;
			if(calc(mid)) r = mid;
			else l = mid + 1;
		}
*/
		solve();
	}

	return 0;
}

void solve(void){
	memset(sol, 0, sizeof(sol));
	int lasg = -Inf, lash = -Inf, cnt = 0;
	for(int i=1; i<=n; i++){
		if(cow[i] == 1){
			if(abs(i - lasg) > k){
				if(i + k <= n){
					sol[i + k] = 'G';
					cnt++;
					lasg = i + k;
				}
				else{
					for(int j=n; j>=i-k; j--){
						if(sol[j] == 0 || sol[j] == '.'){
							sol[j] = 'G';
							cnt++;
							lasg = j;
							break;
						}
					}
				}
			}
		} 
		else{
			if(abs(i - lash) > k){
				if(i + k <= n){
					sol[i + k] = 'H';
					cnt++;
					lash = i + k;
				}
				else{
					for(int j=n; j>=i-k; j--){
						if(sol[j] == 0 || sol[j] == '.'){
							sol[j] = 'H';
							cnt++;
							lash = j;
							break;
						}
					}
				}
			}
		}
	}

	printf("%d\n", cnt);
	for(int i=1; i<=n; i++) if(sol[i] == 0) sol[i] = '.';
	for(int i=1; i<=n; i++) putchar(sol[i]);
	putchar('\n');
}
