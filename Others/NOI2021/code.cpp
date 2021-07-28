#include <cstdio>
#include <iostream>

const int Maxn=2e5+5, Maxq=2e5+5, Mod=998244353;
int n, q, arr[4*Maxn], cntw, cnt;
char we[Maxn+Maxq];
void calc(void);
void Reverse(int, int);
void Flip(int, int);
int gcd(int x, int y){
	if(y==0) return x;
	return gcd(y, x%y);
}

int main(){
	freopen("code.in", "r", stdin);
	freopen("code.out", "w", stdout);

	scanf("%d %d", &n, &q);
	getchar();
	for(int i=1; i<=n; i++){
		scanf("%c", &we[i]);
	}
	cntw=n;
	getchar();
	calc();
	char ap, ty;
	int l, r;
	for(int i=1; i<=q; i++){
		ty = getchar();
		if(ty=='A'){
			for(int cnn=0; cnn<6; cnn++) getchar();
			ap = getchar();
			we[++cntw] = ap;
		}
		else if(ty=='F'){
			for(int cnn=0; cnn<4; cnn++) getchar();
			scanf("%d %d", &l, &r);
			Flip(l, r);
		}
		else{
			for(int cnn=0; cnn<7; cnn++) getchar();
			scanf("%d %d", &l, &r);
			Reverse(l, r);
		}
		calc();
		getchar();
	}

	return 0;
}

void calc(void){
	arr[0] = 0; arr[1] = 1; cnt=2;
	for(int i=1; i<=cntw; i++){
		if(we[i]=='W'){
			arr[cnt-1]++;
		}
		else{
			if(arr[cnt-1]==1) arr[cnt-2]++;
			else{
				arr[cnt-1]--;
				arr[cnt++]=1;
				arr[cnt++]=1;
			}
		}
	}
	int a=arr[cnt-1], b=1, c;
	for(int i=cnt-2; i>=0; i--){
		c=a; a=b; b=c;
		a+=(arr[i]*b)%Mod;
		a%=Mod;
	}
	
	printf("%d %d\n", a%Mod, b%Mod);
}

void Reverse(int l, int r){
	char tmp;
	for(int i=l; i<=((l+r)>>1); i++){
		tmp = we[i];
		we[i] = we[r-(i-l)];
		we[r-(i-l)] = tmp;
	}
}

void Flip(int l, int r){
	for(int i=l; i<=r; i++){
		if(we[i]=='W') we[i]='E';
		else we[i]='W';
	}
}
