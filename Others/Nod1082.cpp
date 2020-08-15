#include <cstdio>
#include <iostream>

const int Max=1000005;
typedef long long lli;
lli calc(int);
lli table[Max];
int t, n, cnt=1;
inline bool ws(int);

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d", &t);
	for(int i=0; i<t; i++){
		scanf("%d", &n);
		printf("%lld\n", calc(n));
	}

	return 0;
}

lli calc(int x){
	if(table[x]) return table[x];
	else{
		for(int i=cnt; i<=x; i++){
			if(i%7 && ws(i)) table[i]=table[i-1]+i*i;
			else table[i]=table[i-1];
		}
		cnt=x+1;
		return table[x];
	}
}

inline bool ws(int x){
	while(x) {
		if(x%10==7) return false;
		else x/=10;
	}
	return true;
}
