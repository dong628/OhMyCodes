#include <cstdio>
#include <iostream>

const int Maxn = 605;

int main(){
	freopen("major1.in", "r", stdin);
	freopen("major.in", "w", stdout);
	int n, q, a, x, y, m, ty, x1, x2, x3;
	srand(time(0));
	scanf("%d %d", &n, &q);
	printf("%d %d\n", n, q);
	for(int i=0; i<n; i++){
		scanf("%d", &a);
		printf("%d ", a);
		for(int j=0; j<a; j++){
			scanf("%d", &x);
			printf("%d ", (rand()%2)+1);
		}
		printf("\n");
	}
	for(int i=0; i<q; i++){
		scanf("%d", &ty);
		printf("%d ", ty);
		if(ty == 1){
			scanf("%d %d", &x, &y);
			printf("%d %d\n", x, (rand()%2)+1);
		}
		if(ty == 2){
			scanf("%d", &x);
			printf("%d\n", x);
		}
		if(ty == 3){
			scanf("%d", &m);
			printf("%d ", m);
			for(int j=0; j<m; j++){
				scanf("%d", &x);
				printf("%d ", x);
			}
			printf("\n");
		}
		if(ty == 4){
			scanf("%d %d %d", &x1, &x2, &x3);
			printf("%d %d %d\n", x1, x2, x3);
		}
	}

	return 0;
}
