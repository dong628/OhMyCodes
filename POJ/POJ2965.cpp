#include <cstdio>
#include <iostream>

void dfs(int);
int mkbin(int);
int pow(int, int);
char a;
int r, b, x, y, logx[20], logy[20], cnt, ans;

int main(){
	freopen("data.in", "r", stdin);

	for(int i=0; i<16; i++){
		scanf("%c", &a);
		if(a=='\n') i--;
		if(a=='+') { r*=2; r+=1; }
		if(a=='-') r*=2;
	}
	dfs(0);

	return 0;
}

void dfs(int step){
	if(r==0){
		printf("%d\n", cnt);
		for(int i=0; i<cnt; i++){
			printf("%d %d\n", logx[i], logy[i]);
		}
		return;
	}
	if(step==16) return;
	
	dfs(step+1);
	int b = mkbin(step);
	r = r^b;
	logx[cnt]=step/4+1;
	logy[cnt]=step%4+1;
	cnt++;
	dfs(step+1);
	r = r^b;
	cnt--;
}

int mkbin(int num){
	ans=0;
	x=num/4; y=num%4;
	ans^=15*pow(16, 3-x);
	ans^=pow(2, 3-y)*1;
	ans^=pow(2, 3-y)*16;
	ans^=pow(2, 3-y)*256;
	ans^=pow(2, 3-y)*4096;
	ans^=pow(2, 3-y)*pow(16, 3-x);
	return ans;
}

int pow(int c, int d){
	int anss=1;
	for(int i=0; i<d; i++) anss*=c;
	return anss;
}
