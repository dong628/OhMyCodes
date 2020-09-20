#include <cstdio>
#include <iostream>

const int Max=105;
int t, n, k, now, cnt, vis[Max];

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d", &t);
	for(int i=0; i<t; i++){
		scanf("%d %d", &n, &k);
		now=0;
		for(int i=0; i<=n; i++) vis[i]=i;
		for(int i=0; i<n; i++){
			cnt=0;
			while(cnt<k){
				now++;
				if(now>n) now%=n;
				if(vis[now]!=0) {
					cnt++;
				}
			}
			vis[now]=0;
			printf("%d ", now);
		}
		printf("\n");
	}

	return 0;
}
