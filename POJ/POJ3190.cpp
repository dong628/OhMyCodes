#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
using std::priority_queue;
using std::vector;
using std::greater;
typedef std::pair<int,int> pint;

const int MAX=50005;
int n, cnt, le, ans[MAX];
priority_queue < pint, vector<pint>, greater<pint> > cl;
pint tmp;
struct Cow{
	int start, end, nu;
}cow[MAX];

bool cmp(Cow x, Cow y) { return x.start < y.start; }

int main(){
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
	
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d %d", &cow[i].start, &cow[i].end);
		cow[i].nu=i;
	}
	std::sort(cow, cow+n, cmp);
	for(int i=0; i<n; i++){
		if(!cl.empty() && cl.top().first<cow[i].start){
			ans[cow[i].nu]=cl.top().second;
			cl.pop();
			tmp.first=cow[i].end; tmp.second=cl.size();
			cl.push(tmp);
			
		}
		else{
			cnt++;
			tmp.first=cow[i].end; tmp.second=cnt;
			cl.push(tmp);
			ans[cow[i].nu]=cnt;
		} 
	}
	printf("%d\n", cnt);
	for(int i=0; i<n; i++) printf("%d\n", ans[i]);
	
	return 0;
}
