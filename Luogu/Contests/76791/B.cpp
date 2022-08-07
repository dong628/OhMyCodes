#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using std::sort;

const int Maxn = 114514;
int a[20], h[20];
int pair, t;

int main(){
	freopen("data.in", "r", stdin);

	bool flag1, flag;
	scanf("%d", &t);
	while(t--){
		memset(h, 0, sizeof(h));
		pair = 0;
		flag1 = false; flag = false;
		scanf("%d %d %d %d", &a[1], &a[2], &a[3], &a[4]);
		sort(a+1, a+5);
		for(int i=1; i<5; i++){
			h[a[i]]++;
			if(h[a[i]]==2){
				flag1 = true;
				pair = a[i];
			}
		}
		if(flag1){
			h[pair] -= 2;
			for(int i=0; i<=9; i++){
				if((h[i]>0 && h[i+1]>0) || (i!=0&&h[i-1]>0&&h[i+1]>0)) flag = true;
			}
		}
		else{
			for(int i=1; i<=9; i++){
				if(h[i-1]>0 && h[i]>0 && h[i+1]>0) flag = true;
			}
		}
		printf("%d\n", flag);
	}

	return 0;
}
