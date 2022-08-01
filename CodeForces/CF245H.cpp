#include <cstdio>
#include <iostream>
#include <cstring>

const int Maxn = 5005;
char s[Maxn];
int ans[Maxn][Maxn], q; 
bool visc[Maxn][Maxn], visj[Maxn][Maxn], jud[Maxn][Maxn];
void calc(void);
void cjudge(int, int);
void cans(int, int);

int main(){
	freopen("data.in", "r", stdin);

	int l, r;
	scanf("%s", s+1);
	calc();
	scanf("%d", &q);
	while(q--){
		scanf("%d %d", &l, &r);
		printf("%d\n", ans[l][r]);
	}

	return 0;
}

void calc(void){
	int n = strlen(s+1);
	for(int i=1; i<=n; i++){
		for(int j=i; j<=n; j++){
			cjudge(i, j);
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=i; j<=n; j++){
			cans(i, j);
		}
	}
}

void cjudge(int l, int r){
	if(visj[l][r]) return;
	if(l==r || l+1==r){
		jud[l][r] = (s[l]==s[r]);
	}
	else{
		cjudge(l+1, r-1);
		jud[l][r] = jud[l+1][r-1] && (s[l]==s[r]);
	}
	visj[l][r] = true;
}

void cans(int l, int r){
	if(visc[l][r]) return;
	if(l==r){
		ans[l][r] = 1;
	}
	else if(l+1 == r){
		ans[l][r] = 2+(s[l]==s[r]);
	}
	else{
		cans(l+1, r); cans(l, r-1); cans(l+1, r-1);
		ans[l][r] = ans[l+1][r]+ans[l][r-1]-ans[l+1][r-1]+jud[l][r];
	}
	visc[l][r] = true;
}
