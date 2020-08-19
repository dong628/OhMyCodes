#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

const int Maxm=5005, Inf=0x7fffffff;
int logg[Maxm][5], d[Maxm], n, m, k;
bool flag;
//typedef pair<int, int> pii;
//priority_queue<pii, vector<pii>, greater<pii> > q;
void dfs(int step);
int mini(void);

int main(){
	freopen("dish.in", "r", stdin);
	int t;
	scanf("%d", &t);
	for(int x=0; x<t; x++){
		flag=false;
		scanf("%d %d %d", &n, &m, &k);
		for(int i=1; i<=n; i++){
			scanf("%d", &d[i]);
//			q.push(make_pair(d, i));
		}
		dfs(0);
		if(!flag) printf("-1\n");
	}

	return 0;
}

void dfs(int step){
	if(flag) return;
	if(step==m){
		for(int i=0; i<m; i++){
			printf("%d %d", logg[i][0], logg[i][1]);
			if(logg[i][2]){
				printf(" %d %d", logg[i][2], logg[i][3]);
			}
			printf("\n");
		}
		flag=true;
		return;
	}
	else{
		int now=mini();
		if(d[now]>=k){
			logg[step][0]=now;
			logg[step][1]=k;
			d[now] -= k;
			dfs(step+1);
		}
		for(int i=1; i<n; i++){
			if(d[i]+d[now]>=k){
				logg[step][0]=now;
				logg[step][1]=d[now];
				logg[step][2]=i;
				logg[step][3]=k-d[now];
				d[i]-=k-d[now];
				dfs(step+1);
				d[i]+=k-d[now];
			}
		}
	}
}

int mini(void){
	int minn=Inf, minii;
	for(int i=1; i<=n; i++){
		if(d[i]>0 && d[i]<minn){
			minn=d[i];
			minii=i;
		}
	}
	return minii;
}
