#include <cstdio>
#include <iostream>
#define lli long long

lli phin, n, e, c, d;
int t;
lli phi(lli);

int main(){
	scanf("%d", &t);
	for(int x=0; x<t; x++){
		scanf("%lld %lld", &n, &e);
		phin = phi(n);
	//	printf("%lld", phin);
		c=1;
		while(true){
			if((c*phin+1)%e==0){
				d=(c*phin+1)/e;
				break;
			}
			else c++;
		}
		printf("%lld\n", d);
	}

	return 0;
}

lli phi(lli num){
	lli p, q;
	for(lli i=2; i<=num; i++){
		if(num%i==0){
			p=i; break;
		}
	}
	q=num/p;
	return (p-1)*(q-1);
}
