#include <cstdio>
#include <iostream>

int main(){
	freopen("edge.in", "r", stdin);
	freopen("edge.out", "w", stdout);
	scanf("%d", &t);
	for(int cs=0; cs<t; cs++){
		scanf("%d %d", &n, &m);
		for(int i=1; i<n; i++){
			scanf("%d %d", &temp.u, &temp.v);
			edge[temp.u].push_back(temp);
			edge[temp.v].push_back(temp);
			cnt[temp.u]++;
			cnt[temp.v]++;
		}
		for(int i=1; i<=n; i++){
			if(cnt[i]==1){
				st=i;
				break;
			}
		}
		now=st; last=0;
		cnt=1;
		hash[st] = cnt++;
		do{
			if(edge[now][0].v!=last){
				last=now; now=edge[now][0].v;
				hash[now]=cnt++;
			}
			if(edge[now][1].v!=last){
				last=now; now=edge[now][1].v;
				hash[now]=cnt++;
			}
		}
		while(cnt[now]==1);
		for(int i=1; i<=m; i++){
			scanf("%d %d", &op, &a, &b);
			if(op==1){
				
			}
		}
	}

	return 0;
}
