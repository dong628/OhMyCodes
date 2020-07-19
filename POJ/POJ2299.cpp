#include <cstdio>
#include <iostream>
#define MAX 500005

int a[MAX], n;
long long ans;

void MergeSort(int*, int);

int main(){
	freopen("data.in", "r", stdin);
	for( ; ; ){
		ans=0;
		scanf("%d", &n);
		if(n==0) return 0;
		for(int i=0; i<n; i++) scanf("%d", &a[i]);
		MergeSort(a, n);
		printf("%lld\n", ans);
	}
}

void MergeSort(int *arr, int len){
	if(len==1) return;

	int *l=arr, *r=arr+len/2;
	int ls=len/2, rs=len-len/2;
	MergeSort(l, ls);
	MergeSort(r, rs);

	int i=0, j=0, ts=0;
	int temp[MAX];
	while(i<ls && j<rs){
		if(l[i]>r[j]){
			temp[ts++] = r[j++];
			ans += ls-i;
		}
		else temp[ts++] = l[i++];
	}
	while(j<rs) temp[ts++] = r[j++];
	while(i<ls) temp[ts++] = l[i++];
	for(int x=0; x<ts; x++){
		arr[x] = temp[x];
	}
}
