#include <cstdio>
#include <iostream>

const int Maxn = 1e6+5;
int n, pi[Maxn], l;
char s[Maxn];

int main(){
	scanf("%d", &n);
	scanf("%s", s);

	for(int i=1; i<n; i++){
		l = pi[i-1];
		while(l>0 && s[i]!=s[l]) l = pi[l-1];
		if(s[i]==s[l]) l++;
		pi[i] = l;
	}

	printf("%d", n-l);

	return 0;
}
