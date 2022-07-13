#include <cstdio>
#include <iostream>

int t;
typedef unsigned long long lol;
lol n, l, r, mid, poww[20];
lol calc(lol);

int main(){
	scanf("%d", &t);
	poww[0] = 1;
	for(int i=1; i<=18; i++){
		poww[i] = poww[i-1]*10;
	}
	for(int cst=0; cst<t; cst++){
		scanf("%llu", &n);
		printf("%llu\n", calc(n));
/*		l = 1; r = n*10;
		while(l<r){
			mid = (l+r+1)>>1;
			if(calc(mid)<=n){
				l = mid;
			}
			else{
				r = mid-1;
			}
		}*/
	}

	return 0;
}
/*
lol calc(lol num){
	lol tmp = num, ans = 1;
	int cnt = 0;
	bool flag = false;
	while(tmp>=10){
		cnt++;
		tmp /= 10;
		if(tmp%10!=9) flag=true;
	}
	if(flag){
		for(int i=0; i<cnt+1; i++){
			ans *= 10;
		}
		ans *= 10; ans -= (1-tmp+1);
	}
	else{
		for(int i=0; i<cnt+1; i++){
			ans *= 10;
		}
		ans *= 10; ans -= (1-tmp);
	}
	return ans;
}*/

lol calc(lol num){
	num++;
	lol ans = 0;
	int wz[20], cnt = 0;
	while(num){
		wz[cnt++] = num%10;
		num /= 10;
	}
	for(int i=cnt-2; i>0; i--){
		if(wz[i]!=0){
			ans += poww[wz[cnt-1]];
			ans += wz[i]*poww[i];
			ans--;
			return ans;
		}
	}
	if(wz[0]==0 || wz[0]==1){
		return poww[cnt-1]-(10-wz[cnt-1]);
	}
	ans += (wz[0]-1)*poww[cnt-1];
	ans += wz[cnt-1];
	return ans;
}
