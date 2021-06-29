#include <cstdio>
#include <iostream>

const int Maxr=105, Maxc=105;
int m[Maxr][Maxc], r, c, len, maxlen, data[Maxr][Maxc];
int me[4][2]={{1,0}, {-1,0}, {0,1}, {0,-1}};
int dfs(int, int);

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d %d", &r, &c);
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			scanf("%d", &m[i][j]);
		}
	}
	maxlen=0;
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			len=dfs(i, j);
			maxlen=maxlen>len?maxlen:len;
		}
	}

	printf("%d", maxlen);

	return 0;
}

int dfs(int x, int y){
	if(data[x][y]) return data[x][y];
	int maxl=0, l, px, py;
	for(int i=0; i<4; i++){
		px=x+me[i][0];
		py=y+me[i][1];
		if(px>=0 && px<r && py>=0 && py<c && m[px][py]<m[x][y]){
			l=dfs(px, py);
			maxl=l>maxl?l:maxl;
		}
	}
	data[x][y]=maxl+1;
	return maxl+1;
}
