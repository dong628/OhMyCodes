#include <cstdio>
#include <iostream>

const int Maxn = 1e5+5;

bool que[Maxn][Maxn], vis[Maxn][Maxn];
int qx, qy, front, rear, a, b, ind[Maxn], indmax;
int nt, mt, n, m, inp[Maxn][2], queue[Maxn][2], ans[Maxn][Maxn];
int cs[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d %d", &n, &m);
	nt = n; mt = m;
	for(int i=1; i<=n; i++){
		scanf("%d %d", &a, &b);
		que[a][b] = true;
		inp[i][0] = a; inp[i][1] = b;
	}
	for(int i=1; i<=m; i++){
		scanf("%d", &ind[i]);
		indmax = ind[i]>indmax?ind[i]:indmax;
	}
	queue[rear][0]=0; queue[rear][1]=0;
	rear++;
	while(front != rear){
		for(int i=0; i<4; i++){
			qx=queue[front][0]+cs[i][0]; qy=queue[front][1]+cs[i][1];
			if(!vis[qx][qy]){
				vis[qx][qy] = true;
				queue[rear][0] = qx; queue[rear][1] = qy;
				if(que[qx][qy]) nt--;
				ans[qx][qy] = rear;
				rear++;
			}
		}
		if(nt<=0 && rear>=indmax) break;
	}

	for(int i=1; i<=n; i++){
		printf("%d\n", ans[inp[i][0]][inp[i][1]]);
	}
	for(int i=1; i<=m; i++){
		printf("%d %d\n", queue[ind[i]][0], queue[ind[i]][1]);
	}
	
	return 0;
}
