#include <cstdio>
#include <iostream>
#include <algorithm>
using std::sort;

const int Maxn = 5e5+5, Maxq = 5e5+5;
struct Quest{
	int l, r, num, ans;
} q[Maxq];
struct Node{
	int a, b;
} s[Maxn];

int cnt, n, m, now, a[Maxn], b[Maxn], top, ans, answer[Maxq], h[Maxn];

bool cmp1(Quest a, Quest b){
	if(a.l<b.l) return true;
	else if(a.l>b.l) return false;
	else return a.r<b.r;
}
int min(int xx, int yy) { return xx<yy?xx:yy; }

int main(){
	freopen("stack.in", "r", stdin);
	freopen("stack.out", "w", stdout);

	bool ta=true, tb=true;
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
		if(a[i]!=i) ta = false;
	}
	for(int i=1; i<=n; i++){
		scanf("%d", &b[i]);
		if(b[i]!=n-i+1) tb = false;
	}
	for(int i=1; i<=m; i++) scanf("%d %d", &q[i].l, &q[i].r);
	for(int i=1; i<=m; i++) q[i].num = i;

	if(tb){
		h[n] = 1;
		for(int i=n-1; i>=1; i--){
			if(a[i] == a[i+1]) cnt++;
			else cnt = 1;
			h[i] = cnt;
		}
		for(int i=1; i<=m; i++){
			printf("%d\n", min(h[q[i].l], q[i].r-q[i].l+1));
		}
	}
	else{
		sort(q+1, q+1+m, cmp1);

		for(int i=1; i<=m; i++){
			if(q[i].l != q[i-1].l){
				top = 1;
				ans = 0;
				now = q[i].l;
			}
			for( ; now<=q[i].r; now++){
				while((s[top-1].a==a[now] || s[top-1].b<=b[now]) && top!=1) top--;
				if(top==1) ans++;
				s[top].a = a[now];
				s[top].b = b[now];
				top++;
			}
			answer[q[i].num] = ans;
		}

		for(int i=1; i<=m; i++) printf("%d\n", answer[i]);
	}

	return 0;
}
