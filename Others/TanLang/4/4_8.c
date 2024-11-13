#include <stdio.h>

int main(){
	int x;
	printf("请输入成绩：");
	scanf("%d", &x);
	if(x<60){
		printf("E");
	}
	else if(x<70){
		printf("D");
	}
	else if(x<80){
		printf("C");
	}
	else if(x<90){
		printf("B");
	}
	else{
		printf("A");
	}

	return 0;
}
