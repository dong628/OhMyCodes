#include <cstdio>
#include <iostream>

const int Max=30000;
int s[Max+5];
void merge(int, int);
void check(int, int);
inline int abs(int x) { return x<0?-x:x; }

int main(){
	freopen("data.in", "r", stdin);

	char mode;
	int t, a, b;
	scanf("%d\n", &t);
	for(int i=0; i<=Max; i++) s[i]=i;
	for(int i=0; i<t; i++){
		scanf("%c %d %d\n", &mode, &a, &b);
		switch(mode){
			case 'M' : merge(a, b); break;	
			case 'C' : check(a, b); break;	
		}
	}

	return 0;
}

void merge(int x, int y){
	int i, j;
	for(i=s[x]; i!=s[i]; i=s[i]);
	for(j=s[y]; j!=s[j]; j=s[j]);
	s[i]=j;
}

void check(int x, int y){
	int i, j, cnti=0, cntj=0;
	for(i=s[x]; i!=s[i]; i=s[i]) cnti++;
	for(j=s[y]; j!=s[j]; j=s[j]) cntj++;
	if(i==j) printf("%d\n", abs(cnti-cntj));
	else printf("-1\n");
}
