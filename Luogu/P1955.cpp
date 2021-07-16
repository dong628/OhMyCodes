#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int Maxn=1e6+5;
bool flag;
int s[Maxn], t, a[Maxn], b[Maxn], e[Maxn], n, eq[Maxn][2], ju[Maxn][2], cntj=1, cntq=1;
int aa[Maxn], bb[Maxn], ee[Maxn], mapp[Maxn*2];
int find(int);
void merge(int, int);
void init(void);

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d", &t);
	for(int cs=0; cs<t; cs++){
		init();
		flag=true;
		cntj=1; cntq=1;
		scanf("%d", &n);
		for(int i=1; i<=n; i++){
			scanf("%d %d %d", &aa[i], &bb[i], &e[i]);
			mapp[2*i-1]=aa[i]; mapp[2*i]=bb[i];
		}
		sort(mapp, mapp+2*n);
		for(int i=1; i<=n; i++){
			a[i] = lower_bound(mapp+1, mapp+2*n+1, aa[i])-mapp;
			b[i] = lower_bound(mapp+1, mapp+2*n+1, bb[i])-mapp;
		}
		for(int i=1; i<=n; i++){
			if(e[i]){
				eq[cntq][0]=a[i];
				eq[cntq][1]=b[i];
				cntq++;
			}
			else{
				ju[cntj][0]=a[i];
				ju[cntj][1]=b[i];
				cntj++;
			}
		}
		for(int i=1; i<cntq; i++){
			merge(eq[i][0], eq[i][1]);
		}
		for(int i=1; i<cntj; i++){
			if(find(ju[i][0]) == find(ju[i][1])){
				flag=false;
				printf("NO\n");
				break;
			}
		}
		if(flag) printf("YES\n");
	}

	return 0;
}

int find(int a){
	if(s[a]==a) return a;
	else return s[a]=find(s[a]);
}

void merge(int x, int y){
	s[find(x)]=find(y);
}

void init(void){
	for(int i=1; i<=n; i++) s[i]=i;
}
