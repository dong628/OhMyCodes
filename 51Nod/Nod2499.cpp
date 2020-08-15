#include <cstdio>
#include <iostream>

const int Max=11;
int n, a[Max], b[Max];

int main(){
	scanf("%d", &n);
	int cnt=0, n1=n;
	while(n1){
		a[cnt++]=n1%10; n1/=10;
	}
	bool flag=false;
	for(int i=cnt-1; i>1; i--){
		if(flag) printf("9");
		else if(a[i-1]-a[i]>0) printf("%d", a[i]);
		else{
			flag=true; printf("%d", a[i]-1);
		}
	}
	if(flag) printf("99\n");
	else {
		if(a[1]<=a[0]) printf("%d%d\n", a[1], a[0]);
		else printf("%d9\n", a[1]-1);
	}


	return 0;
}
