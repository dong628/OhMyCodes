#include <cstdio>
#include <iostream>
using std::lower_bound;

const int Maxn=1e5+5;
int p[Maxn], mapp[Maxn], n, num, low[Maxn], rear;
bool calc(int);

int main(){
//	freopen("data.in", "r", stdin);

	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%d", &num);
		mapp[num]=i;
	}
	for(int i=1; i<=n; i++){
		scanf("%d", &num);
		p[i]=mapp[num];
	}
	for(int i=1; i<=n; i++){
		if(low[rear]<p[i]){
			low[rear+1]=p[i];
			rear++;
		}
		else{
			low[lower_bound(low+1, low+rear+1, p[i])-low]=p[i];
		}
	}

	printf("%d", rear);
	
	return 0;
}
