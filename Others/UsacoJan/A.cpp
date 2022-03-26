#include <cstdio>
#include <iostream>

const int Maxn = 30;
char tar[Maxn], guess[Maxn];
int tha[Maxn], yellow, green;

int main(){
//	freopen("data.in", "r", stdin);

	for(int i=0; i<9; i++){
		scanf("%c", &tar[i]);
		if(tar[i] == '\n') i--;
		else tha[int(tar[i])-'A']++;
	}
	for(int i=0; i<9; i++){
		scanf("%c", &guess[i]);
		if(guess[i] == '\n') i--;
	}
//	printf("%s\n%s", tar, guess);
	for(int i=0; i<9; i++){
		if(tar[i] == guess[i]){
			green++;
			tha[int(tar[i])-'A']--;
		}
	}
	for(int i=0; i<9; i++){
		if(tar[i]!=guess[i] && tha[int(guess[i])-'A']>0){
			tha[int(guess[i])-'A']--;
			yellow++;
		}
	}
	printf("%d\n%d", green, yellow);


	return 0;
}
