#include <cstdio>
#include <iostream>
#include <algorithm>

const int Maxn=1005;
struct Dc{
	int left, right;
}dc[Maxn];
bool cmp(Dc x, Dc y){
	return x.left*x.right < y.left*y.right;
}
void calc(void);
long long ans, p[Maxn];
int n, a, b;

int main(){
	scanf("%d %d %d", &n, &a, &b);
	for(int i=0; i<n; i++){
		scanf("%d %d", &dc[i].left, &dc[i].right);
	}
	std::sort(dc, dc+n, cmp);
	calc();

	return 0;
}

void calc(void){
	long long tmp, max;
	p[0]=a;
	for(int i=1; i<n; i++){
		p[i]=p[i-1]*dc[i-1].left;
	}
	max=p[0]/dc[0].right;
	for(int i=1; i<n; i++){
		tmp=p[i]/dc[i].right;
		max=tmp>max?tmp:max;
	}
	printf("%lld", max);
}
