#include <stdio.h>

int main(){
	double r, h, pi = 3.14159;
	printf("输入圆半径r：");
	scanf("%lf", &r);
	printf("输入圆周长h：");
	scanf("%lf", &h);
	printf("圆周长为%.2lf\n", pi*r*2);
	printf("圆面积为%.2lf\n", pi*r*r);
	printf("圆球表面积为%.2lf\n", pi*r*r*4);
	printf("圆球体积为%.2lf\n", 3*pi*r*r*r/4.0);
	printf("圆柱体积为%.2lf\n", pi*r*r*h);

	return 0;
}
