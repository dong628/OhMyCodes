#include <stdio.h>

int main(){
	double x;
	printf("请输入x：");
	scanf("%lf", &x);
	if(x<1){
		printf("y = %lf", x);
	}
	else if(x<10){
		printf("y = %lf", 2*x-1);
	}
	else{
		printf("y = %lf", 3*x-11);
	}

	return 0;
}
