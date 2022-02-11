#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>

const int Maxn = 1e6+5;
int pi[Maxn], h[Maxn], l, n;
char s[Maxn];

int main(){
	freopen("data.in", "r", stdin);

	scanf("%s", s);
	n = strlen(s);

	for(int i=1; i<n; i++){
		l = pi[i-1];
		while(l>0 && s[l]!=s[i]) l = pi[l-1];
		if(s[l] == s[i]) l++;
		pi[i] = l;
		h[l]++;
	}
	h[l]--;

	while(l>0){
		if(h[l]!=0){
			for(int i=0; i<l; i++) printf("%c", s[i]);
			return 0;
		}
		l = pi[l-1];
	}
	printf("Just a legend");

	return 0;
}
