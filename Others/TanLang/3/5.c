#include <stdio.h>

int main(){
	char a, b, c;
	printf("请输入三个字符，使用空格分隔：");
	scanf("%c %c %c", &a, &b, &c);
	printf("平均值为%lf", ((double)(a+b+c))/3);

	return 0;
}
