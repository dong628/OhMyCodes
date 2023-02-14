#include <cstdio>
#include <iostream>

struct Node{
	int l, r, num;
	Node(int l, int r, int num) : l(l), r(r), num(num) {}
} q[Maxn];
bool cmp1(Node x, Node y){
	if(x.r == y.r) return x.l > y.l;
	return x.r > y.r;
}
bool cmp2(Node x, Node y){
	return x.l > y.l;
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++){
		scanf("%d", &c[i]);
	}

	for(int i=1; i<=m; i++){
		scanf("%d %d", &l, &r);
		q[i] = Node(l, r, num);
	}

	block = sqrt(m); cntb = m / block;
	std::sort(q+1, q+1+m, cmp1);
	for(int i=0; i<cntb; i++){
		std::sort(q+i*block+1, q+i*block+1+block, cmp2);
	}
	if(m % block){
		std::sort(q+(cntb-1)*block+1, q+1+m, cmp2);
		cntb++;
	}

	int lastl = 0, lastr = 0;
	for(int i=1; i<=m; i++){
		
	}

	return 0;
}
