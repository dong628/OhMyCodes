#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
using std::cin;
using std::lower_bound;
using std::upper_bound;
using std::greater;

const int Maxn=100005;
int a[Maxn], n, rear, b[Maxn];

int main(){
	freopen("data.in", "r", stdin);

	while(cin >> a[++n]); n--;
	rear=1; b[1]=a[1];
	for(int i=2; i<=n; i++){
		if(b[rear]>=a[i]){
			rear++;
			b[rear]=a[i];
		}
		else{
			b[upper_bound(b+1, b+rear+1, a[i], greater<int>())-b]=a[i];
		}
	}
	printf("%d\n", rear);
	rear=0;
	for(int i=1; i<=n; i++){
		if(b[rear]<a[i]){
			rear++;
			b[rear]=a[i];
		}
		else{
			b[lower_bound(b+1, b+rear+1, a[i])-b]=a[i];
		}
	}
	printf("%d", rear);

	return 0;
}
