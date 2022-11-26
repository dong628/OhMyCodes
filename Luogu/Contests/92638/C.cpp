#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

const int Maxn = 2e4+5;
std::vector <char> str[Maxn];

int main(){
	freopen("data.in", "r", stdin);

	int cntl = 1, len;
	char a;
	while(true){
		a = getchar();
		if(a == EOF) break;
		str[cntl].push_back(a);
		if(a == '\n'){
			cntl++;
		}
	}
	len = (log(cntl)/log(10))+1;
	for(int i=1; i<cntl; i++){
		for(int j=0; j<len-(log(i)/log(10))-1; j++) putchar(' ');
		printf("%s ", std::to_string(i).c_str());
		for(int j=0; str[i][j] != '\n'; j++){
			putchar(str[i][j]);
		}
		putchar('\n');
	}

	return 0;
}
