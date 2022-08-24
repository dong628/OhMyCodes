#include <cstdio>
#include <iostream>

const int Maxn = 205;
int mapp[Maxn][Maxn];
bool row[Maxn], col[Maxn];

int main(){
	freopen("data.in", "r", stdin);

	int t, n;
	bool flag;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				scanf("%d", &mapp[i][j]);
				if(mapp[i][j]==1){
					row[i] = true;
					col[j] = true;
				}
			}
		}
		flag = true;
		for(int i=0; i<n; i++){
			if(row[i]==false || col[i]==false) flag = false;
		}
		if(flag) printf("Yes\n");
		else printf("No\n");
	}

	return 0;
}
