#include <cstdio>
#include <iostream>

int t, n, rr, bb;
char r[1005], b[1005];

int main(){
//	freopen("data.in", "r", stdin);

	scanf("%d", &t);
	for(int x=0; x<t; x++){
		rr=0; bb=0;
		scanf("%d", &n);
		scanf("%s\n", &r);
		scanf("%s\n", &b);
		for(int i=0; i<n; i++){
			if(r[i]>b[i]) rr++;
			else if(r[i]<b[i]) bb++;
		}
		if(rr>bb) printf("RED\n");
		else if(rr<bb) printf("BLUE\n");
		else printf("EQUAL\n");
	}

	return 0;
}
