#include <cstdio>
#include <iostream>

const int Inf=0x7fffffff, Maxm=2e3+5, Maxn=1e6+5;
int ansl=Inf, minl=Inf, ansr, hash[Maxm], a[Maxn], summ, tar, n, m;

int main(){
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
	}
	tar=(1+m)*m/2;
	int l=1;
	for(int r=1; r<=n; r++){
		if(hash[a[r]]==0){
			summ+=a[r];
		}
		hash[a[r]]++;
		if(summ==tar){
			for( ; hash[a[l]]>1; l++){
				hash[a[l]]--;
			}
			if(minl>r-l){
				ansr=r; ansl=l;
				minl=r-l;
			}
			else if(minl==r-l){
				if(ansl>l){
					ansr=r; ansl=l;
				}
			}
		}
	}
	printf("%d %d", ansl, ansr);

	return 0;
}
