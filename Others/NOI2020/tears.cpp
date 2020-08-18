#include <cstdio>
#include <iostream>

const int Max=100005;
long long nxd;
int a[Max], n, m, arr[Max], temp[Max];
void MergeSort(int*, int);
long long jc(int);
void search(int, int, int, int);

int main(){
	freopen("tears.in", "r", stdin);
	freopen("tears.out", "w", stdout);
	int x1, x2, y1, y2;
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
	}
	for(int i=0; i<m; i++){
		scanf("%d %d %d %d", &x1, &x2, &y1, &y2);
		search(x1, y1, x2, y2);
	}

	return 0;
}

void search(int x1, int y1, int x2, int y2){
	int cnt=0;
	for(int i=x1; i<=x2; i++){
		if(a[i]>=y1 && a[i]<=y2){
			arr[cnt++]=a[i];
		}
	}
	nxd=0;
	MergeSort(arr, cnt);
	printf("%lld\n", nxd);
}

long long jc(int x){
	long long ans=1;
	for(int i=1; i<=x; i++) ans*=i;
	return ans;
}

void MergeSort(int *arr, int len){
	if(len<=1) return;

	int *l=arr, *r=arr+len/2;
	int ls=len/2, rs=len-len/2;
	MergeSort(l, ls);
	MergeSort(r, rs);

	int i=0, j=0, ts=0;
	while(i<ls && j<rs){
		if(l[i]<r[j]){
			temp[ts++] = r[j++];
			nxd += ls-i;
		}
		else temp[ts++] = l[i++];
	}
	while(j<rs) temp[ts++] = r[j++];
	while(i<ls) temp[ts++] = l[i++];
	for(int x=0; x<ts; x++){
		arr[x] = temp[x];
	}
}
