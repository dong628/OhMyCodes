#include <cstdio>
#include <iostream>

const int Max=105;
int n, p, k, t[Max], ans, st[20], cnt, tmp;
void dfs(int);

int main(){
	scanf("%d %d", &n, &p);
	scanf("%d", &k);
	for(int i=0; i<k; i++){
		scanf("%d", &tmp);
		t[tmp]=1;
	}
	dfs(n);
	printf("%d", ans);

	return 0;
}

void dfs(int left){
	st[cnt++]=left;
	for(int i=0; i<cnt; i++){
		if(!t[st[i]]) { ans++; ans%=p; break;}
	}
	cnt--;
	for(int i=1; i<left; i++){
		st[cnt++]=i;
		dfs(left-i);
		cnt--;
	}
}

