#include <cstdio>
#include <iostream>

int main(){

	printf("2500 2500 6\n");

	for(int i=0; i<2500; i++){
		for(int j=0; j<2500; j++){
			printf("0");
		}
		putchar('\n');
	}

	return 0;
}
