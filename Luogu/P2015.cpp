#include <cstdio>
#include <iostream>
#include <vector>
using std::vector;

const int Maxn = 105;
struct zhi{
	int id, enod, val;
/*	zhi(int Id, int Enod, int Val){
		id = Id; enod = Enod; val=Val;
	}*/
	zhi(int id, int enod, int val):id(id),enod(enod),val(val){}
};
int n, q, a, b, c, val[Maxn], cnt[Maxn], tcnt[Maxn];
bool vis[Maxn];
vector<zhi> tmp[Maxn];
vector<int> mapp[Maxn];
void mktree(int, int);

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d %d", &n, &q);
	for(int i=1; i<n; i++){
		scanf("%d %d %d", &a, &b, &c);
		val[i] = c;
		tmp[a].push_back(zhi(i,b,c)); tcnt[a]++;
		tmp[b].push_back(zhi(i,a,c)); tcnt[b]++;
	}
	vis[1] = true;
	mktree(1, 0);

/*	for(int i=0; i<=n; i++){
		printf("%d(val:%d): ", i, val[i]);
		for(int j=0; j<cnt[i]; j++){
			printf("%d ", mapp[i][j]);
		}
		printf("\n");
	}*/



	return 0;
}

void mktree(int node, int root){
	for(int i=0; i<tcnt[node]; i++){
		if(!vis[tmp[node][i].enod]){
			mapp[root].push_back(tmp[node][i].id);
			cnt[root]++;
			vis[tmp[node][i].enod] = true;
			mktree(tmp[node][i].enod, tmp[node][i].id);
			vis[tmp[node][i].enod] = false;
		}
	}
}
