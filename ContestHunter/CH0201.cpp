#include <cstdio>
#include <iostream>

const int Maxn = 25;
int n, m, ch;
std::bitset<Maxn> bits[Maxn], bitscpy[Maxn];

int main(){
	freopen("1876.in", "r", stdin);

	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			scanf("%d", ch);
			bits[i][j] = ch;
		}
	}
	for(int i=0; i<(1<<m); i++){
		for(int j=0; j<n; j++){
			bitscpy[j] =  bits[j];
		}
		for(int j=0; j<m; j++){
			if(i&(1<<j)){
				bitscpy[0][j] ^= 1;
				if(j>0) bitscpy[0][j-1] ^= 1;
				if(j<m-1) bitscpy[0][j+1] ^= 1;
			}
		}
		for(int j=1; j<n; j++){
			for(int k=0; k<m; k++){
				if(bitscpy[j-1][k]){
					bitscpy[j][k] ^= 1;
					bitscpy[j-1][k] ^= 1;
					if(k>0) bitscpy[j][k-1] ^= 1;
					if(k<m-1) bitscpy[j][k+1] ^= 1;
					if(j<n-1) bitscpy[j+1][k] ^= 1;
				}
			}
		}
		flag = true;
		for(int j=0; j<m; j++){
			if(bitscpy[n-1][j]==1) flag = false;
		}
		if(flag){
			for(int j=m-1; j>=0; j--){
				if(i&(1<<j)) printf("1");
				else printf("0");
			}
			printf("\n");
		}
	}

	return 0;
}
