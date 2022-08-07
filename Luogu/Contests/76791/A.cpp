#include <cstdio>
#include <iostream>

const int Maxn = 114514;

int main(){
	freopen("data.in", "r", stdin);

	char a[20];
	int cnt = 0, t;
	bool flag, flag1, flag2;
	scanf("%d", &t);
	while(t--){
		cnt = 0;
		flag = false; flag1 = false; flag2 = false;
		scanf("%s", &a);
		for(int i=0; i<17; i++){
			if(a[i]==0 || a[i]==a[i-1]) cnt++;
			else cnt = 1;
			if(cnt == 4){
				flag = true;
			}
			if(a[i]=='X') flag1 = true;
			if(a[i]=='D') flag2 = true;
		}
		if(flag || (flag1&&flag2)) printf("Yes\n");
		else printf("no\n");
	}

	return 0;
}
