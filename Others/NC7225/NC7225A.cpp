#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

const int Max=1005;

int main(){
	freopen("data.in", "r", stdin);
	int n, m, k, pre[Max], tmp, l, r;
	scanf("%d %d %d", &n, &m, &k);
/*	if(!(k&1)){
		for(int i=1; i<=n; i++) printf("%d ", i);
		return 0;
	}*/
	for(int i=1; i<=n; i++) pre[i]=i;
	for(int i=0; i<m; i++){
		scanf("%d %d", &l, &r);
		for(int j=l; j<=((l+r)>>1); j++){
			tmp=pre[j];
			pre[j]=pre[r-(j-l)];
			pre[r-(j-l)]=tmp;
		}
	}
	int now[Max], ans[Max], ansbak[Max];
	for(int i=1; i<=n; i++) now[i]=pre[i];
	for(int i=1; i<=n; i++) ans[i]=i;
	while(k){
		if(k&1){
			for(int i=1; i<=n; i++){
				ansbak[i]=ans[i];
			}
			for(int i=1; i<=n; i++){
				ans[i]=ansbak[now[i]];
			}
		}
		for(int i=1; i<=n; i++){
			now[i]=pre[pre[i]];
		}
		for(int i=1; i<=n; i++) pre[i]=now[i];
		k>>=1;
	}
	for(int i=1; i<=n; i++) printf("%d ", ans[i]);

	return 0;
}
