#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
#define int long long
using namespace std;

struct Node{
	int l, r;
	mutable int val;
	Node(const int &ll, const int &rr, const int &vv) : l(ll), r(rr), val(vv) {}
	inline bool operator<(const Node &b) const { return l < b.l; }
	inline bool operator!=(const Node &b) const { return l != b.l || r != b.r || val != b.val; }
};

const int Maxn = 3e5+5;
//const int Maxn = 5005;
set <Node> odt, mem, odtbak;
vector <int> reb;
int a[Maxn], b[Maxn], type[Maxn];
bool back[Maxn];

int read(){
  int x = 0, w = 1;
  char ch = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();      
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + (ch - '0');
    ch = getchar();
  }
  return x * w;
}
inline void write(int x) {
  static int sta[35];
  int top = 0;
  do {
    sta[top++] = x % 10, x /= 10;
  } while (x);
  while (top) putchar(sta[--top] + 48);
}

auto split(int x){
	if(odt.empty()) return odt.end();
	if(x > odt.rbegin() -> r) return odt.end();
	auto p = --odt.upper_bound(Node(x, 0, 0));
	if(p -> l == x) return p;
	int l = p -> l, r = p -> r, val = p -> val;
	odt.erase(p);
	odt.insert(Node(l, x-1, val));
	return odt.insert(Node(x, r, val)).first;
}

void add(int ta, int x){
	if(odt.empty()){
		odt.insert(Node(1, ta, x));
		return;
	}
	auto end = split(ta+1);
	for(auto itr = odt.begin(); itr != end; itr++){
		itr -> val += x;
	}
	if(end == odt.end()){
		end--;
		if(ta >= end->r+1){
			odt.insert(Node(end->r+1, ta, x));
		}
	}
}

void del(int ta, int x){
	for(auto itr = split(ta); itr != odt.end(); itr++){
		itr -> val -= x;
		if(itr -> val <= 0){
			odt.erase(itr, odt.end());
			break;
		}
	}
}

void rb(void){
	int val, r;
	for(int i=0; i<reb.size(); i++){
		auto it = --odt.upper_bound(Node(reb[i], 0, 0));
		val = it -> val;
		auto st = it;
		for(; it->val==val; it++){
			r = it -> r;
		}
		it++; odt.erase(st, it);
		odt.insert(Node(reb[i], r, val));
	}
}

void query(int x){
	odtbak = odt;
	int dta, maxx, minn, lastval = 0;
	for(auto itr = odt.begin(); itr != odt.end(); itr++){
		lastval = 0;
//		for(auto jtr = ++odt.rbegin(); *jtr != *itr; jtr++){
		for(auto jtr = prev(odt.end()); jtr->l >= itr->l; jtr = prev(jtr)){
			if(lastval == jtr -> val){
				reb.push_back(jtr->l);
			}
			maxx = (itr -> val - lastval - 1) + (jtr -> r - itr -> l + 1);
			minn = (itr -> val - jtr -> val) + (jtr -> r - itr -> r + 1);
			if(x >= minn && x <= maxx){
				dta = maxx - x;
				if(dta < (itr -> r - itr -> l + 1)){
//					printf("%lld %lld\n", itr->l+dta, lastval+1);
					write(itr->l+dta); putchar(' '); write(lastval+1);
					putchar('\n');
				}
				else{
//					printf("%lld %lld\n", itr->r, jtr->val-(x-minn));
					write(itr->r); putchar(' '); write(jtr->val-(x-minn));
					putchar('\n');
				}
				rb();
				return;
			}
			lastval = jtr -> val;
			if(jtr == odt.begin()) break;
		}
	}
	printf("-1 -1\n");
	rb();
	return;
}

signed main(){
	freopen("stairs.in", "r", stdin);
	freopen("stairs.out", "w", stdout);

	int m, ta, tb;
	char ty;

//	scanf("%lld\n", &m);
	m = read();
	for(int i=1; i<=m; i++){
		ty = getchar();
		if(ty == '+'){
			type[i] = 1;
//			scanf("%lld %lld\n", &ta, &tb);
			a[i] = read(); b[i] = read();
	 	}
		else if(ty == '-'){
			type[i] = 2;
//			scanf("%lld %lld\n", &ta, &tb);
			a[i] = read(); b[i] = read();
	 	}
		else if(ty == 'R'){
			type[i] = 3;
//			scanf("%lld\n", &ta);
			ta = read();
			back[i-ta] = true;
	 	}
		else{
			type[i] = 4;
//			scanf("%lld\n", &ta);
			ta = read();
			a[i] = ta;
		}
	}
	int cnt = 0;
	for(int i=1; i<=m; i++){
		if(back[i]){
			mem = odt;
		}
		if(type[i] == 1){
			add(a[i], b[i]);
		}
		else if(type[i] == 2){
			del(a[i], b[i]);
		}
		else if(type[i] == 3){
			odt = mem;
		}
		else{
			if(cnt == 574){
				cnt++;
			}
			cnt++;
			query(a[i]);
		}
	}

	return 0;
}
