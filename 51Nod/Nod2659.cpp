#include <cstdio>
#include <iostream>

const int Max=50005;
int a[Max];
void init(int);
void merge(int, int);
void check(int, int);
int root(int);

int main(){
	freopen("data.in", "r", stdin);

	int n, m, mode, x, y;
	scanf("%d %d", &n, &m);
	init(n);
	for(int i=0; i<m; i++){
		scanf("%d %d %d", &mode, &x, &y);
		if(mode==1) merge(x, y);
		if(mode==2) check(x, y);
	}

	return 0;
}

void init(int len){
	for(int i=1; i<=len; i++) a[i]=i;
}

void merge(int x, int y){
	int i=root(x), j=root(y);
	a[i]=a[j];
}

void check(int x, int y){
	int i=root(x), j=root(y);
	if(i==j) printf("Yes\n");
	else printf("No\n");
}

int root(int n){
	if(a[n]==n) return n;
	return a[n]=root(a[n]);
}
