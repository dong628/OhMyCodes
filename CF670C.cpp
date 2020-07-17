#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAX 200005
using namespace std;

int a[MAX], b[MAX], c[MAX], z[3*MAX], lang[3*MAX], f[3*MAX];
int n, m, c1, cnt, maxx, maxy, maxi, num, y, zm;
int lb(int);

int main(){
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &num);
		a[i]=num;	z[cnt++]=num;
	}
	scanf("%d", &m);
	for(int i=0; i<m; i++){
		scanf("%d", &num);
		b[i]=num;	z[cnt++]=num;
	}
	for(int i=0; i<m; i++){
		scanf("%d", &num);
		c[i]=num;	z[cnt++]=num;
	}

	sort(z, z+cnt);
	for(int i=0; i<cnt; i++){
		if(i==0 || z[i]!=z[i-1]) lang[c1++]=z[i];
	}
	for(int i=0; i<n; i++){
		f[lb(a[i])]++;
	}
	for(int i=0; i<m; i++){
		y=f[lb(b[i])]; zm=f[lb(c[i])];
		if(maxy<y){
			maxy=y; maxi=i;
		}
		else if(maxy==y){
			if(zm>f[lb(c[maxi])]) maxi=i;
		}
	}
	printf("%d", maxi+1);
/*	for(int i=0; i<c1; i++){
		maxx=f[i]>maxx?f[i]:maxx;
	}*/
	
	return 0;
}

int lb(int x){
	int l=0, r=c1, mid;
	while(l<r){
		mid=(l+r)>>1;
		if(lang[mid]>=x) r=mid;
		else l=mid+1;
	}
	return l;
}
