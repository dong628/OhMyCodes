#include <cstdio>
#include <iostream>
#include <algorithm>

const int Maxn=1e5+5, Mod=1e8-3;
int n, a[Maxn], c[Maxn];
struct Node{
	int first, second;
}b[Maxn];
bool cmp(Node x, Node y) { return x.first<y.first; }
int MergeSort(int l, int r);

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%d", &b[i].first);
	}
	for(int i=1; i<=n; i++){
		scanf("%d", &b[i].second);
	}
	std::sort(b+1, b+n+1, cmp);
	for(int i=1; i<=n; i++){
		a[i] = b[i].second;
	}
	printf("%d", MergeSort(1, n)%Mod);


	return 0;
}

int MergeSort(int l, int r){
	if(l==r) return 0;
	int left = MergeSort(l, (l+r)>>1)%Mod;
	int right = MergeSort(((l+r)>>1)+1, r)%Mod;
	int lp=l, rp=((l+r)>>1)+1, cp=1;
	int cnt=0;
	while(lp<=((l+r)>>1) && rp<=r){
		while(a[lp] > a[rp] && rp<=r && lp<=((l+r)>>1)){
			c[cp++]=a[rp++];
		}
		while(a[lp] <= a[rp] && lp<=((l+r)>>1) && rp<=r){
			cnt += rp-((l+r)>>1)-1;
			cnt %= Mod;
			c[cp++]=a[lp++];
		}
	}
	while(lp<=((l+r)>>1)){
		cnt += rp-((l+r)>>1)-1;
		cnt %= Mod;
		c[cp++]=a[lp++];
	}
	while(rp<=r){
		c[cp++]=a[rp++];
	}
	for(int i=l, j=1; i<=r; i++, j++){
		a[i]=c[j];
	}
	return (cnt+left+right)%Mod;
}
