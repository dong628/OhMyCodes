#include <cstdio>
#include <iostream>

const int Maxn = 1e6+5;
int t, a[Maxn], topl, botl, topr, botr, cur, opt[Maxn], n;
bool flag;

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d", &t);
	while(t --> 0){
		scanf("%d", &n);
		for(int i=1; i<=2*n; i++){
			scanf("%d", &a[i]);
		}
		if(n == 1){
			printf("LL\n");
			continue;
		}
		topl = 2; topr = 2*n;
		for(int i=2; i<=2*n; i++){
			if(a[i] == a[1]){
				botl = i - 1;
				botr = i + 1;
				continue;
			}
		}
		cur = 1; flag = true;
		while(topl <= botl || topr >= botr){
			if(a[topl] == a[botl] && topl < botl){
				opt[cur] = 0;
				opt[2*n-cur-1] = 0;
				topl++; botl--;
			}
			else if(a[topl] == a[botr]){
				opt[cur] = 0;
				opt[2*n-cur-1] = 1;
				topl++; botr++;
			}
			else if(a[topr] == a[botl]){
				opt[cur] = 1;
				opt[2*n-cur-1] = 0;
				topr--; botl--;
			}
			else if(a[topr] == a[botr] && topr > botr){
				opt[cur] = 1;
				opt[2*n-cur-1] = 1;
				topr--; botr++;
			}
			else{
				flag = false;
				break;
			}
			cur++;
		}
		if(flag){
			putchar('L');
			for(int i=1; i<2*n-1; i++){
				if(opt[i] == 0) putchar('L');
				else putchar('R');
			}
			putchar('L');
			putchar('\n');
			continue;
		}

		topl = 1; topr = 2*n-1;
		for(int i=1; i<2*n; i++){
			if(a[i] == a[2*n]){
				botl = i - 1;
				botr = i + 1;
				continue;
			}
		}

		cur = 1; flag = true;
		while(topl <= botl || topr >= botr){
			if(a[topl] == a[botl] && topl < botl){
				opt[cur] = 0;
				opt[2*n-cur-1] = 0;
				topl++; botl--;
			}
			else if(a[topl] == a[botr]){
				opt[cur] = 0;
				opt[2*n-cur-1] = 1;
				topl++; botr++;
			}
			else if(a[topr] == a[botl]){
				opt[cur] = 1;
				opt[2*n-cur-1] = 0;
				topr--; botl--;
			}
			else if(a[topr] == a[botr] && topr > botr){
				opt[cur] = 1;
				opt[2*n-cur-1] = 1;
				topr--; botr++;
			}
			else{
				flag = false;
				break;
			}
			cur++;
		}
		if(flag){
			putchar('R');
			for(int i=1; i<2*n-1; i++){
				if(opt[i] == 0) putchar('L');
				else putchar('R');
			}
			putchar('L');
			putchar('\n');
			continue;
		}
		printf("-1\n");
	}

	return 0;
}
