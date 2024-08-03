#include <cstdio>
#include <iostream>

int main(){
	int t, n, m;
	scanf("%d", &t);
	for(int i=0; i<t; i++){
		scanf("%d %d", &n, &m);
		if(n == 0){
			if(m & 1){
				printf("No\n");
			}
			else{
				printf("Yes\n");
			}
		}
		else{
			if(m & 1){
				printf("Yes\n");
			}
			else{
				printf("No\n");
			}
		}
	}

	return 0;
}
