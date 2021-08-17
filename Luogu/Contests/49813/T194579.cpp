#include <cstdio>
#include <iostream>

int table[8][8] = {
	{1, 0, 0, 0, 0, 0, 0, 0},
	{1, 1, 0, 0, 0, 0, 0, 0},
	{1, 1, 2, 0, 0, 0, 0, 0},
	{1, 1, 2, 2, 0, 0, 0, 0},
	{1, 3, 2, 2, 1, 0, 0, 0},
	{1, 3, 2, 2, 1, 3, 0, 0},
	{1, 3, 2, 2, 1, 3, 1, 0},
	{1, 3, 2, 4, 1, 3, 2, 4},
};
int cnt[8] = {1, 1, 2, 2, 3, 3, 3, 4};
int n;

int main(){
	scanf("%d", &n);
	if(n<=8){
		printf("%d\n", cnt[n-1]);
		for(int i=0; i<n; i++){
			printf("%d ", table[n-1][i]);
		}
	}
	else{
		printf("4\n");
		for(int i=0; i<n; i++){
			printf("%d ", (i%4)+1);
		}
	}

	return 0;
}
