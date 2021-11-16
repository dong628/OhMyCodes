#include <cstdio>
#include <iostream>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using std::make_pair;

const int Inf = 0x7fffffff;
typedef std::pair<int, int> pii;
tree <pii, null_type, std::greater<pii>, rb_tree_tag, tree_order_statistics_node_update> tr, temp, anst;
int n, min, lmin, k, ans;
char op;

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d %d\n", &n, &min);
	lmin = min;
	for(int i=1; i<=n; i++){
		scanf("%c %d\n", &op, &k);
//		printf("%c\n", op);
		if(op=='I' && k>=min){
			tr.insert(make_pair(k+(lmin-min), i));
		}
		if(op=='A'){
			lmin -= k;
//			printf("lmin:%d\n", lmin);
		}
		if(op=='S'){
			lmin += k;
			tr.split(make_pair(lmin, -Inf), temp);
			ans += temp.size();
//			printf("lmin:%d\n", lmin);
		}
		if(op=='F'){
			if(k>tr.size()){
				printf("-1\n");
			}
			else{
				printf("%d\n", (*tr.find_by_order(k-1)).first+(min-lmin));
			}
		}
	}
	printf("%d\n", ans);

	return 0;
}
