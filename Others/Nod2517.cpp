#include <cstdio>
#include <iostream>

const int Max=20005;
int a[Max], n, zero, one, last;
char x;

int main(){
	scanf("%d\n", &n);
	for(int i=0; i<n; i++){
		scanf("%c", &x);
		a[i]=x-'0';
	}
	int i;
	for(i=n-1; i>=0; i--){
		if(a[i]==0) break;
	}
	for(; i>=0; i--){
		if(a[i]==0) zero++;
		else { one++; last=i; }
	}
	printf("%d", std::min(zero-last, one));
	
	return 0;
}
