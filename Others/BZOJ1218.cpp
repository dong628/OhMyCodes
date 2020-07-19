#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int MAX=5005;
int s[MAX][MAX], n, r, summ, maxx, x, y, w;
int xmax, ymax;

int main(){
	freopen("data.in", "r", stdin);
	scanf("%d %d", &n, &r);
	if(r>5000) r=5000;
	for(int i=0; i<n; i++){
		scanf("%d %d %d", &x, &y, &w);
		xmax = xmax>x?xmax:x;
		ymax = ymax>y?ymax:y;
		s[x][y] += w;
	}
	for(int i=1; i<=5000; i++){
		s[i][0] += s[i-1][0];
	}
	for(int i=1; i<=5000; i++){
		s[0][i] += s[0][i-1];
	}
	for(int i=1; i<=5000; i++){
		for(int j=1; j<=5000; j++){
			s[i][j] += s[i-1][j]+s[i][j-1]-s[i-1][j-1];
		}
	}
	for(int i=0; i<=5000-r; i++){
		for(int j=0; j<=5000-r; j++){
			summ = s[i+r][j+r]-s[i+r][j]-s[i][j+r]+s[i][j];
			maxx = maxx>summ?maxx:summ;
		}
	}
	printf("%d", maxx);

	return 0;
}
