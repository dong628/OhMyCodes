#include <cstdio>

typedef unsigned long long ull;
const int Maxn = 4e5+5;
bool s[Maxn+5][256], word[258];
void scan(void);
bool solve(int, int);
int k;

ull myRand(ull &k1, ull &k2) {
	ull k3 = k1, k4 = k2;
	k1 = k4;
	k3 ^= (k3 << 23);
	k2 = k3 ^ k4 ^ (k3 >> 17) ^ (k4 >> 26);
	return k2 + k4;
}

void gen(int n, ull a1, ull a2) {
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < 256; j++)
			s[i][j] = (myRand(a1, a2) & (1ull << 32)) ? 1 : 0;
}

int main() {
	freopen("qi.in", "r", stdin);
	freopen("qi.out", "w", stdout);

	int n, m;
	bool lastance=false;
	ull a1, a2;
	scanf("%d %d %llu %llu", &n, &m, &a1, &a2);
	gen(n, a1, a2);
	for(int i=1; i<=m; i++){
		getchar();
		scan();
		for(int j=0; j<256; j++) word[j]^=lastance;
		scanf("%d", &k);
		lastance = solve(n, k);
		printf("%d\n", int(lastance));
	}

	return 0;
}

bool solve(int n, int lim){
	int cnt;
	for(int i=1; i<=n; i++){
		cnt=0;
		for(int j=0; j<256; j++){
			if(word[j]!=s[i][j]) cnt++;
		}
//		printf("%d ", cnt);
		if(cnt<=lim){
//			printf("\n\n");
			return true;
		}
	}
	return false;
}

void scan(void){
	char a;
	for(int i=0; i<64; i++){
		a=getchar();
		switch(a){
			case '0' :	word[i*4] = 0;
					word[i*4+1] = 0;
					word[i*4+2] = 0;
					word[i*4+3] = 0;
					break;
			case '1' :	word[i*4] = 0;
					word[i*4+1] = 0;
					word[i*4+2] = 0;
					word[i*4+3] = 1;
					break;
			case '2' :	word[i*4] = 0;
					word[i*4+1] = 0;
					word[i*4+2] = 1;
					word[i*4+3] = 0;
					break;
			case '3' :	word[i*4] = 0;
					word[i*4+1] = 0;
					word[i*4+2] = 1;
					word[i*4+3] = 1;
					break;
			case '4' :	word[i*4] = 0;
					word[i*4+1] = 1;
					word[i*4+2] = 0;
					word[i*4+3] = 0;
					break;
			case '5' :	word[i*4] = 0;
					word[i*4+1] = 1;
					word[i*4+2] = 0;
					word[i*4+3] = 1;
					break;
			case '6' :	word[i*4] = 0;
					word[i*4+1] = 1;
					word[i*4+2] = 1;
					word[i*4+3] = 0;
					break;
			case '7' :	word[i*4] = 0;
					word[i*4+1] = 1;
					word[i*4+2] = 1;
					word[i*4+3] = 1;
					break;
			case '8' :	word[i*4] = 1;
					word[i*4+1] = 0;
					word[i*4+2] = 0;
					word[i*4+3] = 0;
					break;
			case '9' :	word[i*4] = 1;
					word[i*4+1] = 0;
					word[i*4+2] = 0;
					word[i*4+3] = 1;
					break;
			case 'A' :	word[i*4] = 1;
					word[i*4+1] = 0;
					word[i*4+2] = 1;
					word[i*4+3] = 0;
					break;
			case 'B' :	word[i*4] = 1;
					word[i*4+1] = 0;
					word[i*4+2] = 1;
					word[i*4+3] = 1;
					break;
			case 'C' :	word[i*4] = 1;
					word[i*4+1] = 1;
					word[i*4+2] = 0;
					word[i*4+3] = 0;
					break;
			case 'D' :	word[i*4] = 1;
					word[i*4+1] = 1;
					word[i*4+2] = 0;
					word[i*4+3] = 1;
					break;
			case 'E' :	word[i*4] = 1;
					word[i*4+1] = 1;
					word[i*4+2] = 1;
					word[i*4+3] = 0;
					break;
			case 'F' :	word[i*4] = 1;
					word[i*4+1] = 1;
					word[i*4+2] = 1;
					word[i*4+3] = 1;
					break;
		}
	}
}
