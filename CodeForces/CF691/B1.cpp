#include <cstdio>
#include <iostream>

int n;
int mpow(int x, int b){
	int ans=1;
	for(int i=0; i<b; i++) ans*=x;
	return ans;
}

int main(){
	scanf("%d", &n);
	if(n&1) printf("%d", (n/2+1)*(n/2+2)*2);
	else printf("%d",((n>>1)+1)*((n>>1)+1));

	return 0;
}
