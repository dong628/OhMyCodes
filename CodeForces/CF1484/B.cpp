#include <cstdio>
#include <iostream>

int t, n, start, a1, a2, sec, pos, neg;
bool flag;

int main(){
//	freopen("data.in", "r", stdin);

	scanf("%d", &t);
	for(int cn=0; cn<t; cn++){
		pos=0; neg=0; flag=false;
		scanf("%d", &n);
		scanf("%d", &start);
		if(n==2){
			scanf("%d", &a1);
			printf("0\n");
			continue;
		}
		a1=start;
		for(int i=1; i<n; i++){
			scanf("%d", &a2);
			if(a1>a2){
				if(neg==0) neg=a2-a1;
				else if(neg!=a2-a1){
					flag=true;
					printf("-1\n");
					break;
				}
			}
			if(a1<a2){
				if(pos==0) pos=a2-a1;
				else if(pos!=a2-a1){
					flag=true;
					printf("-1\n");
					break;
				}
			}
			if(a1==a2 && (neg!=0 || pos!=0)) {
				flag=true;
				printf("-1\n");
				break;
			}
			a1=a2;
		}
		if(flag) continue;
		if(start>=pos-neg){
			printf("-1\n");
			continue;
		}
		if(pos-neg==0){
			printf("0\n");
		}
		printf("%d %d\n", pos-neg, pos);
	}
	
	return 0;
}
