#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>

const int Maxn = 1e6+5;
struct Ch{
	char ch;
	int pi;
}stack[Maxn];
int top, pi[Maxn], l, lens, lent;
char s[Maxn], t[Maxn];

int main(){
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);

	scanf("%s", s); lens = strlen(s);
	scanf("%s", t); lent = strlen(t);

	for(int i=1; i<lent; i++){
		l = pi[i-1];
		while(l>0 && t[i]!=t[l]) l = pi[l-1];
		if(t[i] == t[l]) l++;
		pi[i] = l;
	}
	
	l = 0;
	for(int i=0; i<lens; i++){
		while(l>0 && s[i]!=t[l]) l = pi[l-1];
		if(s[i] == t[l]) l++;
		if(l == lent){
			top -= strlen(t)-1;
			l = stack[top-1].pi;
		}
		else{
			stack[top].ch = s[i];
			stack[top].pi = l;
			top++;
		}
	}

	for(int i=0; i<top; i++){
		printf("%c", stack[i].ch);
	}

	return 0;
}
