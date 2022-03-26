#include <cstdio>
#include <iostream>
#include <bitset>

const int Maxn = 1e5+5;
std::bitset<Maxn> bset[Maxn];
int n, t, x, k[Maxn];
bool flag;

int main(){
	freopen("discuss.in", "r", stdin);
	freopen("discuss.out", "w", stdout);

	scanf("%d", &t);
	for(int cst=0; cst<t; cst++){
		scanf("%d", &n);
		for(int i=1; i<=n; i++){
			scanf("%d", &k[i]);
			for(int j=1; j<=k[i]; j++){
				scanf("%d", &x);
				bset[i][x] = 1;
			}
		}
		flag = false;
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				if(((bset[i]&bset[j]).any())==true && (bset[i]|bset[j])!=bset[i] && (bset[i]|bset[j])!=bset[j]){
					flag = true;
					printf("YES\n%d %d\n", i, j);
					break;
				}
			}
			if(flag) break;
		}
		if(flag == false){
			printf("NO\n");
		}
	}

	return 0;
}
