#include <cstdio>
#include <iostream>
#include <cstring>
using std::string;

int k, cnt;
string x;

int main(){
	std::cin >> k >> x;
	std::cout << 1;
	cnt=x.size();
	for(int i=0; i<k-cnt; i++){
		std::cout << 0;
	}
	std::cout << x;

	return 0;
}
