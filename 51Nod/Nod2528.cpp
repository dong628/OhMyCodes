#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>

const int Max=105;
bool vis[Max];
int mid, log[Max], a[Max], n, maxx;
bool dfs(int);
inline int abs(int x) { return x>0?x:-x; }

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
		maxx=maxx>a[i]?maxx:a[i];
	}
	std::sort(a, a+n);
	int l=0, r=maxx;
	while(l<r){
		memset(log, 0, sizeof(log));
		memset(vis, 0, sizeof(vis));
		mid=(l+r)>>1;
		if(dfs(0)) r=mid;
		else l=mid+1;
	}
	printf("%d", l);

	return 0;
}

bool dfs(int step){
	if(step==n && abs(log[n-1]-log[0])<=mid){
		return true;
	}
	else{
		for(int i=0; i<n; i++){
			if((!vis[i]) && (step==0 || abs(a[i]-log[step-1])<=mid)){
				vis[i]=true;
				log[step]=a[i];
				if(dfs(step+1)) return true;
				vis[i]=false;
				log[step]=0;
			}
		}
	}
	return false;
}
