#include <cstdio>
#include <iostream>

const int Maxn=55, Maxm=505, Maxk=205;
//const int Maxn=55, Maxm=55, Maxk=25;
struct Node{
	int v, w;
}mapp[Maxn][Maxm], msj[Maxn][Maxk];
int cnt[Maxn], cntm[Maxn], c[Maxn], maxx, n, m, T, k, u, v, w, t, x, y;
int yyz;
void dfs(int, int);

int main(){
	freopen("delicacy.in", "r", stdin);
	freopen("delicacy.out", "w", stdout);

	scanf("%d %d %d %d", &n, &m, &T, &k);
	for(int i=1; i<=n; i++){
		scanf("%d", &c[i]);
	}
	for(int i=0; i<m; i++){
		scanf("%d %d %d", &u, &v, &w);
		mapp[u][cnt[u]].v=v;
		mapp[u][cnt[u]].w=w;
		cnt[u]++;
	}
	for(int i=0; i<k; i++){
		scanf("%d %d %d", &t, &x, &y);
		msj[x][cntm[x]].v=t;
		msj[x][cntm[x]].w=y;
		cntm[x]++;
	}
	dfs(0, 1);
	printf("%d", maxx);


	return 0;
}

void dfs(int step, int city){
	if(step>T) return;
	for(int i=0; i<cntm[city]; i++){
		if(msj[city][i].v==step){
			yyz+=msj[city][i].w;
			break;
		}
	}
	yyz+=c[city];
	if(step==T && city==1){
		maxx=maxx>yyz?maxx:yyz;
		return;
	}
	else{
		int yyzold=yyz;
		for(int i=0; i<cnt[city]; i++){
			dfs(step+mapp[city][i].w, mapp[city][i].v);
			yyz=yyzold;
		}
	}
}
