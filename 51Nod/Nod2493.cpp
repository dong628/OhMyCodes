#include <cstdio>
#include <iostream>

const int Max=10005;
int distance(int, int);
int tmp, cnt, n, ans, a[Max];

int main(){
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			ans+=distance(a[i], a[j]);
		}
	}
	printf("%d", ans);

	return 0;
}

int distance(int x, int y){
	tmp=x^y; cnt=0;
	while(tmp){
		tmp=tmp&(tmp-1);
		cnt++;
	}
	return cnt;
}
