/*
  Author: EnderDeer
  Online Judge: Luogu
*/

#include<bits/stdc++.h>

#define int long long
#define mem(x) memset(x,0,sizeof(x))

using namespace std;

int read(){
   int s = 0,w = 1;
   char ch = getchar();
   while(ch < '0' || ch > '9'){if(ch == '-')w = -1;ch = getchar();}
   while(ch >= '0' && ch <= '9')s = s * 10 + ch - '0',ch = getchar();
   return s * w;
}

int n,m;
int l[1000010],r[1000010];
int block,len;
int num[1000010];
int a[1000010],b[1000010]; 
int lazy[1000010];

void update(int x,int y,int w){
	int posl = num[x];
	int posr = num[y];
	if(posl == posr){
		for(int i = x;i <= y;i ++)a[i] += w;
		for(int i = l[posl];i <= r[posl];i ++)b[i] = a[i];
		sort(b + l[posl],b + r[posl] + 1);
		return ;
	}
	for(int i = x;i <= r[posl];i ++)a[i] += w;
	for(int i = l[posl];i <= r[posl];i ++)b[i] = a[i];
	sort(b + l[posl],b + r[posl] + 1);
	for(int i = posl + 1;i <= posr - 1;i ++)lazy[i] += w;
	for(int i = l[posr];i <= y;i ++)a[i] += w;
	for(int i = l[posr];i <= r[posr];i ++)b[i] = a[i];
	sort(b + l[posr],b + r[posr] + 1);
}

int check(int x,int y,int w){
	int posl = num[x];
	int posr = num[y];
	int cnt = 0;
	if(posl == posr){
		for(int i = x;i <= y;i ++){
			if(a[i] + lazy[posl] <= w)cnt ++;
		}
		return cnt;
	}
	for(int i = x;i <= r[posl];i ++){
		if(a[i] + lazy[posl] <= w)cnt ++;
	}
	for(int i = num[x] + 1;i <= num[y] - 1;i ++){
		int ll = l[i],rr = r[i],mid;
		if(b[l[i]] + lazy[i] > w)continue;
		if(b[r[i]] + lazy[i] <= w){
			cnt += r[i] - l[i] + 1;
			continue;
		}
		while(ll < rr){
			mid = (ll + rr) / 2 + 1;
			if(b[mid] + lazy[i] <= w)ll = mid;
			else rr = mid - 1;
		}
		if(b[ll] + lazy[i] <= w)cnt += ll - l[i] + 1;
	}
	for(int i = l[posr];i <= y;i ++){
		if(a[i] + lazy[posr] <= w)cnt ++;
	}
	return cnt;
}

int getmin(int x,int y){
	int posl = num[x];
	int posr = num[y];
	int ans = 2147483647;
	if(posl == posr){
		for(int i = x;i <= y;i ++)ans = min(ans,a[i] + lazy[num[i]]);
		return ans;
	}
	for(int i = x;i <= r[posl];i ++)ans = min(ans,a[i] + lazy[num[i]]);
	for(int i = posl + 1;i <= posr - 1;i ++)ans = min(ans,b[l[i]] + lazy[i]);
	for(int i = l[posr];i <= y;i ++)ans = min(ans,a[i] + lazy[num[i]]);
	return ans;
}

int getmax(int x,int y){
	int posl = num[x];
	int posr = num[y];
	int ans = -2147483647;
	if(posl == posr){
		for(int i = x;i <= y;i ++)ans = max(ans,a[i] + lazy[num[i]]);
		return ans;
	}
	for(int i = x;i <= r[posl];i ++)ans = max(ans,a[i] + lazy[num[i]]);
	for(int i = posl + 1;i <= posr - 1;i ++)ans = max(ans,b[r[i]] + lazy[i]);
	for(int i = l[posr];i <= y;i ++)ans = max(ans,a[i] + lazy[num[i]]);
	return ans;
}

int query(int x,int y,int k){
	if(k < 1 || k > y - x + 1) return -1;
	int posl = num[x];
	int posr = num[y];
	int ans = -1;
	int l,r,mid;
	l = getmin(x,y);
	r = getmax(x,y);
	while(l <= r){
		mid = (l + r) / 2;
		if(check(x,y,mid) < k)l = mid + 1;
		else {
			r = mid - 1;
			ans = mid;
		}
	}
	return ans;
} 

signed main(){
	freopen("data.in", "r", stdin);
	
	cin>>n>>m;
	block = 150;
	len = ceil(n * 1.0 / block);
	for(int i = 1;i <= n;i ++){
		a[i] = read();
		b[i] = a[i];
		num[i] = (i - 1) / block + 1;
	}
	for(int i = 1;i <= len;i ++){
		l[i] = (i - 1) * block + 1;
		r[i] = i * block;
	}
	r[len] = n;
	for(int i = 1;i <= len;i ++)sort(b + l[i],b + r[i] + 1);
	while(m --){
		int op,x,y,w;
		op = read();
		x = read(),y = read(),w = read();
		if(op == 1){
			printf("%lld\n",query(x,y,w));
		}
		else {
			update(x,y,w);
		}
	}
	return 0;
}

