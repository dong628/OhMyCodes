#include <cstdio>
#include <iostream>
using std::max;

const int Max=18;
const int Inf=0x7fffffff;
int mapp[Max][Max], x, y, c, n, s[Max][Max];
int xmax, ymax, xmin=Inf, ymin=Inf;
void lb(void);
bool judge(int);

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d %d", &c, &n);
	for(int i=0; i<n; i++){
		scanf("%d %d", &x, &y);
		mapp[x][y]++;
		xmax = xmax>x?xmax:x;
		ymax = ymax>y?ymax:y;
		xmin = xmin<x?xmin:x;
		ymin = ymin<y?ymin:y;
	}
	for(int i=xmin; i<=xmax; i++)
		for(int j=ymin; j<=ymax; j++)
			s[i][j] = mapp[i][j]+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
	lb();

	return 0;
}

void lb(void){
	int l, r, mid;
	l=1; r = max(xmax-xmin,ymax-ymin)+1;
	while(l<r){
		mid=(l+r)>>1;
		if(judge(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d", l);
}

bool judge(int l){
	int tmp;
	for(int i=xmin-1; i<=max(xmax-l+1,xmin-1); i++){
		for(int j=ymin-1; j<=max(ymax-l+1,ymin-1); j++){
			tmp=s[i+l][j+l]-s[i+l][j]-s[i][j+l]+s[i][j];
			if(tmp>=c) return true;
		}
	}
	return false;
}
