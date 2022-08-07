#include <cstdio>
#include <iostream>
#include <map>
using std::map, std::make_pair, std::min, std::max;

typedef std::pair<int, int> pii;
typedef unsigned long long lol;

int n, x, y;
lol z, ans, pre;
map<pii, lol> points;

int main(){
	freopen("data.in", "r", stdin);

	pii tmp;

	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d %d %llu", &x, &y, &z);
		tmp = make_pair(x, y);
		if(points.find(tmp)!=points.end()){
			pre = points[tmp];
			points[tmp] += z;
		}
		else{
			pre = 0;
			points.insert(make_pair(tmp, z));
		}
		ans += 4*z;
		tmp = make_pair(x+1, y);
		if(points.find(tmp)!=points.end() && points[tmp]>pre)
			ans -= 2*min(max(lol(0), points[tmp]-pre), z);
		tmp = make_pair(x-1, y);
		if(points.find(tmp)!=points.end() && points[tmp]>pre)
			ans -= 2*min(max(lol(0), points[tmp]-pre), z);
		tmp = make_pair(x, y+1);
		if(points.find(tmp)!=points.end() && points[tmp]>pre)
			ans -= 2*min(max(lol(0), points[tmp]-pre), z);
		tmp = make_pair(x, y-1);
		if(points.find(tmp)!=points.end() && points[tmp]>pre)
			ans -= 2*min(max(lol(0), points[tmp]-pre), z);
		printf("%llu\n", ans);
	}

	return 0;
}
