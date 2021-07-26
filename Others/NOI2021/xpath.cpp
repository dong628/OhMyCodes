#include <cstdio>
#include <iostream>

int main(){
	scanf("%d", &t);
	for(int cs=0; cs<t; cs++){
		scanf("%d", &k);
		for(int i=1; i<=k; i++){
			scanf("%d", &n[i]);
		}
		for(int i=1; i<k; i++){
			scanf("%d", &m[i]);
		}
		for(int i=1; i<k; i++){
			for(int j=1; j<=m[i]; j++){
				scanf("%d %d", &u[i][j], &v[i][j]);
			}
		}


	}

	return 0;
}
