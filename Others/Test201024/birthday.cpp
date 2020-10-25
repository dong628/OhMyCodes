#include <cstdio>
#include <cstring>
#include <iostream>

const int Max=1e5+5;
int li[Max], h[35], n, m, l, r, k, cnt, x;
char mode;

int main(){
	freopen("birthday.in", "r", stdin);
    freopen("birthday.out", "w", stdout);

	scanf("%d %d %d\n", &n, &m, &k);
	for(int j=0; j<m; j++){
		mode=getchar();
		if(mode=='C'){
			scanf("%d %d %d\n", &l, &r, &x);
			for(int i=l; i<=r; i++) li[i]=x;
		}
		else{
			cnt=0;
			memset(h, 0, sizeof(h));
			scanf("%d %d\n", &l, &r);
			for(int i=l; i<=r; i++){
				if(h[li[i]]==0){
					h[li[i]]=1;
					cnt++;
				}
			}
			printf("%d\n", cnt);
		}
	}

	return 0;
}
