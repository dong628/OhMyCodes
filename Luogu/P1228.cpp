#include <cstdio>
#include <iostream>

void pl(int, int, int, int, int);

int main(){

	int k, x, y;
	scanf("%d %d %d", &k, &x, &y);
	pl(k, x, y, 0, 0);
	
	return 0;
}

void pl(int k, int x, int y, int xp, int yp){
	if(k==1){
		if(x==1){
			if(y==1){
				printf("%d %d 1\n", 2+xp, 2+yp);
			}
			else{
				printf("%d %d 2\n", 2+xp, 1+yp);
			}
		}
		else{
			if(y==1){
				printf("%d %d 3\n", 1+xp, 2+yp);
			}
			else{
				printf("%d %d 4\n", 1+xp, 1+yp);
			}
		}
		return;
	}

	int lb = 1<<(k-1);
	if(x<=lb){
		if(y<=lb){
			printf("%d %d 1\n", lb+1+xp, lb+1+yp);
			pl(k-1, x, y, xp, yp);
			pl(k-1, lb, 1, xp, yp+lb);
			pl(k-1, 1, lb, xp+lb, yp);
			pl(k-1, 1, 1, xp+lb, yp+lb);
		}
		else{
			printf("%d %d 2\n", lb+1+xp, lb+yp);
			pl(k-1, x, y-lb, xp, yp+lb);
			pl(k-1, lb, lb, xp, yp);
			pl(k-1, 1, lb, xp+lb, yp);
			pl(k-1, 1, 1, xp+lb, yp+lb);
		}
	}
	else{
		if(y<=lb){
			printf("%d %d 3\n", lb+xp, lb+1+yp);
			pl(k-1, lb, lb, xp, yp);
			pl(k-1, x-lb, y, xp+lb, yp);
			pl(k-1, lb, 1, xp, yp+lb);
			pl(k-1, 1, 1, xp+lb, yp+lb);
		}
		else{
			printf("%d %d 4\n", lb+xp, lb+yp);
			pl(k-1, lb, lb, xp, yp);
			pl(k-1, lb, 1, xp, yp+lb);
			pl(k-1, 1, lb, xp+lb, yp);
			pl(k-1, x-lb, y-lb, xp+lb, yp+lb);
		}
	}
}
