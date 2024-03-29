#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using std::sort, std::unique, std::lower_bound, std::swap;

const int Block = 300;
const int Maxn = 1e5+5, Maxsq = 1e3+5;
int a[Maxn], cp[Maxn], cnt[Maxsq][Maxn];
int start[Maxsq], end[Maxsq], block, num, ret[Maxn], cntu;

int calc(int l, int r);


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
//	freopen("std.out", "w", stdout);
	
	int n, c, m;
	n = read(); c = read(), m = read();
//	scanf("%d %d %d", &n, &c, &m);
	for(int i=0; i<n; i++){
//		scanf("%d", &a[i]);
		a[i] = read();
		cp[i] = a[i];
	}
	sort(cp, cp+n);
	cntu = unique(cp, cp+n)-cp;
	for(int i=0; i<n; i++){
		a[i] = lower_bound(cp, cp+cntu, a[i])-cp;
	}
//	block = sqrt(n);
	block = std::min(n, Block);
	num = n/block+1;
	for(int i=0; i<num-1; ++i){
		start[i] = i*block;
		end[i] = (i+1)*block;
		for(int j=0; j<cntu; j++){
			cnt[i][j] = cnt[i-1][j];
		}
		for(int j=start[i]; j<end[i]; j++){
			cnt[i][a[j]]++;
		}
	}
	if((num-1)*block != n){
		start[num-1] = (num-1)*block;
		end[num-1] = n;
		for(int j=0; j<cntu; ++j){
			cnt[num-1][j] = cnt[num-2][j];
		}
		for(int j=start[num-1]; j<end[num-1]; ++j){
			++cnt[num-1][a[j]];
		}
	}
	else num--;
//	return 0;

	int l, r, ans = 0;
	
	while(m--){
		l = read(); r = read();
//		scanf("%d %d", &l, &r);
//		l = ((l+ans)%n)+1;
//		r = ((r+ans)%n)+1;
		if(l>r) swap(l, r);
		ans = calc(l-1, r-1);
		printf("%d\r\n", ans);
	}

	return 0;
}

int calc(int l, int r){
	int lb = l/block, rb = r/block;
	int count = 0;
//	memset(ret, 0, sizeof(ret));
	if(lb!=rb){
		for(int i=l; i==l||i%block!=0; ++i)
			++ret[a[i]];
		for(int i=r; i==r||i%block!=block-1; --i)
			++ret[a[i]];
		for(int j=0; j<cntu; ++j){
			ret[j] += cnt[rb-1][j]-cnt[lb][j];
			if(ret[j] && ((ret[j]&1)==0)) ++count;
			ret[j] = 0;
		}
		return count;
	}
	else{
		for(int i=l; i<=r; ++i)
			++ret[a[i]];
		for(int j=0; j<cntu; ++j){
			if(ret[j] && ((ret[j]&1)==0)) ++count;
			ret[j] = 0;
		}
		return count;
	}
}
