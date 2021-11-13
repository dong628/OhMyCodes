#include <cstdio>
#include <iostream>

const int Maxn = (1<<10)+5;
int book[Maxn], n, k;
bool vis[Maxn], flag;
void dfs(int now, int step);
int pop(int xx){
	int cnt=0;
	while(xx){
		if(xx&1) cnt++;
		xx>>=1;
	}
	return cnt;
}

void print(int, int);

int main(){
	scanf("%d %d", &n, &k);
	
	book[0]=0; vis[0] = true;
	dfs(0, 1);
	if(flag == true){
		printf("1\n");
		for(int i=0; i<(1<<n); i++){
			print(book[i], n);
//			printf("%d ", book[i]);
		}
	}
	else{
		printf("0\n");
	}

	return 0;
}

void dfs(int now, int step){
	if(step == (1<<n)){
		flag = true;
		return;
	}
	for(int i=0; i<(1<<n); i++){
		if(pop(i^now)==k && !vis[i]){
			vis[i] = true;
			book[step] = i;
			dfs(i, step+1);
			if(flag==true) return;
			vis[i] = false;
		}
	}
}

void print(int num, int alpha){
	for(int i=alpha-1; i>=0; i--){
		if(num&(1<<i)) printf("1");
		else printf("0");
	}
	printf("\n");
}
