#include <cstdio>
#include <iostream>
#include <bits/extc++.h>
using namespace __gnu_pbds;

const int Delta = 30;
bool flag;
int n, m, op;
long long x, last, ans, num;
tree <long long, null_type, std::less<long long>, rb_tree_tag, tree_order_statistics_node_update> tr;

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++){
		scanf("%lld", &num);
		tr.insert((num<<Delta)+i);
	}
	for(int i=1; i<=m; i++){
		scanf("%d %lld", &op, &x);
		x ^= last; flag = false;
//		printf("%d %lld\n", op, x);
		switch(op){
			case 1: tr.insert((x<<Delta)+i+n); break;
			case 2: tr.erase(tr.lower_bound(x<<Delta)); break;
			case 3: last=tr.order_of_key(x<<Delta)+1; flag=true; break;
			case 4: last=(*tr.find_by_order(x-1))>>Delta; flag=true; break;
			case 5: last=(*(--tr.lower_bound(x<<Delta)))>>Delta; flag=true; break;
			case 6: last=(*tr.upper_bound((x<<Delta)+n+m))>>Delta; flag=true; break;
		}
		if(flag){
			ans ^= last;
		}
	}
	printf("%lld", ans);

	return 0;
}
