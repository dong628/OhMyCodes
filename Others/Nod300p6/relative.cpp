#include <cstdio>
#include <iostream>
#include <algorithm>

const int Max=2e5+5;
struct Point{
	int x, num;
}x[Max];
int s, n, m, nu, point[Max], len, maxx, minn, a, l, zj;
inline bool cmp(Point a, Point b) { return a.x<b.x; }

int main(){
	freopen("relative.in", "r", stdin);
	freopen("relative.out", "w", stdout);

	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++){
		scanf("%d", &nu);
		point[i]=nu;
		x[i].x=nu; x[i].num=i;
	}
	std::sort(x+1, x+n+1, cmp);
	maxx=x[n].x;
	minn=x[1].x;
	len=x[n].x-x[1].x;
	for(int k=0; k<m; k++){
		scanf("%d %d", &a, &l);
		l-=x[n].x-point[a];
		if(l<0){
			zj=a;
			for(int i=n; i>0; i--){
				if(x[i].x<=maxx+l){
					zj=x[i].num;
					break;
				}
			}
		}
		else if((l/len)&1){
			s=l%len;
			for(int i=1; i<=n; i++){
				if(x[i].x<=minn+s){
					zj=x[i].num;
				}
				else break;
			}
		}
		else{
			s=l%len;
			for(int i=n; i>0; i--){
				if(x[i].x>=maxx-s){
					zj=x[i].num;
				}
				else break;
			}
		}
		printf("%d\n", zj);
	}

	return 0;
}
