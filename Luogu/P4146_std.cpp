#include <cstdio>
#include <iostream>

const int Maxn = 1e3+5, Inf = 0x7fffffff;
//const int Maxn = 5e4+5, Inf = 0x7fffffff;
int a[Maxn];

int main(){
	freopen("data.in", "r", stdin);
	
	int n, m, opt, l, r, v, maxx;
	scanf("%d %d", &n, &m);

	while(m--){
		scanf("%d", &opt);
		if(opt == 1){
			scanf("%d %d %d", &l, &r, &v);
			for(int i=l; i<=r; i++){
				a[i] += v;
			}
		}
		else if(opt == 2){
			scanf("%d %d", &l, &r);
			for(int i=0; i<(r-l+1)>>1; i++){
				std::swap(a[l+i], a[r-i]);
			}
		}
		else{
			scanf("%d %d", &l, &r);
			maxx = -Inf;
			for(int i=l; i<=r; i++){
				maxx = maxx>a[i]?maxx:a[i];
			}
			printf("%d\n", maxx);
		}
		for(int i=1; i<=n; i++){
			printf("%d ", a[i]);
		}
//		output(root);
		putchar('\n');
	}

	return 0;
}
