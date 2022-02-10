#include <iostream>
#include <cstdio>

const int Maxn = 1e6+5;
int n, pi[Maxn];
char a[Maxn];

int main(){
	scanf("%d", &n);
	scanf("%s", a);

	for(int i=1; i<n; i++){
		l = pi[i-1];
		while(l>0 && a[i]!=a[l]) l = pi[l-1];
		if(a[i] == a[l]) l++;
		pi[i] = l;
		if(a[i] == a[l-1]){
			l--;
		}
		else{
			
		}
	}

	return 0;
}
