#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
using std::to_string, std::string;


int main(){
	long long cnt = 0, wacnt = 0, accnt = 0, num;
	printf("Input data amount: ");
	scanf("%lld", &num);
	string strgen;

//	while(true){
	for(int i=0; i<num; i++){
		cnt++;
		strgen = "echo " + to_string(cnt+1145) + " | ./gen";
//		printf("%s", strgen.c_str());
		system(strgen.c_str());
		system("./djl > djl.out");
		system("./std > std.out");
		if(system("diff std.out djl.out")){
			printf("Test %lld: Wrong answer!\n", cnt);
			wacnt++;
			return 0;
		}
		else{
//			printf("Test %lld: Accepted!\n", cnt);
			printf("%lld:AC ", cnt);
			fflush(stdout);
			accnt++;
		}
	}
	printf("Ac/All: %lld/%lld = %.3lf", accnt, num, double(accnt)/num);

	return 0;
}
