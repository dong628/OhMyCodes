#include <cstdio>
#include <iostream>

const int MAX=30005;
int a[MAX], n, tmp[MAX], m, mode, l, r, x;
long long ans;

void MergeSort(int*, int);

int main(){
	freopen("data.in", "r", stdin);
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
	}
	for(int k=0; k<m; k++){
		scanf("%d", &mode);
		if(mode==1){
			scanf("%d %d %d", &l, &r, &x);
			for(int i=l; i<=r; i++){
				a[i]=x; x++;
			}
		}
		else{
			for(int i=1; i<=n; i++){
				tmp[i]=a[i];
			}
			ans=0;
			MergeSort(tmp+1, n);
			printf("%d\n", ans);
		}
	}

	return 0;
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
