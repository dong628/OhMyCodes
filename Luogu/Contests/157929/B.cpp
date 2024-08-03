#include <cstdio>
#include <iostream>

const int Maxn = 1e5+5;
char a[Maxn], tmp;
int bcnt, n, m;

int main(){
	scanf("%d %d\n", &n, &m);
	for(int i=0; i<n; i++){
		a[i] = getchar();
	}
	getchar();
	for(int i=0; i<n; i++){
		tmp = getchar();
		if(tmp == '#')
			bcnt++;
	}
	int cur = 0;
	for(int i=0; i<n; i++){
		if(a[i] == '#'){
			a[i] = 'a'+cur;
			if(bcnt >= 25-cur){
				bcnt -= 25-cur;
				cur = 0;
			}
			else{
				cur++;
				cur %= 26;
			}
		}
	}
	printf("%s", a);

	return 0;
}
