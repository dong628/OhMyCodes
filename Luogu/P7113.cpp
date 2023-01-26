#include <cstdio>
#include <iostream>
#include <vector>
#define int __int128
using namespace std;

typedef __int128 lol;
const int Maxn = 1e5+5;
lol gcd(lol xx, lol yy){
	if(xx%yy==0) return yy;
	return gcd(yy, xx%yy);
}
struct Ans{
	lol p, q;
} ans[Maxn];
lol cnt[Maxn], gcdd;
void typ(int, lol, lol);
int n, m, sp[Maxn], c, csp, x;
bool lsp[Maxn], sj[Maxn];
vector<int> mapp[Maxn];

inline unsigned int read(){
    unsigned int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}

inline void print(unsigned int x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>9)
        print(x/10);
    putchar(x%10+'0');
}

signed main(){
//	freopen("data.in", "r", stdin);
//	freopen("data.out", "w", stdout);

//	scanf("%d %d", &n, &m);
	n = read(); m = read();
	for(int i=1; i<=n; i++){
		ans[i].p=0; ans[i].q=1;
		c = read();
//		scanf("%d", &c);
		for(int j=1; j<=c; j++){
			x = read();
//			scanf("%d", &x);
			mapp[i].push_back(x);
			lsp[x] = true;
			cnt[i]++;
		}
	}
	for(int i=1; i<=n; i++){
		if(lsp[i]==false) sp[csp++]=i;
	}
	for(int i=0; i<csp; i++){
		typ(sp[i], 1, 1);
	}
	for(int i=1; i<=n; i++){
		if(sj[i]){
			print(ans[i].p); putchar(' '); print(ans[i].q); putchar('\n');
//			printf("%lld %lld\n", ans[i].p, ans[i].q);
		}
	}

	return 0;
}

void typ(int poi, lol p, lol q){
	if(cnt[poi]==0){
		sj[poi]=true;
		ans[poi].p *= q;
		ans[poi].p += ans[poi].q*p;
		ans[poi].q *= q;
		gcdd = gcd(ans[poi].p, ans[poi].q);
		ans[poi].p /= gcdd; ans[poi].q /= gcdd;
		return;
	}
	else{
		for(int i=0; i<cnt[poi]; i++){
			typ(mapp[poi][i], p, q*cnt[poi]);
		}
	}
}
