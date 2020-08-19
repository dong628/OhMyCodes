#include <cstdio>
#include <cstring>
#include <iostream>

const int Maxh=2005, Maxbin=2005, Maxn=2005;
struct Node{
	int cc, floor;
}fl[Maxn];
int cnt[Maxh][Maxbin], cntt[Maxh];
int btree(void);
bool judge(int);

int main(){
	freopen("surreal.in", "r", stdin);
	
	int N, m, maxh; bool flag;
	scanf("%d", &N);
	for(int e=0; e<N; e++){
		flag=false; memset(cnt, 0, sizeof(cnt));
		scanf("%d", &m);
		if(m==1){
			printf("Almost Complete\n");
			continue;
		}
		for(int i=0; i<m; i++){
			maxh=btree();
		}
		for(int i=1; i<=maxh; i++){
			if(judge(i)){
				printf("Almost Complete\n");
				flag=true;
				break;
			}
		}
		if(!flag) printf("No\n");
	}

	return 0;
}

int btree(void){
	int n, a, b, h=0;
	scanf("%d", &n);
	fl[1].floor=0; fl[1].cc=1;
	for(int i=1; i<=n; i++){
		scanf("%d %d", &a, &b);
		if(a==0 && b==0){
			cnt[fl[i].floor][fl[i].cc]++;
		}
		if(a){
			fl[a].floor=fl[i].floor+1;
			fl[a].cc=fl[i].cc*2-1;
			h=fl[a].floor>h?fl[a].floor:h;
		}
		if(b){
			fl[b].floor=fl[i].floor+1;
			fl[b].cc=fl[i].cc*2;
			h=fl[b].floor>h?fl[b].floor:h;
		}
	}
	return h;
}

bool judge(int floor){
	for(int i=1; i<=(1<<floor); i++){
		if(cnt[floor][i]<(1<<floor)) return false;
	}
	return true;
}
