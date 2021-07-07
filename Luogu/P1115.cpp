#include <cstdio>
#include <iostream>

int n, a, summ, maxx=-0x7fffffff;

int main(){
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &a);
		summ+=a;
		maxx=maxx>summ?maxx:summ;
		if(summ<0) summ=0;
	}
	printf("%d", maxx);

	return 0;
}
