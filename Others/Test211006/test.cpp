#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>

char s1[20], s2[20];

int main(){
	scanf("%s %s", s1, s2);
	for(int i=0; i<20; i++){
		printf("%d ", s1[i]);
	}

	return 0;
}
