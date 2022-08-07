#include <cstdio>
#include <iostream>
#include <cstring>

const int Maxn = 2e5+5;
int n, a, e, ansa, ansb, pointa[Maxn], pointb[Maxn], minf, len;
char str[Maxn], ans[Maxn];

int main(){
	freopen("data.in", "r", stdin);

	int t;
	scanf("%d", &t);
	while(t--){
		memset(ans, 0, sizeof(ans));
		ansa = 0; ansb = 0;
		scanf("%d %d %d\n", &n, &a, &e);
		scanf("%s", str);
		len = 2*n;
		for(int i=0; i<len; i++){
			if(str[i] == 'A'){
				pointa[ansa] = i;
				ansa++; 
			}
			else{
				pointb[ansb] = i;
				ansb++;
			}
		}
		if(ansa > a){
			minf = ansa-a;
			if(((e-minf)&1) || (len-ansa)*2<e-minf || e<minf){
				printf("-1\n");
			}
			else{
				for(int i=0; i<(e-minf)/2; i++){
					ans[pointb[i]] = 'A';
				}
				for(int i=(e-minf)/2; i<a; i++){
					ans[pointa[i]] = 'A';
				}
				for(int i=0; i<len; i++){
					if(ans[i]!='A') ans[i] = 'B';
				}
				printf("%s\n", ans);
			}
		}
		else{
			minf = a-ansa;
			if(((e-minf)&1) || (len-ansa)*2<e-minf || e<minf){
				printf("-1\n");
			}
			else{
				for(int i=0; i<(e-minf)/2; i++){
					ans[pointa[i]] = 'B';
				}
				for(int i=(e-minf)/2; i<len-a; i++){
					ans[pointb[i]] = 'B';
				}
				for(int i=0; i<len; i++){
					if(ans[i]!='B') ans[i] = 'A';
				}
				printf("%s\n", ans);
			}
		}
	}

	return 0;
}
