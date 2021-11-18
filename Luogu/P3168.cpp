#include <cstdio>
#include <iostream>
#include <algorithm>

const int Maxn = 1e5+5;
long long int a, b, c, x, s, e, p, n, m, pre, k, cnt;
struct Node{
	long long int s, e, p;
}renwu[Maxn];
bool cmp(Node xx, Node yy){
	return xx.p<yy.p;
}

int main(){
	freopen("data.in", "r", stdin);

	scanf("%lld %lld", &m, &n);
	for(int i=1; i<=m; i++){
		scanf("%lld %lld %lld", &s, &e, &p);
		renwu[i].s=s;
		renwu[i].e=e;
		renwu[i].p=p;
	}
	std::sort(renwu+1, renwu+1+m, cmp);
	pre = 1;
	for(int i=1; i<=n; i++){
		scanf("%lld %lld %lld %lld", &x, &a, &b, &c);
		k = 1+(a*pre+b)%c;
		pre = 0; cnt = 0;
		for(int j=1; j<=m && cnt<k; j++){
			if(renwu[j].s<=x && renwu[j].e>=x){
				pre += renwu[j].p;
				cnt++;
			}
		}
		printf("%lld\n", pre);
	}

	return 0;
}
