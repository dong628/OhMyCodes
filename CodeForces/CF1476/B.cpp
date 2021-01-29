#include <cstdio>
#include <iostream>
using namespace std;

int t, n, k;
long long ans, summ, tmp, p;

int main(){
	scanf("%d", &t);
	for(int co=0; co<t; co++){
		ans=0; summ=0;
		scanf("%d %d", &n, &k);
		for(int co1=0; co1<n; co1++){
			scanf("%lld", &p);
			if(co1!=0){
				tmp=(p*100+k-1)/k;
				if(tmp>summ){
					ans+=tmp-summ;
					summ=tmp;
				}
			}
			summ+=p;
		}
		printf("%lld\n", ans);
	}


	return 0;
}
