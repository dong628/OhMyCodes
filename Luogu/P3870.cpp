#include <cstdio>
#include <iostream>
#include <cmath>

const int Maxn = 1e5+5;
int num[Maxn], len[Maxn], lm, c, a, b, n, m, cnt;;
bool sw[Maxn], part[Maxn];

void turn(int, int);
int count(int, int);

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d %d", &n, &m);
	lm = int(sqrt(n));
	cnt = n/lm;
	for(int i=0; i<cnt; i++){
		len[i] = lm;
	}
	len[cnt] = n-(n/lm)*lm;
	
	for(int i=0; i<m; i++){
		scanf("%d %d %d", &c, &a, &b);
		a--; b--;
		if(c == 0){
			turn(a, b);
		}
		else{
			printf("%d\n", count(a, b));
		}
	}

	return 0;
}

void turn(int l, int r){
	if(l/lm+1 >= r/lm){
		for(int i=l; i<=r; i++){
			sw[i] = !sw[i];
			if(sw[i]) num[i/lm]++;
			else num[i/lm]--;
		}
	}
	else{
		for(int i=l; i<=(l/lm+1)*lm-1; i++){
			sw[i] = !sw[i];
			if(sw[i]) num[l/lm]++;
			else num[l/lm]--;
		}
		for(int i=l/lm+1; i<r/lm; i++){
			part[i] = !part[i];
		}
		for(int i=(r/lm)*lm; i<=r; i++){
			sw[i] = !sw[i];
			if(sw[i]) num[r/lm]++;
			else num[r/lm]--;
		}
	}
}

int count(int l, int r){
	int ans = 0;
	if(l/lm+1 >= r/lm){
		for(int i=l; i<=r; i++){
			if(sw[i]^part[i/lm]) ans++;
		}
	}
	else{
		for(int i=l; i<=(l/lm+1)*lm-1; i++){
			if(sw[i]^part[l/lm]) ans++;
		}
		for(int i=l/lm+1; i<r/lm; i++){
			if(part[i]) ans += lm-num[i];
			else ans += num[i];
		}
		for(int i=(r/lm)*lm; i<=r; i++){
			if(sw[i]^part[r/lm]) ans++;
		}
	}
	return ans;
}
