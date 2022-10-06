#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
using std::vector, std::max;

const int Maxn = 1e6+5;
//const int Maxn = 5e1+5;
vector <int> nums[Maxn], cont[Maxn], quest[Maxn];
int cnt1[Maxn], cnt2[Maxn], l[Maxn], type[Maxn], tj[Maxn];
int n, q;
void solvea(void), solveb(void), bf(void);

int main(){
	freopen("major.in", "r", stdin);
	freopen("major.out", "w", stdout);

	int x, y, z, m, a;
	bool spa = true, spb = true;
	scanf("%d %d", &n, &q);
	for(int i=1; i<=n; i++){
		scanf("%d", &l[i]);
		cont[i].push_back(i);
		for(int j=0; j<l[i]; j++){
			scanf("%d", &a);
			nums[i].push_back(a);
			if(a != 1 && a != 2) spb = false;
		}
	}
	if(n != 1) spa = false;
	for(int i=1; i<=q; i++){
		scanf("%d", &type[i]);
		if(type[i] == 1){
			scanf("%d %d", &x, &y);
			quest[i].push_back(x); quest[i].push_back(y);
			if(y != 1 && y != 2) spb = false;
		}
		if(type[i] == 2){
			scanf("%d", &x);
			quest[i].push_back(x);
		}
		if(type[i] == 3){
			scanf("%d", &m);
			quest[i].push_back(m);
			while(m--){
				scanf("%d", &x);
				quest[i].push_back(x);
			}
		}
		if(type[i] == 4){
			spa = false;
			scanf("%d %d %d", &x, &y, &z);
			quest[i].push_back(x);
			quest[i].push_back(y);
			quest[i].push_back(z);
		}
	}
	if(spb){
		solveb();
	}
	else{
		bf();
	}
/*
	if(spa){
		solvea();
	}
*/

	return 0;
}

void solveb(void){
	int sum1, sum2, x, y, x1, x2, x3, m;

	for(int i=1; i<=n; i++){
		for(int j=0; j<l[i]; j++){
			if(nums[i][j] == 1) cnt1[i]++;
			else cnt2[i]++;
		}
	}
	for(int i=1; i<=q; i++){
		if(type[i] == 1){
			x = quest[i][0]; y = quest[i][1];
			nums[cont[x].back()].push_back(y);
			if(y == 1) cnt1[x]++;
			else cnt2[x]++;
		}
		if(type[i] == 2){
			x = quest[i][0];
			if(nums[cont[x].back()].back() == 1) cnt1[x]--;
			else cnt2[x]--;
			nums[cont[x].back()].pop_back();
			if(nums[cont[x].back()].empty() && cont[x].size()>1) cont[x].pop_back();
		}
		if(type[i] == 3){
			sum1 = 0; sum2 = 0;
			m = quest[i][0];
			for(int j=1; j<=m; j++){
				x = quest[i][j];
				sum1 += cnt1[x];
				sum2 += cnt2[x];
			}
			if(sum1 > sum2) printf("1\n");
			else if(sum1 < sum2) printf("2\n");
			else printf("-1\n");
		}
		if(type[i] == 4){
			x1 = quest[i][0]; x2 = quest[i][1]; x3 = quest[i][2];
			cnt1[x3] = cnt1[x1] + cnt1[x2];
			cnt2[x3] = cnt2[x1] + cnt2[x2];
			for(int i=0; i<cont[x1].size(); i++){
				cont[x3].push_back(cont[x1][i]);
			}
			for(int i=0; i<cont[x2].size(); i++){
				cont[x3].push_back(cont[x2][i]);
			}
		}
	}
}

void bf(void){
	int sum1, sum2, x, y, x1, x2, x3, m;
	int maxtj, tot, maxx;
	for(int i=1; i<=q; i++){
		if(type[i] == 1){
			x = quest[i][0]; y = quest[i][1];
			nums[x].push_back(y);
		}
		if(type[i] == 2){
			x = quest[i][0];
			nums[x].pop_back();
		}
		if(type[i] == 3){
			tot = 0; maxtj = 0;
			memset(tj, 0, sizeof(tj));
			m = quest[i][0];
			for(int j=1; j<=m; j++){
				x = quest[i][j];
				for(int k=0; k<nums[x].size(); k++){
					tj[nums[x][k]]++;
					if(maxtj < tj[nums[x][k]]){
						maxx = nums[x][k];
						maxtj = tj[nums[x][k]];
					}
				}
				tot += nums[x].size();
			}
			if(maxtj > tot/2) printf("%d\n", maxx);
			else printf("-1\n");
		}
		if(type[i] == 4){
			x1 = quest[i][0]; x2 = quest[i][1]; x3 = quest[i][2];
			for(int i=0; i<nums[x1].size(); i++){
				nums[x3].push_back(nums[x1][i]);
			}
			for(int i=0; i<nums[x2].size(); i++){
				nums[x3].push_back(nums[x2][i]);
			}
		}
	}
}
