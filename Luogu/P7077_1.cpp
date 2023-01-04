#include <cstdio>
#include <iostream>

int main(){
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
	}
	scanf("%d", &m);
	for(int i=1; i<=m; i++){
		scanf("%d", t[i]);
		if(t[i] == 1){
			scanf("%d %d", &p[i], &v[i]);
		}
		else if(t[i] == 2){
			scanf("%d", &v[i]);
		}
		else{
			scanf("%d", &a[i]);
			for(int j=1; j<=a[i]; j++){
				scanf("%d", &tmp);
				g[i].push_back(tmp);
			}
		}
	}
	scanf("%d", &q);
	for(int i=1; i<q; i++){
		scanf("%d", &tmp);
		g[0].push_back(tmp);
	}

	tp(0);



	return 0;
}

void tp(int rt){
	queue <int> q;
	memset(vis, 0, sizeof(vis));
	q.push(rt);
	upxy[cnt++] = rt;
	while(!q.empty()){
		cur = q.front(); q.pop();
		for(int i=0; i<g[cur].size(); i++){
			if(!vis[g[cur][i]]){
				upxy[cnt++] = g[cur][i];
				vis[g[cur][i]] = true;
				q.push(g[cur][i]);
			}
		}
	}
}
