#include <cstdio>
#include <iostream>

const int Maxn = 5e5+5;
int n, fa[Maxn], val[Maxn], ans;

int main(){
	scanf("%d", &n);
	for(int i=2; i<=n; i++){
		scanf("%d", &fa[i]);
	}
	for(int i=1; i<=n; i++){
		scanf("%d", &val[i]);
	}
	if(n==1){
		printf("0\n");
		return 0;
	}
	if(n==2){
		printf("0\n0\n");
		return 0;
	}
	printf("0\n0\n");
	ans = val[1]^val[2];
	printf("%d\n", ans);
	for(int i=4; i<=n; i++){
		for(int j=1; j<i-1; j++){
			if((val[i-1]^val[j])>ans) ans = val[i-1]^val[j];
		}
		printf("%d\n", ans);
	}

	return 0;
}
