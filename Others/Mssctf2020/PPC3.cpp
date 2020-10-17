#include <cstdio>
#include <iostream>
using namespace std;

string s, subs[100005];
int t, n, len, les;

int main(){
	scanf("%d", &t);
	for(int i=0; i<t; i++){
		scanf("%d", &n);
		cin >> s;
		len=s.length();
		les=len-((len/n)*n);
		for(int i=0; i<les; i++){
			subs[i]=s.substr(i*(len/n+1), len/n+1);
		}
		for(int i=les; i<n; i++){
			subs[i]=s.substr(les*(len/n+1)+(i-les)*(len/n), len/n);
		}
		for(int i=0; i<len/n; i++){
			for(int j=0; j<n; j++){
				cout << subs[j][i];
			}
		}
		for(int i=0; i<les; i++){
			cout << subs[i][len/n];
		}
		cout << endl;
/*		for(int i=0; i<n; i++){
			cout << subs[i] << endl;
		}*/
	}

	return 0;
}
