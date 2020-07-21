#include <cstdio>
#include <iostream>

int dw, n;

int main(){
//	freopen("data.in", "r", stdin);
	while(true){
		dw=3;
		for(int i=0; i<10; i++){
			if(scanf("%d", &n)==EOF) return 0;
			if(n==1 && dw!=7) dw++;
			if(n==7 && dw!=1) dw--;
		}
		if(dw==7) printf("666\n");
		else printf("777\n");
	}

	return 0;
}
