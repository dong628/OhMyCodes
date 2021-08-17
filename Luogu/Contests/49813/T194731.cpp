#include <cstdio>
#include <iostream>

const int Maxn=2e3+5;
int l, q, ans, left, right, x, y;
char ch, mapp[Maxn][Maxn];

int main(){
//	freopen("data.in", "r", stdin);
//	freopen("data.out", "w", stdout);

	scanf("%d %d\n", &l, &q);
	for(int i=1; i<=l; i++){
		for(int j=1; j<=l; j++){
			ch = getchar();
			mapp[i][j] = ch;
		}
		scanf("\n");
	}
/*	for(int i=1; i<=l; i++){
		for(int j=1; j<=l; j++){
			printf("%c", mapp[i][j]);
		}
		printf("\n");
	}*/
	if(l==1 || l==2){
		for(int i=1; i<=q; i++){
			printf("1\n");
		}
		return 0;
	}

	for(int i=1; i<=q; i++){
		scanf("%d %d", &x, &y);
		ans = 0;
		left = x; right = x;
		while(left>0 && right<=l){
			if(mapp[left][y] == mapp[right][y]){
				left--; right++;
			}
			else{
				left++; right--;
				break;
			}
		}
		if(left<=0 || right>l){
			left++; right--;
		}
		ans = right-left+1;

		left = y; right = y;
		while(left>0 && right<=l){
			if(mapp[x][left] == mapp[x][right]){
				left--; right++;
			}
			else{
				left++; right--;
				break;
			}
		}
		if(left<=0 || right>l){
			left++; right--;
		}
		ans = ans>(right-left+1)?ans:(right-left+1);
		printf("%d\n", ans);
	}

	return 0;
}
