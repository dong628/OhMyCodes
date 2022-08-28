#include <cstdio>
#include <iostream>
#include <cmath>

int vct[5];

int main(){
	int x0, y0, x1, y1, x2, y2, x3, y3, cnt0, cntn;
	bool flag;
	int ans = 1;
	
	scanf("%d %d", &x0, &y0);
	scanf("%d %d", &x1, &y1);
	scanf("%d %d", &x2, &y2);
	scanf("%d %d", &x3, &y3);
	vct[1] = (y1-y0)*(y0-y3)+(x1-x0)*(x0-x3);
	vct[2] = (y2-y1)*(y1-y0)+(x2-x1)*(x1-x0);
	vct[3] = (y3-y2)*(y2-y1)+(x3-x2)*(x2-x1);
	vct[4] = (y0-y3)*(y3-y2)+(x0-x3)*(x3-x2);
	a[1] = vct[1]/()
	flag = true;
	for(int i=1; i<5; i++) ans *= vct[i];
	for(int i=1; i<5; i++) if(vct[i]==0) cnt0++;
	for(int i=1; i<5; i++) if(vct[i]<0) cntn++;
	if(cntn>=3) flag = false;
	if(flag) printf("Yes");
	else printf("No");

	return 0;
}
