#include <cstdio>
#include <iostream>

const int Max=50005;
void MergeSort(int*, int);
int n, a[Max];
long long ans;

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	MergeSort(a, n);
	printf("%lld", ans);

	return 0;
}

void MergeSort(int *arr, int len){
	if(len==1) return;
	int *l=arr, *r=arr+len/2;
	int ls=len/2, rs=len-len/2;
	MergeSort(l, ls);
	MergeSort(r, rs);

	int i=0, j=0, ts=0, temp[Max];
	while(i<ls && j<rs){
		if(l[i]>r[j]){
			temp[ts++]=r[j++];
			ans+=ls-i;
		}
		else temp[ts++]=l[i++];
	}
	while(i<ls) temp[ts++]=l[i++];
	while(j<rs) temp[ts++]=r[j++];
	for(int x=0; x<ts; x++){
		arr[x]=temp[x];
	}
}
