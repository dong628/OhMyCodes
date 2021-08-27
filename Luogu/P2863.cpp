#include <cstdio>
#include <iostream>
#include <vector>
using std::vector;

const int Maxn = 1e4+5;
int n, m, a, b, cnt[Maxn], ans, count, dfn[Maxn], low[Maxn], tm;
int stack[Maxn], top;
bool vis[Maxn];
int min(int xx, int yy) { return xx<yy?xx:yy; }
void tarjan(int);
vector<int> mapp[Maxn];

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d %d", &n, &m);
	for(int i=1; i<=m; i++){
		scanf("%d %d", &a, &b);
		mapp[a].push_back(b);
		cnt[a]++;
	}
	for(int i=1; i<=n; i++){
		if(!vis[i]){
			tarjan(i);
		}
	}
	printf("%d", ans);

	return 0;
}

void tarjan(int point){
	tm++;
	dfn[point] = low[point] = tm;
	vis[point] = true;
	stack[top++] = point;
	for(int i=0; i<cnt[point]; i++){
		if(!vis[mapp[point][i]]){
//			vis[mapp[point][i]] = true;
			tarjan(mapp[point][i]);
			low[point] = min(low[point], low[mapp[point][i]]);
		}
		else{
			for(int j=0; j<top; j++){
				if(stack[j] == mapp[point][i]){
					low[point] = min(low[mapp[point][i]], low[point]);
				}
			}
		}
	}
	if(low[point] == dfn[point]){
		count = 0;
		while(stack[top-1]!=point){
			count++;
			top--;
		}
		top--; count++;
		if(count>1) ans++;
	}
}
