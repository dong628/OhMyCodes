#include <cstdio>
#include <iostream>

const int Max=1e6+5;
int n, m, num, l, r, mid, a[Max];

int main(){
//	freopen("data.in", "r", stdin);

	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	for(int i=0; i<m; i++){
		scanf("%d", &num);
		l=0; r=n-1;
		while(l<r){
			mid=(l+r)>>1;
			if(a[mid]>=num) r=mid;
			else l=mid+1;
		}
		if(a[l]==num) printf("%d ", l+1);
		else printf("-1 ");
	}

	return 0;
}
