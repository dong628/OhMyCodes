#include <cstdio>
#include <iostream>

int main(){
	int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	printf("%d\n", *(a+4));

	int *p = (int *)malloc(10*sizeof(int));
	for(int i=0; i<10; i++){
		p[i]=i;
	}
	printf("%d\n", p[4]);
	printf("%p\n", &p[4]);
	printf("%d\n", p[1100]);
	printf("%p\n", &p[1100]);

	return 0;
}
