#include <cstdio>
#include <iostream>

int t;
const double Esp=1e-10;
double h1, h2, d, r, l, mid, mmid;
inline double calc(double x) { return h1-((h1-h2)/x*d)+(d-x); }

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d", &t);
	for(int tt=0; tt<t; tt++){
		scanf("%lf %lf %lf", &h1, &h2, &d);
		l=0; r=d;
		while(r-l>Esp){
			mid=(l+r)/2;
			mmid=(mid+r)/2;
			if(calc(mid)>calc(mmid)) r=mmid;
			else l=mid;
		}
		printf("%.3lf ", calc(l));
	}

	return 0;
}
