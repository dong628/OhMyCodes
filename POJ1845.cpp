#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int a, b, summ;
const int modd=9901;
void fj(int);
int su(int, int);
int qpow(int, int, int);

int main(){
	scanf("%d %d", &a, &b);
	fj(a);
	printf("%d", summ%modd);
	
	return 0;
}

void fj(int n){
	int cnt;
	for(int i=2; i<=sqrt(n); i++){
		cnt=0;
		while(n%i==0){
			cnt++;
			n/=i;
		}
		if(cnt) summ *= su(i, b*cnt);
		summ %= modd;
	}
	if(n>1) summ=su(n, b)%modd;
}

int su(int p, int c){
	if(c==1) return p+1;
	else if(c==0) return 1;
	else if(c&1){
		return ((1+qpow(p, (c+1)/2, modd))%modd)*su(p, (c-1)/2)%modd;
	}
	else{
		return ((1+qpow(p, c/2, modd))%modd)*su(p, c/2-1)%modd+qpow(p, c, modd);
	}
}

int qpow(int x, int y, int m){
	int base=x, ans=1;
	while(y){
		if(y&1){
			ans *= base;
			ans %= m;
		}
		y >>= 1;
		base *= base;
		base %= m;
	}
	return ans;
}
