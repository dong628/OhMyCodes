#include <cstdio>

const int Max=605;
int c[Max], n;

int main(){
	c[0]=1; c[1]=1; c[2]=2; c[3]=5;
	scanf("%d", &n);
	for(int i=4; i<=n; i++){
		for(int j=1; j<=i; j++) c[i]+=c[j-1]*c[i-j];
	}
	printf("%d", c[n]);

	return 0;
}
