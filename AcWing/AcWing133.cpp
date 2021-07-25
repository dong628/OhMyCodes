#include <cstdio>
#include <iostream>

const int Maxn=1e5+5;
int n, top;
long long s[Maxn][2], length, h;
long long maxs;

int main(){
//	freopen("data.in", "r", stdin);

	for( ; ; ){
		scanf("%d", &n);
		if(n==0) return 0;

		s[0][0]=-1; top=1; maxs=0;
		for(int i=1; i<=n; i++){
			scanf("%lld", &h);
			length=0;
			for( ; s[top-1][0]>h; top--){
				length += s[top-1][1];
				maxs = maxs>length*s[top-1][0] ? maxs : length*s[top-1][0];
			}
			s[top][0]=h; s[top][1]=length+1;
			top++;
		}
		length = 0;
		while(top!=1){
			length += s[top-1][1];
			maxs = maxs>length*s[top-1][0] ? maxs : length*s[top-1][0];
			top--;
		}
		printf("%lld\n", maxs);
	}
}
