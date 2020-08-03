#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>

const int MAX=1005;
int n, cnt;
double d, pos=double(-0x7fffffff);
struct Island{
	double x, y, l, r;
} a[MAX];
bool cmp(Island x, Island y) { return x.l<y.l; }

int main(){
	freopen("data.in", "r", stdin);
	
	scanf("%d %lf", &n, &d);
	for(int i=0; i<n; i++){
		scanf("%lf %lf", &a[i].x, &a[i].y);
		if(a[i].y>d){
			printf("-1");
			return 0;
		}
		a[i].l = a[i].x-sqrt(d*d-a[i].y*a[i].y);
		a[i].r = a[i].x+sqrt(d*d-a[i].y*a[i].y);
	}
	std::sort(a, a+n, cmp);
	for(int i=0; i<n; i++){
		if(a[i].l>pos){
			pos=a[i].r;
			cnt++;
		}
		else{
			pos=std::min(a[i].r, pos);
		}
	}
	printf("%d", cnt);
	
	return 0;
}
