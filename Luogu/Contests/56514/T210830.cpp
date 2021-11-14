#include <cstdio>
#include <iostream>

bool calc(int);

int main(){
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
	}
	int l=1, r=n, mid;
	while(l<r){
		mid = (l+r+1)>>1;
		if(calc(mid)){
			l=mid;
		}
		else{
			r=mid-1;
		}
	}

	return 0;
}

bool calc(int x){
	for(int i=1; i<=x; i++){
		cnt[a[i]]++;
		if(cnt[a[i]]==1){
			ans++;
		} 
	}
}
