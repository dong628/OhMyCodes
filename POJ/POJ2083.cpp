#include <cstdio>
#include <cstring>
#include <iostream>

bool image[750][750];
int n;
void fractal(int, int, int);
int pow(int, int);

int main(){
	while(true){
		scanf("%d", &n);
		if(n==-1) return 0;
		memset(image, 0, sizeof(image));
		fractal(n, 0, 0);
		for(int i=0; i<pow(3, n-1); i++){
			for(int j=0; j<pow(3, n-1); j++){
				if(image[i][j]) printf("X");
				else printf(" ");
			}
			printf("\n");
		}
		printf("-\n");
	}
	
	return 0;
}

void fractal(int level, int x, int y){
	if(level==1) image[x][y]=true;
	else{
		int pp=pow(3,level-2);
		fractal(level-1, x, y);
		fractal(level-1, x+2*pp, y);
		fractal(level-1, x+pp, y+pp);
		fractal(level-1, x, y+2*pp);
		fractal(level-1, x+2*pp, y+2*pp);
	}
}

int pow(int x, int y){
	int ans=1;
	for(int i=0; i<y; i++) ans*=x;
	return ans;
}
