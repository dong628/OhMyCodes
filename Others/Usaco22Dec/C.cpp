#include <cstdio>
#include <iostream>
#include <cstring>

const int Maxn = 105;
struct Line{
	int ind;
	bool tar, ret;
} lines[Maxn];
int cs1[Maxn][Maxn], b[Maxn][Maxn], ret[Maxn];
int n, m;

int main(){
//	freopen("data.in", "r", stdin);

	int t, tmp;
	char ch;
	bool flag;
	scanf("%d", &t);
	while(t --> 0){
		scanf("%d %d\n", &n, &m);
		for(int i=1; i<=m; i++){
			for(int j=1; j<=n; j++){
				ch = getchar();
				b[i][j] = (ch == '0' ? 0 : 1);
			}
			scanf("%d\n", &ret[i]);
		}
		if(n == 2){
			flag = true; memset(cs1, 0, sizeof(cs1));
			for(int i=1; i<=m; i++){
				tmp = cs1[b[i][1]][b[i][2]];
				if(tmp > 0 && tmp != ret[i]) flag = false;
				else cs1[b[i][1]][b[i][2]] = ret[i];
			}
			if(flag == false){
				printf("LIE\n");
				continue;
			}
			if(cs1[0][0]==0 && cs1[0][1]==1 && cs1[1][0]==1 && cs1[1][1]==0){
				printf("LIE\n");
			}
			else printf("OK\n");
		}
		else if(m == 2){
			flag = false;
			for(int i=1; i<=n; i++){
				if(b[1][i] != b[2][i]) flag = true;
			}
			if(flag) printf("OK\n");
			else if(ret[1] != ret[2]) printf("LIE\n");
			else printf("OK\n");
		}
		else{
			printf("OK\n");
		}
	}

	return 0;
}

/*
void dfs(int dep){
	if(dep == n){
		flag = true;
		return;
	}
	bool flag1 = true, flag0 = true;
	for(int i=1; i<=n; i++){
		if(!vind[i]){
			vind = true;
			for(int j=1; j<=m; j++){
				if((!avai[j]) || b[j][i] != 1) flag1 = false; 
				if((!avai[j]) || b[j][i] != 0) flag0 = false; 
			}
			if(flag1){
				lines[dep].ind = i;
				lines[dep].tar = 1;
				lines[dep].ret = 0;
			}
		}
	}
}
*/
