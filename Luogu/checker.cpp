#include <cstdio>
#include <cstdlib>
#include <iostream>

int main(){
	long long cnt = 0;

	while(true){
		cnt++;
		system("./gen");
		system("./djl > djl.out");
		system("./std > std.out");
		if(system("diff std.out djl.out")){
			printf("Test %lld: Wrong answer!\n", cnt);
			return 0;
		}
		printf("Test %lld: Accepted!\n", cnt);
	}

	return 0;
}
