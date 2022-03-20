#include <cstdio>
#include <iostream>

const int Maxn = 305;
int n, a[Maxn], case1, case2;
bool flag1, flag2;

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
		if(a[i]==1) flag1 = true;
		if(a[i]==2) flag2 = true;
	}
	if(!(flag1 && flag2)){
		printf("1");
		return 0;
	}
	for(int i=1; i<=n; i++){
		if(a[i]==1 && a[i-1]!=1) case1++;
	}
	for(int i=1; i<=n; i++){
		if(a[i]==2 && a[i-1]!=2) case2++;
	}
	printf("%d", (case1<case2?case1:case2)+1);


	return 0;
}
