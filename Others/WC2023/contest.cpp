#include <iostream>
#include <cstdio>
#include <vector>
#include <random>
#include <algorithm>

const int Maxn = 2005;
int n, m, k[Maxn], a[Maxn][Maxn];
std::vector <int> mems, grp[Maxn];

bool valid(){
	for(int i=1; i<mems.size()-1; i++){
		for(int a=0; a<grp[mems[i-1]].size(); a++){
			for(int b=0; b<grp[mems[i]].size(); b++){
				for(int c=0; c<grp[mems[i+1]].size(); c++){
					if(grp[mems[i-1]][a] == grp[mems[i]][b] && grp[mems[i]][b] == grp[mems[i+1]][c]) return false;
				}
			}
		}
	}
	for(int a=0; a<grp[mems[n-2]].size(); a++){
		for(int b=0; b<grp[mems[n-1]].size(); b++){
			for(int c=0; c<grp[mems[0]].size(); c++){
				if(grp[mems[n-2]][a] == grp[mems[n-1]][b] && grp[mems[n-1]][b] == grp[mems[0]][c]) return false;
			}
		}
	}
	for(int a=0; a<grp[mems[n-1]].size(); a++){
		for(int b=0; b<grp[mems[0]].size(); b++){
			for(int c=0; c<grp[mems[1]].size(); c++){
				if(grp[mems[n-1]][a] == grp[mems[0]][b] && grp[mems[0]][b] == grp[mems[1]][c]) return false;
			}
		}
	}
	return true;
}

int main(){
	freopen("contest.in", "r", stdin);
	freopen("contest.out", "w", stdout);
	
	std::random_device dev;
	std::mt19937 gen(dev());
	bool flag;
	int t, t0;

	scanf("%d", &t);
	while(t-->0){
		scanf("%d %d", &n, &m);
		for(int i=1; i<=m; i++){
			scanf("%d", &k[i]);
			for(int j=1; j<=k[i]; j++){
				scanf("%d", &a[i][j]);
				grp[a[i][j]].push_back(i);
			}
		}
		if(m == 1){
			printf("-1\n");
			continue;
		}
		mems.clear(); flag = false;
		for(int i=1; i<=n; i++){
			mems.push_back(i);
		}
		while((double)clock()/CLOCKS_PER_SEC < (0.9-((double)clock()/CLOCKS_PER_SEC))/t){
			std::shuffle(mems.begin(), mems.end(), dev);
			if(valid()){
				for(int j=0; j<n; j++){
					printf("%d ", mems[j]);
				}
				printf("\n");
				flag = true;
				break;
			}
		}
		if(!flag) printf("-1\n");
	}

	return 0;
}
