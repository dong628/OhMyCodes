#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int mat[4][4];
void placenum(void), printmat(void);
int rand24();
bool gravity(char);

int main(){
	time_t t;
	srand((unsigned)(time(&t)));
	char opt;
	for( ; ; ){
		placenum();
		while(true){
			printmat();
			printf("input option: ");
			opt = getchar();
			getchar();
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
	int pmat[4][4], tmpmat[4][4];
	if(opt == 's'){
		for(int i=0; i<4; i++){
			for(int j=0; j<4; j++){
				pmat[i][j] = mat[3-i][j];
			}
		}
	}
	else if(opt == 'd'){
		for(int i=0; i<4; i++){
			for(int j=0; j<4; j++){
				tmpmat[i][j] = mat[i][3-j];
			}
		}
		for(int i=0; i<4; i++){
			for(int j=0; j<4; j++){
				pmat[j][i] = tmpmat[i][j];
			}
		}
	}
	else if(opt == 'w'){
		for(int i=0; i<4; i++){
			for(int j=0; j<4; j++){
				pmat[i][j] = mat[i][j];
			}
		}
	}
	else if(opt == 'a'){
		for(int i=0; i<4; i++){
			for(int j=0; j<4; j++){
				pmat[j][i] = mat[i][j];
			}
		}
	}
	else{
		return false;
	}

/*
	printf("turned:\n");
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			printf("|%d\t", pmat[i][j]);
		}
		printf("|\n");
	}
	printf("\n");
*/


	int drop_mat[10][10], merge_mat[10][10], layer, layer_last;
	memset(drop_mat, 0, sizeof(drop_mat));
	memset(merge_mat, 0, sizeof(merge_mat));
	for(int j=0; j<4; j++){
		layer = 0;
		for(int i=0; i<4; i++){
			if(pmat[i][j] != 0){
				drop_mat[layer++][j] = pmat[i][j];
			}
		}
		for(int i=0; i<4; i++){
			if(drop_mat[i][j] == drop_mat[i+1][j]){
				drop_mat[i][j] <<= 1;
				drop_mat[i+1][j] = 0;
			}
		}
		layer = 0;
		for(int i=0; i<4; i++){
			if(drop_mat[i][j] != 0){
				merge_mat[layer++][j] = drop_mat[i][j];
			}
		}
	}
/*
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
*/
	bool ret = false;
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			if(merge_mat[i][j] != pmat[i][j]){
				ret = true;
			}
		}
	}

	if(opt == 's'){
		for(int i=0; i<4; i++){
			for(int j=0; j<4; j++){
				mat[i][j] = merge_mat[3-i][j];
			}
		}
	}
	if(opt == 'd'){
		for(int i=0; i<4; i++){
			for(int j=0; j<4; j++){
				tmpmat[j][i] = merge_mat[i][j];
			}
		}
		for(int i=0; i<4; i++){
			for(int j=0; j<4; j++){
				mat[i][j] = tmpmat[i][3-j];
			}
		}
	}
	if(opt == 'w'){
		for(int i=0; i<4; i++){
			for(int j=0; j<4; j++){
				mat[i][j] = merge_mat[i][j];
			}
		}
	}
	if(opt == 'a'){
		for(int i=0; i<4; i++){
			for(int j=0; j<4; j++){
				mat[j][i] = merge_mat[i][j];
			}
		}
	}

	return ret;
}

int rand24(){
	if(rand()%10 == 0){
		return 4;
	}
	else{
		return 2;
	}
}
