#include <cstdio>
#include <iostream>
#include <cmath>

const int Maxn = 45;
const int Maxl = 805;
int n, l[Maxn], s, dp[Maxl][Maxl], maxx;
int hl(int, int, int);
inline int max(int xx, int yy) { return xx>yy?xx:yy; }

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%d", &l[i]);
	}
	s = l[1]+l[2];
	dp[0][0] = true;
	for(int k=3; k<=n; k++){
		s += l[k];
		for(int i=s/2-1; i>=l[k]; i--){
			for(int j=s/2-1; j>=l[k]; j--){
				if(i+j>s-i-j && s-i>j && s-j>i && (dp[i][j-l[k]] || dp[i-l[k]][j] || dp[i][j])){
					dp[i][j] = true;
					maxx = max(maxx, hl(i, j, s-i-j));
				}
			}
		}
	}
	if(maxx == 0) printf("-1");
	else printf("%d", maxx);

	return 0;
}

int hl(int a, int b, int c){
	double p = (a+b+c)/2.0;
	return int(sqrt(p*(p-a)*(p-b)*(p-c))*100);
}
