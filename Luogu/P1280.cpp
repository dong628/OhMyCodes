#include <cstdio>
#include <iostream>
#include <vector>
using std::vector;

const int Maxn = 1e4+5;
int n, k, p, t, f[Maxn];
vector<int> task[Maxn];

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d %d", &n, &k);
	for(int i=1; i<=k; i++){
		scanf("%d %d", &p, &t);
		task[p].push_back(t);
	}
	for(int i=n; i>=1; i--){
		if(task[i].empty()) f[i] = f[i+1]+1;
		else{
			for(int j=0; j<task[i].size(); j++){
				f[i] = f[i]>f[i+task[i][j]]?f[i]:f[i+task[i][j]];
			}
		}
	}
	printf("%d", f[1]);

	return 0;
}
