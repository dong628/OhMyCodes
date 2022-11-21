#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <time.h>
using std::max, std::min;

const int Maxadd = 1e2, Maxn = 1e9;
int n[Maxadd];

int main(){
	freopen("data.in", "w", stdout);
	int seed;
	
	scanf("%d", &seed);
	srand(seed*114);

	int m, l, r, opt, v, ver;
	m = 10;
	printf("%d\n", m);
	for(int i=1; i<=m; i++){
		opt = rand()%4+1;
		ver = rand()%i;
		if(n[ver] > 0){
			l = rand()%n[ver]+1;
			r = rand()%n[ver]+1;
		}
		else { opt = 1; l = 0;}
		printf("%d %d ", ver, opt);
		if(opt == 1){
			n[i] = n[ver]+1;
			v = rand()%10-5;
			printf("%d %d\n", l, v);
		}
		else if(opt == 2){
			n[i] = n[ver]-1;
			printf("%d\n", l);
		}
		else{
			printf("%d %d\n", min(l, r), max(l, r));
		}
	}

	return 0;
}
