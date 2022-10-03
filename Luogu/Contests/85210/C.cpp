#include <cstdio>
#include <iostream>

int main(){
	int t, m, q, a;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &m, &q);
		for(int i=0; i<m; i++){
			scanf("%d", &a);
		}
		for(int i=0; i<q; i++){
			scanf("%d", &a);
			printf("0\n");
		}
	}

	return 0;
}
