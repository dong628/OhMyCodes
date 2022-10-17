#include <cstdio>
#include <iostream>
#include <algorithm>

const int Maxn = 3e5+5;
//const int Maxn = 3e2+5;
typedef std::pair <int, int> pii;
pii xs[Maxn], cur;
int plan[Maxn], cnt, ans;

int main(){
//	freopen("data.in", "r", stdin);

	int n, k, d, m;

	scanf("%d %d", &n, &k);
	for(int i=0; i<n; i++){
		scanf("%d %d", &d, &m);
		xs[cnt++] = std::make_pair(d, m);
	}
	std::sort(xs, xs+n);
	for(int i=0; i<n; i++){
		cur = xs[i];
		if(plan[cur.first]+cur.second > k){
			plan[cur.first+1] += cur.second-(k-plan[cur.first]);
			plan[cur.first] = k;
			if(plan[cur.first+1]>k) plan[cur.first+1] = k;
		}
		else{
			plan[cur.first] += cur.second;
		}
	}
	for(int i=xs[0].first; i<=xs[n-1].first+1; i++){
		ans += plan[i];
	}
	printf("%d", ans);

	return 0;
}
