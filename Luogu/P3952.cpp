#include <cstdio>
#include <iostream>

void input(void);

int main(){
	scanf("%d\n", &t);
	while(t --> 0){
		input();
	}

	return 0;
}

void input(void){
	int ch;
	scanf("%d ", &lines);
	getchar(); getchar();
	scanf("%c", &ch);
	if(ch == '1') fn = false;
	else fn = true;
	for(int i=0; i<lines; i++){
		
	}
}
