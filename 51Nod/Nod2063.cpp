#include <cstdio>
#include <iostream>

const int Max=100005;
void lb(int);
int n, q, a[Max];

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	int x;
	scanf("%d", &q);
	for(int i=0; i<q; i++){
		scanf("%d", &x);
		lb(x);
	}

	return 0;
}

void lb(int x){
	int l=0, r=n, mid;
	while(l<r){
		mid=(l+r)>>1;
		if(a[mid]>=x) r=mid;
		else l=mid+1;
	}
	if(a[l]==x) printf("Yes\n");
	else printf("No\n");
}

