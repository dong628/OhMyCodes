#include <cstdio>
#include <iostream>
#include <set>
#define int long long

struct Node{
	int l, r;
	mutable int val;
	Node(const int &ll, const int &rr, const int &vv) : l(ll), r(rr), val(vv) {}
	inline bool operator< (const Node &b) const { return l < b.l; }
};
struct Rnk{
	int len, val;
	Rnk(const int &ll, const int &vv) : len(ll), val(vv) {}
	inline bool operator< (const Rnk &b) const { return val < b.val; }
};

int n, m;
long long seed, vmax;
std::set <Node> odt;
std::multiset <Rnk> rnk;

int rnd(void);

long long qpow(int a, int b, int mod){
	unsigned long long base = a%mod, ans = 1;
	while(b){
		if(b & 1) { ans *= base; ans %= mod; }
		base *= base;
		base %= mod;
		b >>= 1;
	}
	return ans;
}

auto split(int x){
	if(x > n) return odt.end();
	auto it = --odt.upper_bound(Node(x, 0, 0));
	if(it -> l == x) return it;
	int l = it -> l, r = it -> r, val = it -> val;
	odt.erase(it);
	odt.insert(Node(l, x-1, val));
	return odt.insert(Node(x, r, val)).first;
}

void assign(int l, int r, int val){
	auto itr = split(r+1), itl = split(l);
	odt.erase(itl, itr);
	odt.insert(Node(l, r, val));
}

void add(int l, int r, int val){
	auto itr = split(r+1), itl = split(l);
	for( ; itl != itr; itl++){
		itl -> val += val;
	}
}

int xth(int l, int r, int k){
	auto itr = split(r+1), itl = split(l);
	int tot = 0, tot1 = 0;
	rnk.clear();
	for( ; itl != itr; itl++){
		rnk.insert(Rnk(itl -> r - itl -> l + 1, itl -> val));
		tot1 += itl -> r - itl -> l + 1;
	}
//	printf("%lld ", tot1);
	for(auto iter = rnk.begin(); iter != rnk.end(); iter++){
		tot += iter -> len;
		if(tot >= k) return iter -> val;
	}
	return rnk.rbegin() -> val;
}

long long query(int l, int r, int x, int y){
	auto itr = split(r+1), itl = split(l);
	long long ans = 0;
	for( ; itl != itr; itl++){
		ans += (itl -> r - itl -> l + 1) * qpow(itl -> val, x, y);
		ans %= y;
	}
	return ans;
}

signed main(){
	freopen("data.in", "r", stdin);

	int op, l, r, x ,y;
	scanf("%lld %lld %lld %lld", &n, &m, &seed, &vmax);
	for(int i=1; i<=n; i++){
		odt.insert(Node(i, i, (rnd()%vmax)+1));
	}
	for(int i=1; i<=m; i++){
		op = (rnd() % 4) + 1;
		l = (rnd() % n) + 1;
		r = (rnd() % n) + 1;
		if(l > r) std::swap(l, r);

		if(op == 1){
			x = (rnd()%vmax) + 1;
			add(l, r, x);
		}
		else if(op == 2){
			x = (rnd()%vmax) + 1;
			assign(l, r, x);
		}
		else if(op == 3){
			x = (rnd() % (r-l+1)) + 1;
			printf("%lld\n", xth(l, r, x));
		}
		else{
			x = (rnd()%vmax) + 1;
			y = (rnd()%vmax) + 1;
			printf("%lld\n", query(l, r, x, y));
		}
	}

	return 0;
}

int rnd(void){
	int ret = seed;
	seed = (seed * 7 + 13) % signed(1e9+7);
	return ret;
}
