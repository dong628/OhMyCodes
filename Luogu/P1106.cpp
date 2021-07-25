#include <cstdio>
#include <iostream>
#include <cstring>
using std::string;
using std::cin;

const int Maxn=255;
string n;
int cnt, stack[Maxn], head=1, k;

int main(){
	cin >> n;
	scanf("%d", &k);
	for(int i=0; i<n.size(); i++){
		while(stack[head-1]>int(n[i]-'0') && cnt<k && head>1){
			head--;
			cnt++;
		}
		stack[head++]=int(n[i]-'0');
	}
	int i;
	for(i=1; stack[i]==0; i++);
	if(i>=n.size()-k+1) printf("0");
	for(; i<n.size()-k+1; i++){
		printf("%d", stack[i]);
	}

	return 0;
}
