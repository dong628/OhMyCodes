#include <stdio.h>

int main(){
	int a[4], tmp;
	printf("输入四个整数：");
	for(int i=0; i<4; i++){
		scanf("%d", &a[i]);
	}
	for(int i=0; i<4; i++){
		for(int j=0; j<3; j++){
			if(a[j]>a[j+1]){
				tmp = a[j];
				a[j] = a[j+1];
				a[j+1] = tmp;
			}
		}
	}
	for(int i=0; i<4; i++){
		printf("%d ", a[i]);
	}

	return 0;
}

