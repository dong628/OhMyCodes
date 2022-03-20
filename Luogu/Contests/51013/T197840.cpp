#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

const int Maxn=2005;
int t, n, m, di, ai, bi, q, e;
int cnt[Maxn], friends[Maxn];
bool chosen[Maxn];
struct Student{
	int num, val;
} d[Maxn];
std::vector<int> mapp[Maxn];
bool cmp(Student xx, Student yy) { return xx.val<yy.val; }
int solve(int);

int main(){
//	freopen("data.in", "r", stdin);

	scanf("%d", &t);
	for(int cs=0; cs<t; cs++){
		scanf("%d %d", &n, &m);
		for(int i=1; i<=n; i++){
			scanf("%d", &di);
			d[i].num=i; d[i].val=di;
		}
		std::sort(d+1, d+n+1, cmp);
		for(int i=1; i<=m; i++){
			scanf("%d %d", &ai, &bi);
			mapp[ai].push_back(bi);
			mapp[bi].push_back(ai);
			cnt[ai]++; cnt[bi]++;
//			judge[ai][bi] = true;
//			judge[bi][ai] = true;
		}
		scanf("%d", &q);
		for(int csq=1; csq<=q; csq++){
			scanf("%d", &e);
			printf("%d ", solve(e));
		}
		printf("\n");
	}

	return 0;
}

int solve(int pow){
	memset(chosen, 0, sizeof(chosen));
	memset(friends, 0, sizeof(friends));
	for(int i=1; i<=n; i++){
		if(pow>=d[i].val){
			chosen[d[i].num] = true;
			for(int j=0; j<cnt[d[i].num]; j++){
				friends[mapp[d[i].num][j]]++;
			}
			pow-=d[i].val;
		}
		else{
			for(int j=1; j<=n; j++){
				if(chosen[j] && (friends[j]==0)){
					chosen[j] = false;
					for(int k=0; k<cnt[j]; k++)
						friends[mapp[j][k]]--;
					pow += d[j].val;
				}
			}
			if(pow<d[i].val) break;
			else i--;
		}
	}
	int ans = 0;
	for(int i=1; i<=n; i++){
		if(chosen[i] && (friends[i]>0)) ans++;
	}
	return ans;
}
