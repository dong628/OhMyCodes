#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
using std::min;

const double eps = 1e-8;
const int Maxn = 40;
double x[Maxn], y[Maxn];
int f[(1<<19)], pass[Maxn][Maxn];

bool eq(double a, double b){
	if(a-b < eps && a-b > -eps) return true;
	else return false;
}
void solve(double &a, double &b, double xi, double yi, double xj, double yj){
	a = (yi*xj - yj*xi) / (xi*xi*xj - xi*xj*xj);
	b = (yi*xj*xj - yj*xi*xi) / (xi*xj*xj - xi*xi*xj);
}
bool calc(double a, double b, double xx, double yy){
	if(eq(a*xx*xx + b*xx, yy)) return true;
	else return false;
}
int lowbit(int xx){
	return xx&(-xx);
}

int main(){
	freopen("data.in", "r", stdin);

	int t, n, m, tmp;
	double tmpa, tmpb;
	scanf("%d", &t);

	while(t --> 0){
		scanf("%d %d", &n, &m);
		for(int i=0; i<n; i++){
			scanf("%lf %lf", &x[i], &y[i]);
		}
		memset(pass, 0, sizeof(pass));
		for(int i=0; i<n; i++){
			for(int j=i+1; j<n; j++){
				if(x[i] == x[j]) continue;
				solve(tmpa, tmpb, x[i], y[i], x[j], y[j]);
				if(tmpa > 0 || eq(tmpa, 0)) continue;
				for(int k=0; k<n; k++){
					if(calc(tmpa, tmpb, x[k], y[k])){
						pass[i][j] |= (1<<k);
					}
				}
			}
		}

		memset(f, 0x3f, sizeof(f));
		f[0] = 0;
		for(int s=0; s<(1<<n); s++){
			tmp = log2(lowbit(~s));
			f[s|(1<<tmp)] = min(f[s|(1<<tmp)], f[s]+1);
			for(int i=tmp+1; i<n; i++){
				f[s|pass[tmp][i]] = min(f[s|pass[tmp][i]], f[s]+1);
			}
		}

		printf("%d\n", f[(1<<n)-1]);
	}

	return 0;
}

