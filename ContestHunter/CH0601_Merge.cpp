#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using std::vector;
using std::min;
using std::sort;

const int MAX=500005;
int k, n, m, s;
long long o[MAX], ne[MAX], ne1[MAX];
long long t, a[MAX], b[MAX];

void merge(int);
int genius(void);
long long check(int, int);

int main(){
	freopen("data.in", "r", stdin);
	
	scanf("%d", &k);
	for(int i=0; i<k; i++){
		scanf("%d%d%lld", &n, &m, &t);
		for(int i=0; i<n; i++){
			scanf("%lld", &a[i]);
		}
		printf("%d\n", genius());
	}
	
	return 0;
}

int genius(){
	int r=0, ans=0, l, p;
	long long ch;
	while(r<n){
		if(r==n-1){
			ans++; break;
		}
		l=r; p=1;
		memset(ne, 0, sizeof(ne));
		memset(o, 0, sizeof(o));
//		ne.clear(); o.clear();
		while(p!=0 && r<n){
			ch = check(r, p);
			if(ch<=t){
				r+=p; p*=2;
				for(int i=0; i<n; i++) o[i]=ne[i];
			}
			else p/=2;
		}
		ans++;
	}
	return ans;
}

long long check(int r, int p){
//	ne=o;
	for(int i=0; i<n; i++) ne[i]=o[i];
	int l, r1, mid, le=0;
	for(int i=r; i<min(r+p, n); i++){
		b[le++]=a[i];
	}
	sort(b, b+le);
	merge(le);
/*	for(int i=r; i<min(r+p, n); i++){
		l=0; r1=ne.size();
		while(l<r1){
			mid=(l+r1)>>1;
			if(ne[mid]>=a[i]) r1=mid; 
			else l=mid+1;
		}
		ne.insert(ne.begin()+l, a[i]);
	}*/
//	int s=ne.size();
	long long ans=0;
	for(int i=0; i<m; i++){
		if(s>=(i+1)*2){
			ans+=(ne[i]-ne[s-i-1])*(ne[i]-ne[s-i-1]);
		}
	}
	return ans;
}

void merge(int le){
	int l=0, r=0, ls=0;
	while(l<s && r<le){
		if(ne[l]<=b[r]){
			ne1[ls++]=ne[l++];
		}
		else ne1[ls++]=b[r++];
	}
	while(l<s) ne1[ls++]=ne[l++];
	while(r<le) ne1[ls++]=b[r++];
	for(int i=0; i<ls; i++){
		ne[i]=ne1[i];
	}
	s=ls;
}
