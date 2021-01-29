#include <iostream>
#include <cstdio>
using namespace std;

int n, k, t, ans, tmp;

int main(){
	scanf("%d", &t);
	for(int x=0; x<t; x++){
		scanf("%d %d", &n, &k);
		if(n>k){
			tmp=((n+k-1)/k)*k;
			ans=(tmp-1)/n+1;
		}
		else if(n==k) ans=1;
		else{
			ans=(k+n-1)/n;
		}
		printf("%d\n", ans);
	}

	return 0;
}
