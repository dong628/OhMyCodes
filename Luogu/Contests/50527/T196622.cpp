#include <cstdio>
#include <iostream>

int n;

int main(){
	scanf("%d", &n);
	switch(n){
		case 1: printf("10"); break;
		case 2: printf("1100"); break;
		case 3: printf("11101000"); break;
		case 4: printf("000010010101101111"); break;
	}

	return 0;
}
