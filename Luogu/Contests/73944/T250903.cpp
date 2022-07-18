#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using std::sort;
using std::vector;

const int Maxn = 1e3+5;
vector<int> mapp[Maxn];
int n, k, u, v, cnt[Maxn], roots[Maxn], circ[Maxn][Maxn], block[Maxn][Maxn];
int cb[Maxn], cntc[Maxn], cntree, cntres, book[Maxn], cur, cost;
bool vis[Maxn], viscir[Maxn];
struct Val{
	int cost;
	double val;
} each[Maxn];
void dfs(int, int, int);
void ana(int);
int calc(int);
bool cmp(Val a, Val b) { return a.val>b.val; }

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d %d", &n, &k);
	for(int i=1; i<=n; i++){
		scanf("%d %d", &u, &v);
		mapp[u].push_back(v); mapp[v].push_back(u);
		cnt[u]++; cnt[v]++;
	}
	for(int i=1; i<=n; i++){
		if(!vis[i]){
			roots[cntree] = i;
			dfs(i, cntree, 0);
			cntree++;
		}
	}
	memset(vis, 0, sizeof(vis));
	for(int i=0; i<cntree; i++){
			ana(i);
	}
	sort(each, each+cntres, cmp);
	for(int i=0; i<cntres; i++){
		cur += each[i].val*each[i].cost;
		cost += each[i].cost;
		if(cur >= k){
			if(each[i].cost == 2){
				cur -= each[i].val*each[i].cost;
				for(int j=i+1; j<cntres; j++){
					if(each[j].cost == 1 && each[j].val+cur>=k){
						cost--;
						break;
					}
				}
			}	
			break;
		}
	}
	printf("%d", cost);

/*
	for(int i=0; i<cntres; i++){
		printf("%d %lf\n", cost[i], val[i]);
	}
*/
	return 0;
}

void dfs(int root, int count, int step){
	bool flag = false;
	vis[root] = true;
	book[step] = root;
	block[count][cb[count]++] = root;
	for(int i=0; i<cnt[root]; i++){
		if(!vis[mapp[root][i]]){
			dfs(mapp[root][i], count, step+1);
		}
		else if(mapp[root][i] != book[step-1] && (!viscir[count])){
//			circ[count][cntc[count]++] = mapp[root][i];
			viscir[count] = true;
			for(int j=step; book[j]!=mapp[root][i]; j--){
				circ[count][cntc[count]++] = book[j];
			}
			circ[count][cntc[count]++] = mapp[root][i];
		}
	}
}

void ana(int id){
	bool oncirc = false;
	int root = roots[id], available, tmp;
	for(int i=0; i<cntc[id]; i++){
		if(circ[id][i] == root){
			oncirc = true;
			break;
		}
	}
	if(oncirc){
		for(int i=0; i<cntc[id]; i++){
			vis[circ[id][i]] = true; 
		}
		for(int i=0; i<cnt[root]; i++){
			if(!vis[mapp[root][i]]){
				tmp = calc(mapp[root][i]);
				each[cntres].cost = 1; each[cntres].val = double(tmp);
				cntres++;
			}
		}
		for(int i=0; i<cntc[id]; i++){
			if(circ[id][i]!=root){
				vis[circ[id][i]] = false; 
				available = circ[id][i];
			}
		}
		tmp = calc(available);
		each[cntres].cost = 2; each[cntres].val = double(tmp)/2;
		cntres++;
	}
	else{
		vis[root] = true;
		for(int i=0; i<cnt[root]; i++){
			tmp = calc(mapp[root][i]);
			each[cntres].cost = 1; each[cntres].val = double(tmp);
			cntres++;
		}
	}
}

int calc(int root){
	int ans = 1;
	vis[root] = true;
	for(int i=0; i<cnt[root]; i++){
		if(!vis[mapp[root][i]]){
			ans += calc(mapp[root][i]);
		}
	}
	return ans;
}
