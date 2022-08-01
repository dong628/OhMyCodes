#include <cstdio>
#include <iostream>
#include <cstring>
using std::swap;

int t, n, m, ai, bi;
bool alpha[105];

int main(){
//	freopen("data.in", "r", stdin);

	scanf("%d", &t);
	while(t--){
		memset(alpha, 0, sizeof(alpha));
		scanf("%d %d", &n, &m);
		for(int i=0; i<n; i++){
			scanf("%d", &ai);
			bi = m+1-ai;
			if(bi < ai) swap(ai, bi);
			if(alpha[ai]) alpha[bi] = true;
			else alpha[ai] = true;
		}
		for(int i=1; i<=m; i++){
			if(alpha[i]) printf("A");
			else printf("B");
		}
		printf("\n");
	}

	return 0;
}
