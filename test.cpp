#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
	vector<int> a;
	a.insert(a.begin(), 3);
	a.insert(a.begin(), 2);
	a.insert(a.begin(), 1);
	a.insert(a.begin()+1, 0);
	for(int i=0; i<4; i++){
		printf("%d", a[i]);
	}

	return 0;
}
