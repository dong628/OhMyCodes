#include <cstdio>
#include <iostream>
#include <algorithm>
using std::sort;

const int Max=200005;
struct Node{
	int x, y;
}t[Max];
int floor[Max], cnt[Max];
inline int max(int x, int y) { return x>y?x:y; }
inline int min(int x, int y) { return x<y?x:y; }
bool cmp(Node x, Node y) { return x.x<y.x; }

int main(){
	freopen("data.in", "r", stdin);

	int n, m, x, y;
	scanf("%d", &n);
	for(int i=0; i<n-1; i++){
		scanf("%d %d", &x, &y);
		t[i].x=min(x, y); t[i].y=max(x, y);
	}
	sort(t, t+n-1, cmp);
	floor[1]=1;
	for(int i=0; i<n-1; i++){
		floor[t[i].y]=floor[t[i].x]+1;
	}
	int nf=1, a;
	for(int i=0; i<n; i++){
		scanf("%d", &a);
		if(floor[a]<nf){
			printf("No");
			return 0;
		}
		else nf=floor[a];
	}
	printf("Yes");

	return 0;
}
