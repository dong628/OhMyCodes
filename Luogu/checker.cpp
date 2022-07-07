#include <cstdio>
#include <cstdlib>
#include <iostream>

int main(){
	while(true){
		system("./gen");
		system("./a");
		system("./b");
		if(system("diff a.out b.out")){
			return 0;
		}
	}

	return 0;
}
