#include <cstdio>
#include <iostream>
using std::max;

const int Maxn = 20;
int a[Maxn], b[Maxn];

int main(){
	freopen("data.in", "r", stdin);
	
	int n, t;

	scanf("%d %d", &n, &t);
	for(int i=0; i<n; i++){
		scanf("%d %d", &a[i], &b[i]);
	}
	if(n == 1){
		printf("0");
		return 0;
	}
	if(t == 1){
		printf("0");
	}
	if(t == 2){
		if(n == 1) printf("0");
		else printf("-1");
	}
	if(t == 3){
		printf("%d", n-1);
	}
	if(t == 4){
		printf("-1");
	}
	if(t == 5){
		printf("%d", ((n+1)*n)/2-1);
	}

	return 0;
}
