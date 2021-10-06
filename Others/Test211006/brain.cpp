#include <cstdio>
#include <iostream>

const int Maxn=1e5+5;
int n, m, x, y, z, node[Maxn], cnt[Maxn];
int a, b, t, s;

int main(){
	freopen("brain.in", "r", stdin);

	scanf("%d %d", &n, &m);
	for(int i=1; i<n; i++){
		scanf("%d %d %d", &x, &y, &z);
		if(x==1){
			node[y] = z;
		}
		else{
			node[x] = z;
		}
		cnt[z]++;
	}

	node[1] = 1;

	for(int i=1; i<=m; i++){
		scanf("%d %d %d %d", &a, &b, &t, &s);
		node[a]-=1; node[b]-=1;
		if(node[a]==0){
			node[a]=1;
		}
		else{
			cnt[node[a]+1]--;
			cnt[node[a]]++;
		}
		if(node[b]==0){
			node[b]=1;
		}
		else{
			cnt[node[b]+1]--;
			cnt[node[b]]++;
		}

		if((node[s]!=3&&node[t]!=3) || (node[s]==3&&node[t]==1) || (node[t]==3&&node[t]!=3)){
			printf("1 ");
		}
		else{
			printf("0 ");
		}

		if(node[t]==1){
			printf("%d\n", cnt[1]+cnt[2]+cnt[3]);
		}
		else if(node[t]==2){
			printf("%d\n", cnt[1]+cnt[2]);
		}
		else if(node[t]==3){
			printf("%d\n", cnt[1]+cnt[2]);
		}
	}

	return 0;
}
