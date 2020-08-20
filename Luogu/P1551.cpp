#include <cstdio>
#include <iostream>

const int Max=5005;
int s[Max];
void init(int);
void check(int, int);
void merge(int, int);
int root(int);

int main(){
	int n, m, p, a, b;
	scanf("%d %d %d", &n, &m, &p);
	init(n);
	for(int i=0; i<m; i++){
		scanf("%d %d", &a, &b);
		merge(a, b);
	}
	for(int i=0; i<p; i++){
		scanf("%d %d", &a, &b);
		check(a, b);
	}

	return 0;
}

void init(int n){
	for(int i=0; i<=n; i++) s[i]=i;
}

void check(int x, int y){
	int i=root(x), j=root(y);
	if(i==j) printf("Yes\n");
	else printf("No\n");
}

void merge(int x, int y){
	int i=root(x), j=root(y);
	s[i]=j;
}

int root(int n){
	if(s[n]==n) return n;
	else return s[n]=root(s[n]);
}
