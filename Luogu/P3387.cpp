#include <cstdio>
#include <iostream>

void dfs(int);
void build(void);

int main(){
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++){
		scanf("%d", &oldval[i]);
	}
	for(int i=1; i<=m; i++){
		scanf("%d %d", &ui, &vi);
		mapp[ui].push_back(vi);
		cnt[ui]++;
	}
	for(int i=1; i<=n; i++){
		if(!vis[i]){
			vis[i] = true;
			stack[rear++] = i;
			dfs(i);
			rear--;
		}
	}
	build();

	return 0;
}

void dfs(int point){
	tim++;
	dfn[point] = tim;
	for(int i=0; i<cnt[point]; i++){
		if(!vis[mapp[point][i]]){
			vis[mapp[point][i]] = true;
			stack[rear++] = mapp[point][i];
			dfs(mapp[point][i]);
			rear--;
		}
		else{
			flag = false;
			for(fi=rear; fi>=0; fi--){
				if(mapp[point][fi] == stack[fi]){
					flag = true;
					break;
				}
			}
			if(flag == false){
				return;
			}
			for(int j=rear; j>=fi; j--){
				scc[cntscc][cnts[cntscc]++] = stack[j];
			}
			cntscc++;
		}
	}
}

void build(void){
	
}
