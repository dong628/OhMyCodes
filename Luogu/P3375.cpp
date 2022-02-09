#include <cstdio>
#include <iostream>
#include <cstring>
using std::string;

const int Maxn = 1e6+5, Maxm = 1e6+5;
int pi[Maxm+10];
char cs1[Maxn], cs2[Maxm];
void perfix(string);

int main(){
	freopen("data.in", "r", stdin);

	scanf("%s %s", cs1, cs2);
	string s1 = cs1, s2 = cs2;
	s2 += "#";
	int ls1 = s1.size(), ls2 = s2.size();
	
	perfix(s2);
	
	int lp = 0;
	for(int i=0; i<ls1; i++){
		while(lp>0 && s1[i]!=s2[lp]) lp = pi[lp-1];
		if(s1[i] == s2[lp]) lp++;
		if(lp == ls2-1) printf("%d\n", i-ls2+3);
	}

	for(int i=0; i<ls2-1; i++){
		printf("%d ", pi[i]);
	}

	return 0;
}

void perfix(string str){
	int n = str.size(), j;
	for(int i=1; i<n; i++){
		j = pi[i-1];
		while(j>0 && str[i]!=str[j]) j = pi[j-1];
		if(str[i] == str[j]) j++;
		pi[i] = j;
	}
}
