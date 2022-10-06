#include <cstdio>
#include <iostream>

int main(){
	int cnt = 0;
	while(true){
		system("./gen");
		system("./bf > bf.out");
		system("./major > major.out");
		if(system("diff major.out bf.out")){
			printf("WA\n");
			break;
		}
		else{
			cnt++;
			printf("Accept! #%d\n", cnt);
		}
	}

	return 0;
}
