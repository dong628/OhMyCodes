#include <cstdio>
#include <iostream>

const int Maxn = 205;
int t, n, m, x, y, z;

int main(){
//	freopen("data.in", "r", stdin);

	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &m);
		scanf("%d %d %d", &x, &y, &z);
		if(m == 1 && z == 0){
			printf("0\n");
		}
		else if(m == 1 && z == 1){
			printf("A 1\n");
		}
	}

	return 0;
}
