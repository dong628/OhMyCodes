#include <cstdio>
#include <iostream>
#include <algorithm>

const int Maxn=1005, Maxx=1e6+5;
int n, x, y, xa[Maxn], ya[Maxn], xy[Maxn][2], p1, p2, p3, p4, xx, yy, minx=0x7fffffff;
int sm[Maxn][Maxn], mapp[Maxn][Maxn], xm[Maxx], ym[Maxx], xp, yp, cntx, cnty;

int main(){
	freopen("data.in", "r", stdin);
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%d %d", &x, &y);
		if(xm[x]==0){
			xa[++cntx]=x;
			xm[x]++;
		}
		if(ym[y]==0){
			ya[++cnty]=y;
			ym[y]++;
		}
		xy[i][0]=x; xy[i][1]=y;
	}
	std::sort(xa+1, xa+1+cntx);
	std::sort(ya+1, ya+1+cnty);

	for(int i=1; i<=n; i++){
		xp = std::lower_bound(xa+1, xa+1+cntx, xy[i][0])-xa;
		yp = std::lower_bound(ya+1, ya+1+cnty, xy[i][1])-ya;
		mapp[xp][yp]++;
	}
	
	for(int i=1; i<=cntx; i++){
		for(int j=1; j<=cnty; j++){
			sm[i][j] = sm[i-1][j]+sm[i][j-1]-sm[i-1][j-1]+mapp[i][j];
		}
	}
	for(int i=1; i<=cntx; i++){
		for(int j=1; j<=cnty; j++){
			p1 = sm[i][j];
			p2 = sm[cntx][j]-p1;
			p3 = sm[i][cnty]-p1;
			p4 = n-p1-p2-p3;
			p1 = p1>p2?p1:p2;
			p1 = p1>p3?p1:p3;
			p1 = p1>p4?p1:p4;
			minx = minx<p1?minx:p1;
		}
	}
	printf("%d", minx);

/*	if(n&1){
		xx=(xa[n/2]+xa[n/2-1])/2;
		yy=(ya[n/2]+ya[n/2-1])/2;
	}
	else{
		xx=xa[n/2-1];
		yy=ya[n/2-1];
	}

	for(int i=0; i<n; i++){
		if(xy[i][1]>xx && xy[i][2]>yy) p1++;
		if(xy[i][1]<xx && xy[i][2]>yy) p2++;
		if(xy[i][1]>xx && xy[i][2]<yy) p3++;
		if(xy[i][1]<xx && xy[i][2]<yy) p4++;
	}
	maxx=p1;
	maxx=maxx>p2?maxx:p2;
	maxx=maxx>p3?maxx:p3;
	maxx=maxx>p4?maxx:p4;
	printf("%d", maxx);
*/
	return 0;
}
