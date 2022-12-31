#include <cstdio>
#include <iostream>
#include <cstring>

const int Maxn = 3e5+5;
int n, cnt, count[Maxn], mapp[2*Maxn][2], bcj[Maxn];
int rt(int);
void merge(int, int);

int main(){
	freopen("data.in", "r", stdin);

	bool flag3 = true;
	scanf("%d", &n);
	if(n & 1){
		printf("-1");
		return 0;
	}

	for(int i=1; i<n; i++){
		mapp[cnt][0] = i; mapp[cnt][1] = i+1;
		cnt++;
	}
	mapp[cnt][0] = n; mapp[cnt][1] = 1;
	cnt++;

	int u, v;
	for(int i=1; i<=n-3; i++){
		scanf("%d %d", &u, &v);
		mapp[cnt][0] = u; mapp[cnt][1] = v;
		cnt++;
		if(u != 1) flag3 = false;
	}

	if(flag3){
		for(int i=2; i<=n; i++){
			printf("1 %d\n", i);
		}
		return 0;
	}

	bool avai;
	int cnt1, root;
	for(int i=0; i<(1<<(2*n-3)); i++){
		cnt1 = 0;
		for(int j=0; j<2*n-3; j++){
			if(i & (1<<j)) cnt1++;
		}
		if(cnt1 != n-1) continue;
		memset(count, 0, sizeof(count));
		for(int j=1; j<=n; j++) bcj[j] = j;
		for(int j=0; j<2*n-3; j++){
			if(i & (1<<j)){
				count[mapp[j][0]]++;
				count[mapp[j][1]]++;
				merge(mapp[j][0], mapp[j][1]);
			}
		}
		avai = true;
		for(int i=1; i<=n; i++) if(!(count[i] & 1)) avai = false;
		root = rt(1);
		for(int i=2; i<=n; i++){
			if(rt(i) != root) avai = false;
		}
		if(avai){
			for(int j=0; j<2*n-3; j++){
				if(i & (1<<j)) printf("%d %d\n", mapp[j][0], mapp[j][1]);
			}
			return 0;
		}
	}

	return 0;
}

int rt(int x){
	if(bcj[x] == x) return x;
	else return bcj[x] = rt(bcj[x]);
}

void merge(int x, int y){
	bcj[rt(x)] = rt(y);
} 
