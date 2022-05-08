#include <iostream>
#include <cstdio>
using namespace std;

const int Maxn = 2e6+5;
char cs1[Maxn], cs2[Maxn];
int pi[Maxn], j, ls2;
string s1, s2;

int main(){
	freopen("data.in", "r", stdin);

	scanf("%s %s", cs1, cs2);
	s1 = cs1; s2 = cs2;
	ls2 = s2.size();
	s2+='#'; s2 += s1;

	for(int i=1; i<s2.size(); i++){
		j = pi[i-1];
		while(j>0 && s2[i]!=s2[j]) j = pi[j-1];
		if(s2[i] == s2[j]) j++;
		pi[i] = j;
		if(i>ls2 && pi[i]==ls2) printf("%d\n", i-ls2*2+1);
	}

	for(int i=0; i<ls2; i++){
		printf("%d ", pi[i]);
	}

	return 0;
}
