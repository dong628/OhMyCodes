#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <map>
using std::map;
using std::string;
using std::cin;

int n, m;
string st;
map<string, int> hash;

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d\n", &n);
	for(int i=1; i<=n; i++){
		cin >> st;
		hash[st]=0;
	}
	cin >> m;
	for(int i=1; i<=m; i++){
		cin >> st;
		if(hash.find(st)==hash.end()) printf("WRONG\n");
		else if(hash[st]==0){
			printf("OK\n");
			hash[st]++;
		}
		else printf("REPEAT\n");
	}

	return 0;
}
