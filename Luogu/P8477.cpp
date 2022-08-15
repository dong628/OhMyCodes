#include <cstdio>
#include <iostream>

int main(){
	int n, r1s, r1e, r2s, r2e, l1s, l1e, l2s, l2e, l3s, l3e, lb, rb;
	int extra;
//	disp n r1s r1e r2s r2e l1s l1e l2s l2e l3s l3e lb rb;

	scanf("%d", &n);
	if(n%2){
		r1s = 1; r1e = n/2+1;
		r2s = r1e+1; r2e = n;
		rb = n/2+1;
	}
	else{
		r1s = 1; r1e = n/2;
		r2s = r1e+1; r2e = n;
		rb = n/2;
	}
	if(n%3 == 0){
		l1s = 1; l1e = n/3;
		l2s = l1e+1; l2e = 2*l1e;
		l3s = l2e+1; l3e = n;
		lb = n/3;
	}
	else if(n%3 == 1){
		l1s = 1; l1e = n/3+1;
		l2s = l1e+1; l2e = l1e+n/3;
		l3s = l2e+1; l3e = n;
		lb = n/3+1;
	}
	else{
		l1s = 1; l1e = n/3+1;
		l2s = l1e+1; l2e = l1e*2;
		l3s = l2e+1; l3e = n;
		lb = n/3+1;
	}
	extra = l2e+r1e+1;
	printf("%d\n", extra);
	for(int i=l1s; i<=l2e; i++){
		for(int j=r1s; j<=r1e; j++){
			printf("2 %d %d %d %d\n", i, i, j+l2e, j);
		}
	}
	for(int i=l3s; i<=l3e; i++){
		for(int j=r1s; j<=r1e; j++){
			printf("3 %d %d %d %d %d\n", i, -(i-l2e+l2s-1), extra, j+l2e, j);
		}
	}
	for(int i=l1s; i<=l1e; i++){
		for(int j=r2s; j<=r2e; j++){
			printf("3 %d %d %d %d %d\n", i, i, -extra, -(j+l2e-rb), j);
		}
	}
	for(int i=l3s; i<=l3e; i++){
		for(int j=r2s; j<=r2e; j++){
			printf("2 %d %d %d %d\n", i, -(i-l2e+l2s-1), -(j+l2e-rb), j);
		}
	}
	for(int i=l2s; i<=l2e; i++){
		for(int j=r2s; j<=r2e; j++){
			printf("2 %d %d %d %d\n", i, -(i-lb), -(j+l2e-rb), j);
		}
	}

	return 0;
}
