#include <iostream>
#include <cstdio>
#include <cmath>
#define int long long

const int Maxn = 1e5+5, Maxu = 1e3+5, Mod = 19260817;
//const int Maxn = 1e1+5, Maxu = 1e1+5, Mod = 19260817;
int n, m, gd, block, num;
int a[Maxn], tags[Maxu], start[Maxu], end[Maxu], fibarr[Maxn], dbarr[Maxn], fib[Maxn];
int tagfib1[Maxu], tagfib2[Maxu], tagdck[Maxu], tagdcd[Maxu], tagdbf[Maxu];
void preil(void);
void dcadd(int l, int r, int k, int d);
void dbadd(int l, int r, int k);
void fibadd(int l, int r);
void update(int id);
int query(int l, int r);
int qpow(int di, int vi);

signed main(){
	freopen("data.in", "r", stdin);

//	scanf("%d %d %d", &n, &m, &gd);
	scanf("%lld %lld %lld", &n, &m, &gd);
//	for(int i=0; i<n; i++) scanf("%d", &a[i]);
	for(int i=0; i<n; i++) scanf("%lld", &a[i]);
	preil();
//	for(int i=0; i<Maxn; i++) printf("%lld ", dbarr[i]);
//	for(int i=0; i<Maxn; i++) printf("%lld ", fibarr[i]);
	block = n/sqrt(n); num = n/block;
	int sum;
	for(int i=0; i<num; i++){
		start[i] = block*i;
		end[i] = block*(i+1);
		sum = 0;
		for(int j=start[i]; j<end[i]; j++){
			sum += a[j];
			sum %= Mod;
		}
		tags[i] = sum;
	}
	if(n%block){
		start[num] = block*num;
		end[num] = block*(num+1);
		sum = 0;
		for(int j=start[num]; j<end[num]; j++){
			sum += a[j];
			sum %= Mod;
		}
		tags[num] = sum;
		num++;
	}
	int op, l, r, k, d;
	for(int i=0; i<m; i++){
		scanf("%lld", &op);
//		scanf("%d", &op);
		switch(op){
			case 1: scanf("%lld %lld %lld %lld", &l, &r, &k, &d); dcadd(l-1, r-1, k, d); break;
			case 2: scanf("%lld %lld %lld", &l, &r, &k); dbadd(l-1, r-1, k); break;
			case 3: scanf("%lld %lld", &l, &r); fibadd(l-1, r-1); break;
			case 4: scanf("%lld %lld", &l, &r); printf("%lld\n", query(l-1, r-1)); break;
//			case 1: scanf("%d %d %d %d", &l, &r, &k, &d); dcadd(l-1, r-1, k, d); break;
//			case 2: scanf("%d %d %d", &l, &r, &k); dbadd(l-1, r-1, k); break;
//			case 3: scanf("%d %d", &l, &r); fibadd(l-1, r-1); break;
//			case 4: scanf("%d %d", &l, &r); printf("%d\n", query(l-1, r-1)); break;
		}
	}

	return 0;
}

void preil(void){
	int db1 = 1, tmp;
	fib[1] = 1, fib[2] = 1;
	dbarr[1] = 1; fibarr[1] = 1; fibarr[2] = 1+1;
	for(int i=2; i<Maxn; i++){
		db1 *= gd;
		dbarr[i] = dbarr[i-1]+db1;
		db1 %= Mod; dbarr[i] %= Mod;
	}
	for(int i=3; i<Maxn; i++){
		fib[i] = fib[i-1]+fib[i-2];
		fib[i] %= Mod;
		fibarr[i] = fibarr[i-1] + fib[i];
		fibarr[i] %= Mod;
	}
}

void dcadd(int l, int r, int k, int d){
	d %= Mod;
	int lb = l/block, rb = r/block, curval = k, curvar = k+(r-l)*d;
	if(lb != rb){
		for(int i=l; i==l||i%block!=0; i++){
			a[i] += curval;
			tags[lb] += curval;
			curval += d;
			a[i] %= Mod; tags[lb] %= Mod; curval %= Mod;
		}
		for(int i=r; i==r||i%block!=block-1; i--){
			a[i] += curvar;
			tags[rb] += curvar;
			curvar -= d;
			a[i] %= Mod; tags[rb] %= Mod; curvar %= Mod;
		}
		for(int i=lb+1; i<rb; i++){
			tags[i] += (curval+((end[i]-start[i]-1)*d+curval)) * (end[i]-start[i]) / 2;
			tagdck[i] += curval;
			tagdcd[i] += d;
			curval += d*(end[i]-start[i]);
			tags[i] %= Mod; curval %= Mod; tagdck[i] %= Mod; tagdcd[i] %= Mod;
		}
	}
	else{
		for(int i=l; i<=r; i++){
			a[i] += curval;
			tags[lb] += curval;
			curval += d;
			a[i] %= Mod; tags[lb] %= Mod; curval %= Mod;
		}
	}
}

