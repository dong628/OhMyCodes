#include <cstdio>
#include <iostream>

const int Maxr=505, Maxc=505;
int r, c, a, b, mapp[Maxr][Maxc], s[Maxr][Maxc], ll, rr, mid;
bool flag;
bool calc(int);

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d %d %d %d", &r, &c, &a, &b);
	for(int i=1; i<=r; i++){
		for(int j=1; j<=c; j++){
			scanf("%d", &mapp[i][j]);
			rr += mapp[i][j];
			s[i][j] = s[i-1][j]+s[i][j-1]-s[i-1][j-1]+mapp[i][j];
		}
	}
	while(ll<rr){
		mid = (ll+rr+1)>>1;
		if(calc(mid)) ll=mid;
		else rr=mid-1;
	}
	printf("%d", ll);

	return 0;
}

bool calc(int judge){
	int rows=1, rowe=1, cols=1, cole=1, tmp;
	for(int i=1; i<=a; i++){
		while(true){
			flag = false;
			cols=1; cole=1;
			for(int j=1; j<=b; j++){
				while(true){
					tmp=s[rowe][cole]-s[rows-1][cole]-s[rowe][cols-1]+s[rows-1][cols-1];
					if(tmp < judge) cole++;
					else{
						cols = cole+1;
						cole = cols;
						break;
					}
					if(cole > c){
						flag = true;
						break;
					}
				}
				if(flag) break;
			}
			if(flag) rowe++;
			else{
				rows = rowe+1;
				rowe = rows;
				break;
			}
			if(rowe > r){
				flag = true;
				break;
			}
		}
		if(flag) return false;
	}
	return true;
}
