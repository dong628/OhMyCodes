#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
using std::sort, std::min;

const int Maxn = 1e5+5, Maxsq = 1e4+5;
//const int Maxn = 1e2+5, Maxsq = 1e2+5;
int a[Maxn], cp[Maxn], start[Maxsq], end[Maxsq], tag[Maxsq], tmp[Maxn];
int block, num, maxai;
void add(int, int, int);
int query(int, int, int);
int calc(int, int, int);
void merge(int, int, int);
void update(int);


int read() {
  int x = 0, w = 1;
  char ch = 0;
  while (ch < '0' || ch > '9') {  // ch 不是数字时
    if (ch == '-') w = -1;        // 判断是否为负
    ch = getchar();               // 继续读入
  }
  while (ch >= '0' && ch <= '9') {  // ch 是数字时
    x = x * 10 + (ch - '0');  // 将新读入的数字’加’在 x 的后面
    // x 是 int 类型，char 类型的 ch 和 ’0’ 会被自动转为其对应的
    // ASCII 码，相当于将 ch 转化为对应数字
    // 此处也可以使用 (x<<3)+(x<<1) 的写法来代替 x*10
    ch = getchar();  // 继续读入
  }
  return x * w;  // 数字 * 正负号 = 实际数值
}

int main(){
	freopen("data.in", "r", stdin);

	int n, m;
	n = read(); m = read();
//	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++){
		a[i] = read();
//		scanf("%d", &a[i]);
		cp[i] = a[i];
		maxai = a[i]>maxai?a[i]:maxai;
	}
//	block = std::min(n, 150);
//	if(n == 1) block = 1;
//	else block = 2*sqrt((double(n)))*(log(n)/log(2));
	block = min(150, int(sqrt(n)));
	num = n/block;
	for(int i=0; i<num; i++){
		start[i] = i*block;
		end[i] = (i+1)*block;
		sort(cp+start[i], cp+end[i]);
	}
	if(n%block != 0){
		start[num] = num*block;
		end[num] = n;
		sort(cp+start[num], cp+end[num]);
		num++;
	}

	int opt, l, r, k;
	while(m--){
		opt = read(); l = read(); r = read(); k = read();
//		scanf("%d %d %d %d", &opt, &l, &r, &k);
		if(opt == 1){
			printf("%d\n", query(l-1, r-1, k));
		}
		else{
			add(l-1, r-1, k);
		}
	}

	return 0;
}

void add(int l, int r, int k){
	int lb = l/block, rb = r/block;
	if(lb != rb){
		for(int i=l; i==l||i%block!=0; i++){
			a[i] += k;
		}
//		merge(start[lb], l, end[lb]);
		update(lb);
		for(int i=r; i==r||i%block!=block-1; i--){
			a[i] += k;
		}
//		merge(start[rb], r+1, end[rb]);
		update(rb);
		for(int i=lb+1; i<rb; i++){
			tag[i] += k;
		}
	}
	else{
		for(int i=l; i<=r; i++){
			a[i] += k;
		}
//		sort(a+start[lb], a+end[lb]);
		update(lb);
	}
}

int query(int l, int r, int k){
	int lb = l/block, rb = r/block;
	int ll = 0x7fffffff, rr = -0x7fffffff, mid;
	if(k==0 || r-l+1<k) return -1;
	for(int i=lb; i<=rb; i++){
		ll = cp[start[i]]+tag[i] < ll ? cp[start[i]]+tag[i] : ll;
		rr = cp[end[i]-1]+tag[i] > rr ? cp[end[i]-1]+tag[i] : rr;
	}
	while(ll < rr){
		mid = (ll+rr+1)>>1;
		if(calc(l, r, mid) >= k) rr = mid-1;
		else ll = mid;
	}
	return ll;
}

int calc(int l, int r, int k){ // <k
	int lb = l/block, rb = r/block, cnt = 0;
	int ll, rr, mid;
	if(lb != rb){
		for(int i=l; i==l||i%block!=0; i++){
			if(a[i]+tag[lb] < k) cnt++;
		}
		for(int i=r; i==r||i%block!=block-1; i--){
			if(a[i]+tag[rb] < k) cnt++;
		}
		for(int i=lb+1; i<rb; i++){
			if(k > cp[end[i]-1]+tag[i]){
				cnt += block;
				continue;
			}
			else if(k < cp[start[i]]+tag[i]) continue;
			ll = start[i]; rr = end[i]-1;
			while(ll < rr){
				mid = (ll+rr)>>1;
				if(cp[mid] < k-tag[i]) ll = mid+1;
				else rr = mid;
			}
			cnt += ll - start[i];
		}
	}
	else{
		for(int i=l; i<=r; i++){
			if(a[i]+tag[lb] < k) cnt++;
		}
	}
	return cnt;
}

void update(int id){
	for(int i=start[id]; i<end[id]; i++){
		a[i] += tag[id];
		cp[i] = a[i];
	}
	tag[id] = 0;
	sort(cp+start[id], cp+end[id]);
}

void merge(int l, int mid, int r){
	int ll = l, lr = mid, rl = mid, rr = r, ansi = l;
	while(ll<lr && rl<rr){
		if(a[ll] < a[rl]) cp[ansi++] = a[ll++];
		else cp[ansi++] = a[rl++];
	}
	while(ll<lr) tmp[ansi++] = a[ll++];
	while(rl<rr) tmp[ansi++] = a[rl++];
	for(int i=l; i<r; i++){
		cp[i] = tmp[i];
	}
}