void dbadd(int l, int r, int k){
	int lb = l/block, rb = r/block; k %= Mod;
	int curval = k;
	if(lb != rb){
		int curvar = k*qpow(gd, start[rb]-l);
		for(int i=l; i==l||i%block!=0; i++){
			a[i] += curval;
			tags[lb] += curval;
			curval *= gd;
			a[i] %= Mod; tags[lb] %= Mod; curval %= Mod;
		}
		for(int i=start[rb]; i<=r; i++){
			a[i] += curvar;
			tags[rb] += curvar;
			curvar *= gd;
			a[i] %= Mod; tags[rb] %= Mod; curvar %= Mod;
		}
		for(int i=lb+1; i<rb; i++){
//			tags[i] += calcdb(curval, gd, end[i]-start[i]);
			tags[i] += ((dbarr[end[i]-l]-dbarr[start[i]-l])%Mod+Mod)*k;
			tagdbf[i] += curval;
			curval *= qpow(gd, end[i]-start[i]);
			tags[i] %= Mod; tagdbf[i] %= Mod; curval %= Mod;
		}
	}
	else{
		for(int i=l; i<=r; i++){
			a[i] += curval;
			tags[lb] += curval;
			curval *= gd;
			a[i] %= Mod; tags[lb] %= Mod; curval %= Mod;
		}
	}
}

void fibadd(int l, int r){
	int lb = l/block, rb = r/block, curval = 1, curvar = r-l+1;
	if(lb != rb){
		for(int i=l; i==l||i%block!=0; i++){
			a[i] += fib[curval];
			tags[lb] += fib[curval];
			curval++;
			a[i] %= Mod; tags[lb] %= Mod;
		}
		for(int i=r; i==r||i%block!=block-1; i--){
			a[i] += fib[curvar];
			tags[rb] += fib[curvar];
			curvar--;
			a[i] %= Mod; tags[rb] %= Mod;
		}
		for(int i=lb+1; i<rb; i++){
			tags[i] += (fibarr[end[i]-l]-fibarr[start[i]-l])%Mod+Mod;
			tagfib2[i] += fib[curval];
			tagfib1[i] += fib[curval-1];
			curval += end[i]-start[i];
			tags[i] %= Mod; tagfib2[i] %= Mod; tagfib1[i] %= Mod;
		}
	}
	else{
		for(int i=l; i<=r; i++){
			a[i] += fib[curval];
			tags[lb] += fib[curval];
			curval++;
			a[i] %= Mod; tags[lb] %= Mod; 
		}
	}
}

void update(int id){
	int curdc = tagdck[id], curdb = tagdbf[id], curfib2 = tagfib2[id], curfib1 = tagfib1[id];
//	printf("aa: ");
//	for(int i=start[id]; i<end[id]; i++) printf("%lld ", a[i]);
//	printf("\n");
	int tmp;
	for(int i=start[id]; i<end[id]; i++){
		a[i] += curdc; curdc += tagdcd[id]; curdc %= Mod; a[i] %= Mod;
		a[i] += curdb; curdb *= gd; curdb %= Mod; a[i] %= Mod;
		a[i] += curfib2; tmp = curfib1; curfib1 = curfib2; curfib2 += tmp; curfib2 %= Mod;
		a[i] %= Mod;
	}
//	printf("bb: ");
//	for(int i=start[id]; i<end[id]; i++) printf("%lld ", a[i]);
//	printf("\n");
	tagdck[id] = 0; tagdcd[id] = 0; tagdbf[id] = 0; tagfib1[id] = 0; tagfib2[id] = 0;
}

int query(int l, int r){
	int lb = l/block, rb = r/block, ans = 0;
	if(lb != rb){
		update(lb);
		for(int i=l; i==l||i%block!=0; i++){
			ans += a[i];
			ans %= Mod;
		}
		update(rb);
		for(int i=r; i==r||i%block!=block-1; i--){
			ans += a[i];
			ans %= Mod;
		}
		for(int i=lb+1; i<rb; i++){
			ans += tags[i];
			ans %= Mod;
		}
	}
	else{
		for(int i=l; i<=r; i++){
			ans += a[i];
			ans %= Mod;
		}
	}
	return ans;
}

int qpow(int di, int vi){
	int base = di, ans = 1;
	while(vi){
		if(vi&1) ans *= base;
		base *= base; base %= Mod;
		ans %= Mod; vi >>= 1;
	}
	return ans;
}

