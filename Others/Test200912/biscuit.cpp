#include <cstdio>
#include <iostream>

char ch;
inline int min(int a, int b) { return a>b?b:a; }
int n, minn=0xfffffff, cnt[5][10005];
bool flag;

int main(){
	freopen("biscuit.in", "r", stdin);
	freopen("biscuit.out", "w", stdout);

	scanf("%d", &n);
	getchar();
	for(int i=0; i<4; i++){
		flag=true;
		for(int j=1; j<=n*n; j++){
			scanf("%c", &ch);
			if(int(ch-'0')==int(flag)) cnt[i][0]++;
			else cnt[i][1]++;
			flag=!flag;
			if(j%3==0) getchar();
		}
	}
	minn = min(cnt[0][0]+cnt[1][0]+cnt[2][1]+cnt[3][1], minn);
	minn = min(cnt[0][0]+cnt[2][0]+cnt[1][1]+cnt[3][1], minn);
	minn = min(cnt[0][0]+cnt[3][0]+cnt[2][1]+cnt[1][1], minn);
	minn = min(cnt[1][0]+cnt[2][0]+cnt[0][1]+cnt[3][1], minn);
	minn = min(cnt[1][0]+cnt[3][0]+cnt[0][1]+cnt[2][1], minn);
	minn = min(cnt[2][0]+cnt[3][0]+cnt[0][1]+cnt[1][1], minn);
	printf("%d", minn);

	return 0;
}
