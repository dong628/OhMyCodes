#include <cstdio>
#include <iostream>

const int MAX=505;
int k, n, m;
long long t, a[MAX];

int genius(void);
int check(int, int);

int main(){
	scanf("%d", &k);
	for(int i=0; i<k; i++){
		scanf("%d%d%lld", &n, &m, &t);
		for(int i=0; i<n; i++){
			scanf("%lld", &a[i]);
		}
		printf("%d", genius());
	}
	
	return 0;
}

int genius(){
	int l=0, r=l, p=1;
	while(p!=0){
		ch = check(l, r+p);
		if(ch<=t){
			r+=p; p*=2;
		}
		else p/=2;
	}
}

int check(int l, int r){
	if(l==el && r-l>=v.size()){	//MergeSort
		
	}
}
