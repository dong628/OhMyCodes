#include <cstdio>
#include <iostream>

const int Max=1e5+5;
int r, n, k, s[Max];
bool calc(int);

int main(){
	scanf("%d %d %d", &r, &n, &k);
	for(int i=0; i<n; i++){
		scanf("%d", &s[i]);
	}
	int l=0, mid;
	while(l<r){
		mid=(l+r)>>1;
		if(calc(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d\n", l);

	return 0;
}

bool calc(int length){
	int ans=0;
	for(int i=0; i<n-1; i++){
		ans += (s[i+1]-s[i]-1)/length;
	}
	if(ans>k) return false;
	else return true;
}
