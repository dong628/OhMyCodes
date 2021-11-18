#include <cstdio>
#include <iostream>
#include <bits/extc++.h>
using std::make_pair;
using namespace __gnu_pbds;

typedef std::pair<int, int> pii;
int n, opt, x, node;
tree<pii, null_type, std::less<pii>, rb_tree_tag, tree_order_statistics_node_update> tr;

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d", &n);
	for(int i=0; i<=n; i++){
		scanf("%d %d", &opt, &x);
		switch(opt){
			case 1: tr.insert(make_pair(x, i)); break;
			case 2: tr.erase(*tr.lower_bound(make_pair(x, -1))); break;
			case 3: printf("%d\n", tr.order_of_key(*tr.lower_bound(make_pair(x, -1)))); break;
			case 4: printf("%d\n", (*tr.find_by_order(x)).first); break;
			case 5: {
				node = tr.order_of_key(*tr.lower_bound(make_pair(x, -1)))-1;
				printf("%d\n", (*tr.find_by_order(node)).first);
				break;
			}
			case 6: {
				node = tr.order_of_key(*tr.lower_bound(make_pair(x, -1)))+1;
				printf("%d\n", (*tr.find_by_order(node)).first);
				break;
			}
		}
	}

	return 0;
}
