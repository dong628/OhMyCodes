#include <cstdio>
#include <iostream>
#include <cstring>

const int Max=2e5+5;
int t, cream, a[Max], b[Max], n;

int main(){
//	freopen("data.in", "r", stdin);

	scanf("%d", &t);
	for(int casenum=0; casenum<t; casenum++){
		memset(b, 0, sizeof(b));
		cream=0;
		scanf("%d", &n);
		for(int i=0; i<n; i++){
			scanf("%d", &a[i]);
		}
		for(int i=n-1; i>=0; i--){
			cream = cream>a[i]?cream:a[i];
			if(cream>0){
				b[i] = 1; cream--;
			}
		}
		for(int i=0; i<n; i++){
			printf("%d ", b[i]);
		}
		printf("\n");
	}

	return 0;
}
