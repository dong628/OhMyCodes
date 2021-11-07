#include <cstdio>
#include <iostream>
#include <cmath>

long long abs(long long xx) {return xx>0?xx:-xx;}
long long c, n, m, a, b, ans, base, step, ansa, ansb;
double d;

int main(){
//	freopen("data.in", "r", stdin);

	scanf("%lld %lld", &n, &m);
	for(int i=1; i<=n; i++){
		scanf("%lld %lld", &a, &b);
		step = abs(a)+abs(b);
		base = (step-1)*2*step;
		if(a==0 && b<0){
			ans = 2*b*b-2*b;
		}
		else if(a==0 && b>0){
			ans = 2*b*b;
		}
		else if(b==0 && a<0){
			ans = 2*a*a-a;
		}
		else if(b==0 && a>0){
			ans = base+1;
		}
		else if(a>=0 && b>=0){
			ans = base+2*b;
		}
		else if(a>=0 && b<=0){
			ans = base-2*b+1;
		}
		else if(a<=0 && b>=0){
			ans = 2*step*step-a;
		}
		else{
			ans = 2*step*step+step-b;
		}
		printf("%lld\n", ans);
	}
	for(int i=1; i<=m; i++){
		scanf("%lf", &d);
		c = (long long)(d);
		d--;
		step = (long long)((4+(long long)(sqrt(16+16*d)))/8);
		printf("%lld\n", step);
		base = (step-1)*2*step+1;
		c -= base;
		if(c<=2*step*step && (c&1)){
			ansb = (c+1)/2;
			ansa = step-ansb;
		}
		else if(c<=2*step*step && !(c&1)){
			ansb = -c/2;
			ansa = step+ansb;
		}
		else if(c>2*step*step && c<=2*step*step+step){
			ansa = c-2*step*step;
			ansb = -(step-ansa);
		}
		else if(c>2*step*step+step){
			ansb = -(c-2*step*step);
			ansa = -(step+ansb);
		}
		printf("%lld %lld\n", ansa, ansb);
	}

	return 0;
}

