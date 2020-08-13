#include <cstdio>
#include <iostream>
#include <algorithm>

const int Max=105;
int col[3*Max], zws, n, ans;
struct Node { int x, y; } p[Max];
bool cmp0(Node x, Node y) { return x.y < y.y; }
bool cmp1(Node x, Node y) { return x.x < y.x; }
inline int abs(int x) { return x>0?x:-x; }

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d %d", &p[i].x, &p[i].y);
		col[p[i].x+Max]++;
//		xmax = p[i].x>xmax?p[i].x:xmax;
//		xmin = p[i].x<xmin?p[i].x:xmin;
	}

	std::sort(p, p+n, cmp0);
	zws=p[n>>1].y;
	for(int i=0; i<n; i++){
		ans+=abs(p[i].y-zws);
	}

	std::sort(p, p+n, cmp1);
	zws=p[n>>1].x+Max;
	for(int i=0; i<n/2; i++){
		if(col[zws+i]>1){
			for(int j=zws+i+1; j<=zws+i+1+n; j++){
				if(col[j]==0){
					col[j]++;
					col[zws+i]--;
					ans+=j-(zws+i);
				}
				if(col[zws+i]==1) break;
			}
		}
		if(col[zws-i]>1){
			for(int j=zws-i-1; j>=zws-i-1-n; j--){
				if(col[j]==0){
					col[j]++;
					col[zws-i]--;
					ans+=zws-i-j;
				}
				if(col[zws+i]==1) break;
			}
		}
	}
	printf("%d", ans);


	return 0;
}
