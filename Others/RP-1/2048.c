#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int mat[4][4];
void placenum(void), printmat(void);

int main(){
	time_t t;
	srand(unsigned(time(&t)));
	char opt;
	for( ; ; ){
		placenum();
		printmat();
		while(true){
			printf("input option: ");
			opt = getchar();
			if(gravity(opt)) break;
		}
	}

	return 0;
}

void placenum(void){
	int zerocnt = 0, zeros[20][2];
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			if(mat[i][j] == 0){
				zeros[zerocnt][0] = i;
				zeros[zerocnt][1] = j;
				zerocnt++;
			}
		}
	}
	int p_coord = rand()%zerocnt;
	mat[zeros[p_coord][0]][zeros[p_coord][1]] = rand24();
}

void printmat(void){
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			printf("|%d\t", mat[i][j]);
		}
		printf("|\n");
	}
}

bool gravity(char opt){
	int pmat[4][4];
	if(opt == "W"){
		for(int i=0; i<4; i++){
			for(int j=0; j<4; j++){
				pmat[i][j] = mat[3-i][j];
			}
		}
	}
	if(opt == "A"){
		for(int i=0; i<4; i++){
			for(int j=0; j<4; j++){
				pmat[i][j] = mat[3-i][j];
			}
		}
		for(int i=0; i<4; i++){
			for(int j=0; j<4; j++){
				pmat[j][i] = mat[i][j];
			}
		}
	}
	if(opt == "S"){
		for(int i=0; i<4; i++){
			for(int j=0; j<4; j++){
				pmat[i][j] = mat[i][j];
			}
		}
	}
	if(opt == "D"){
		for(int i=0; i<4; i++){
			for(int j=0; j<4; j++){
				pmat[j][i] = mat[i][j];
			}
		}
	}

	int drop_mat[4][4];
	memset(drop_mat, 0, sizeof(drop_mat));
	for(int j=1; j<4; j++){
		layer = 3;
		for(int i=3; i>=0; i--){
			if(pmat[i][j] == 0) continue;
			if(i>0 && pmat[i-1][j] == pmat[i][j]){
				drop_mat[layer--][j] = pmat[i][j] << 1;
				i--;
			}
			else{
				drop_mat[layer--][j] = pmat[i][j];
			}
		}
	}
	bool ret = false;
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			if(drop_mat[i][j] != pmat[i][j]){
				ret = true;
			}
		}
	}

	if(opt == "W"){
		for(int i=0; i<4; i++){
			for(int j=0; j<4; j++){
				mat[i][j] = drop_mat[3-i][j];
			}
		}
	}
	if(opt == "A"){
		for(int i=0; i<4; i++){
			for(int j=0; j<4; j++){
				mat[j][i] = drop_mat[i][j];
			}
		}
		for(int i=0; i<4; i++){
			for(int j=0; j<4; j++){
				mat[i][j] = drop_mat[3-i][j];
			}
		}
	}
	if(opt == "S"){
		for(int i=0; i<4; i++){
			for(int j=0; j<4; j++){
				mat[i][j] = drop_mat[i][j];
			}
		}
	}
	if(opt == "D"){
		for(int i=0; i<4; i++){
			for(int j=0; j<4; j++){
				mat[j][i] = drop_mat[i][j];
			}
		}
	}

	return ret;
}
