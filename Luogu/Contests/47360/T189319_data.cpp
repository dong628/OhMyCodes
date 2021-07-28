#include <iostream>
#include <cstdio>

int t, n;
int data[9]={0, 5, 45, 349, 2749, 21495, 167143, 1294015, 9981491};

int main(){
	scanf("%d", &t);
	for(int i=0; i<t; i++){
		scanf("%d", &n);
		printf("%d\n", data[n/5]);
	}

	
	return 0;
}
