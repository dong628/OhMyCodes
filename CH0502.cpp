#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAX 100005
using namespace std;

int n, m, t, flag, row[MAX], col[MAX], s[MAX], x, y, l, r, ans;

int main(){
	freopen("data.in", "r", stdin);
	
	scanf("%d %d %d", &n, &m, &t);
	if(t%m){
		if(t%n) { printf("impossible"); return 0; }
		else { printf("row "); flag=1; }
	}
	else if(t%n) { printf("column "); flag=2; }
	else { printf("both "); flag=3; }

	for(int i=0; i<t; i++){
		scanf("%d %d", &x, &y);
		row[x]++;
		col[y]++;
	}
	if(flag&1){
		s[0]=row[0]-t/n;
		for(int i=1; i<n; i++) s[i]=s[i-1]+row[i];
		sort(s, s+n);
		for(int i=0; i<n/2; i++) l+=s[i];
		for(int i=n/2; i<n; i++) r+=s[i];
		if(n&1) r-=s[n/2];
		ans += r-l;
	}
	l=0; r=0;
	if(flag>=2){
		s[0]=col[0]-t/m;
		for(int i=1; i<m; i++) s[i]=s[i-1]+col[i];
		sort(s, s+m);
		for(int i=0; i<m/2; i++) l+=s[i];
		for(int i=m/2; i<m; i++) r+=s[i];
		if(m&1) r-=s[m/2];
		ans += r-l;
	}
	printf("%d", ans);
	
	return 0;
}
