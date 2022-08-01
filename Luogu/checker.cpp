#include <cstdio>
#include <cstdlib>
#include <iostream>

int main(){
	while(true){
		system("./gen");
		system("./djl");
		system("./std");
		if(system("diff std.out djl.out")){
			return 0;
		}
	}

	return 0;
}
