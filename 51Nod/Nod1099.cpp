#include <cstdio>
#include <iostream>
#include <algorithm>

const int Max=100005;
struct Node{
	int r, o, p;
}a[Max];
int old, now, n;
bool cmp(Node x, Node y) { return x.p>y.p; }

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d%d", &a[i].r, &a[i].o);
		a[i].p=a[i].r-a[i].o;
	}
	std::sort(a, a+n, cmp);
	for(int i=0; i<n; i++){
		old=now+a[i].r;
		now+=a[i].o;
	}
	printf("%d", old);

	return 0;
}
