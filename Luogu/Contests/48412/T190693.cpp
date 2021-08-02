#include <cstdio>
#include <iostream>

const int Maxn=5e5+5;
int n, m, zero, one, v, a[Maxn], ans;
char ch;

int main(){
//	freopen("data.in", "r", stdin);
//	freopen("data.out", "w", stdout);

	scanf("%d %d\n", &n, &m);
	for(int i=1; i<=n; i++){
		ch = getchar();
		a[i] = ch-'0';
	}
	for(int i=1; i<=m; i++){
		ans=0;
		scanf("%d", &v);
		if(v>0){
			for(int j=n; v>0&&j>=0; j--){
				if(a[j]==0){
					a[j]=1; v--;
				}
			}
		}
		else{
			v=-v;
			for(int j=n; v>0&&j>=0; j--){
				if(a[j]==1){
					a[j]=0; v--;
				}
			}
		}
		for(int j=1; j<=n; j++){
			if(a[j]==1 && a[j-1]==0){
				ans+=n-j+1;
			}
			else if(a[j]==0 && a[j-1]==1){
				ans+=n-j+1;
			}
		}
		printf("%d\r\n", ans);
	}

	return 0;
}
