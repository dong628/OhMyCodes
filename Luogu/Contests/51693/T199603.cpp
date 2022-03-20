#include <cstdio>
#include <iostream>

int t, a, A, b, B, c, C, maxc;
bool flag;
int max(int xx, int yy) { return xx>yy?xx:yy; }
int min(int xx, int yy) { return xx<yy?xx:yy; }
int upq(int, int);
bool calc(int, int);

int main(){
	scanf("%d", &t);
	for(int ct=0; ct<t; ct++){
		scanf("%d %d %d %d", &a, &A, &b, &B);
		if(a==0 || A==0){
			printf("-1 -1\n");
			continue;
		}
		maxc = max(a, A);
		flag = false;
		for(int i=upq(B,b+1); i>0; i--){
			c = max(b+1, upq(B, i));
			if(c>=maxc) break;
			C = b*(i-1)+1;
			if(calc(c, C)){
				printf("%d %d\n", c, C);
				flag = true;
				break;
			}
		}
		if(flag) continue;
		for(int i=upq(B, b-1); i<=B; i++){
			c = min(b-1, upq(B, i));
			if(c>=maxc) break;
			C = b*i+1;
			if(calc(c, C)){
				printf("%d %d\n", c, C);
				flag = true;
				break;
			}
		}
		if(!flag) printf("-1 -1\n");
	}

	return 0;
}

int upq(int xx, int yy){
	if((xx/yy)*yy==xx){
		return xx/yy;
	}
	else{
		return xx/yy+1;
	}
}

bool calc(int x, int X){
	if(x<a){
		return upq(X, a)<=upq(A, x);
	}
	else{
		return upq(X, a)<upq(A, x);
	}
}
