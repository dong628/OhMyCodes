#include <cstdio>
#include <iostream>
#include <algorithm>

const int Max=100005;
int n, nt, summ;
struct Node{
	int a, b;
}p[Max];
bool cmp(Node x, Node y) { return x.a>y.a; }

int main(){
	freopen("data.in", "r", stdin);
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d%d", &p[i].a, &p[i].b);
	}
	std::sort(p, p+n, cmp);
	for(int i=0; i<n; i++){
		nt+=p[i].b;
		summ+=p[i].a*nt;
	}
	printf("%d", summ);

	return 0;
}
