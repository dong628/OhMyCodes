#include <cstdio>
#include <iostream>

bool flag;
int n, m, t, a[10], ans;
void dfs(int step);

int main(){
	scanf("%d", &t);
	for(int i=0; i<t; i++){
		ans=0;
		scanf("%d %d", &n, &m);
		dfs(0);
		printf("%d\n", ans);
	}

	return 0;
}

void dfs(int step){
	if(step==m){
		flag=false;
		for(int i=0; i<m; i++){
			if(flag && a[i]>a[i-1]) return;
			if(!flag && a[i]<a[i-1]) flag=true;
		}
		ans++;
		return;
	}
	else{
		for(int i=1; i<=n; i++){
			a[step]=i;
			dfs(step+1);
		}
	}
}
