#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <bitset>
using std::sort, std::unique, std::lower_bound, std::swap;

const int Block = 300;
const int Maxn = 1e5+5, Maxsq = 1e3+5, Maxlog = 20;
//const int Maxn = 1e2+5, Maxsq = 1e1+5, Maxlog = 20;
std::bitset<Maxn> bs[Maxsq], ret, cx[Maxsq], st[Maxsq*2][Maxlog], ans;
int a[Maxn], cp[Maxn];
int start[Maxsq], end[Maxsq], block, num, cntu;

void st_prework(void);
int calc(int l, int r);
int query(int l, int r);

int read() {
  int x = 0, w = 1;
  char ch = 0;
  while (ch < '0' || ch > '9') {  // ch 不是数字时
    if (ch == '-') w = -1;        // 判断是否为负
    ch = getchar();               // 继续读入
  }
  while (ch >= '0' && ch <= '9') {  // ch 是数字时
    x = x * 10 + (ch - '0');  // 将新读入的数字’加’在 x 的后面
    ch = getchar();  // 继续读入
  }
  return x * w;  // 数字 * 正负号 = 实际数值
}

int main(){
	freopen("data.in", "r", stdin);
//	freopen("data.out", "w", stdout);
	
	int n, c, m;
//	n = read(); c = read(), m = read();
	scanf("%d %d %d", &n, &c, &m);
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
//		a[i] = read();
		cp[i] = a[i];
	}
	sort(cp, cp+n);
	cntu = unique(cp, cp+n)-cp;
	for(int i=0; i<n; i++){
		a[i] = lower_bound(cp, cp+cntu, a[i])-cp;
	}
	block = sqrt(n);
//	block = std::min(n, Block);
	num = n/block;
	for(int i=0; i<num; ++i){
		start[i] = i*block;
		end[i] = (i+1)*block;
		for(int j=start[i]; j<end[i]; j++){
			bs[i].flip(a[j]);
			cx[i][a[j]] = true;
		}
		bs[i+1] = bs[i];
	}
	if(n%block != 0){
		start[num] = (num)*block;
		end[num] = n;
		for(int j=start[num]; j<end[num]; ++j){
			bs[num].flip(a[j]);
			cx[num][a[j]] = true;
		}
		num++;
	}

	st_prework();

	int l, r, ans = 0;
	
	while(m--){
//		l = read(); r = read();
		scanf("%d %d", &l, &r);
		l = ((l+ans)%n)+1;
		r = ((r+ans)%n)+1;
		if(l>r) swap(l, r);
		ans = calc(l-1, r-1);
		printf("%d\r\n", ans);
	}

	return 0;
}

int calc(int l, int r){
	int lb = l/block, rb = r/block;
	int count = 0;
	ret.reset();
//	memset(ret, 0, sizeof(ret));
	if(lb!=rb){
		for(int i=l; i==l||i%block!=0; ++i)
			ret.flip(a[i]);
		for(int i=r; i==r||i%block!=block-1; --i)
			ret.flip(a[i]);
		ret ^= (bs[lb]^bs[rb-1]);
//		ret.flip();
		return query(l, r) - ret.count();
	}
	else{
		for(int i=l; i<=r; ++i)
			ret.flip(a[i]);
		return query(l, r) - ret.count();
	}
}

void st_prework(void){
	int log2 = log(num)/log(2);
	for(int i=0; i<num; i++) st[i][0] = cx[i];
	for(int i=1; i<=log2; i++){
		for(int j=0; j<num; j++){
			st[j][i] = st[j][i-1]|st[j+(1<<(i-1))][i-1];
		}
	}
}

int query(int l, int r){
	int lb = l/block, rb = r/block, log2 = log(rb-lb-1)/log(2);
	ans.reset();
	if(rb-lb > 1){
		for(int i=l; i==l||i%block!=0; i++) ans[a[i]] = true;
		for(int i=r; i==r||i%block!=block-1; i--) ans[a[i]] = true;
		ans |= (st[lb+1][log2]|st[rb-(1<<log2)][log2]);
	}
	else{
		for(int i=l; i<=r; i++) ans[a[i]] = true;
	}
	return ans.count();
}
