#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

const int Maxn = 1e3+5;
const double esp = 1e-7;
struct Point{
	double x, y;
} p[Maxn];
bool vis[Maxn];
int cnt;
int n;
std::vector <int> tree[Maxn], q, qbk;
double mans = 1e10;
void dfs(int), dfs1(int);
bool eq(double, double);
double calc(double, double, double, double);

int main(){
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);

	bool flagb = true;
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%lf %lf", &p[i].x, &p[i].y);
		if(i!=1 && ((p[i].x<p[i-1].x && !eq(p[i].x, p[i-1].x)) || (p[i].y>p[i-1].y && !eq(p[i].y, p[i-1].y)))) flagb = false;
	}
	if(flagb){
		for(int i=1; i<=n; i++) printf("%d ", i);
		return 0;
	}

	double minn = 1e8, dis;
	for(int i=2; i<=n; i++){
		dis = calc(p[1].x, p[1].y, p[i].x, p[i].y);
		minn = dis < minn ? dis : minn;
	}

	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(i == j) continue;
			dis = calc(p[i].x, p[i].y, p[j].x, p[j].y);
			if(eq(minn, dis)){
				tree[i].push_back(j);
			}
		}
	}
	int st = 1;
	for(int i=1; i<=n; i++){
		if(tree[i].size() == 1){
			st = i;
			break;
		}
	}

	dfs(st);
	if(cnt == n){
		for(int i=0; i<cnt; i++){
			printf("%d ", q[i]);
		}
		return 0;
	}

	memset(vis, 0, sizeof(vis));
	q.clear();
	dfs1(1);
	for(int i=0; i<n; i++){
		printf("%d ", qbk[i]);
	}

/*
	printf("%lf\n", calc(p[182].x, p[182].y, p[183].x, p[183].y));
	printf("%lf\n", calc(p[184].x, p[184].y, p[183].x, p[183].y));
	printf("%lf\n", calc(p[182].x, p[182].y, p[2].x, p[2].y));
	printf("%lf\n", calc(p[181].x, p[181].y, p[1].x, p[1].y));
*/

	return 0;
}

void dfs(int cur){
	q.push_back(cur);
	cnt++;
	vis[cur] = true;
	for(int i=0; i<tree[cur].size(); i++){
		if(vis[tree[cur][i]] == false) dfs(tree[cur][i]);
	}
}

double calc(double xa, double ya, double xb, double yb){
	return sqrt((xa-xb)*(xa-xb) + (ya-yb)*(ya-yb));
}

bool eq(double a, double b){
	double x = a - b;
	if(x < 0) x = -x;
	return x < esp;
}

void dfs1(int step){
	if(step == n+1){
		double sum = 0;
		for(int i=1; i<q.size(); i++){
			sum += calc(p[q[i]].x, p[q[i]].y, p[q[i-1]].x, p[q[i-1]].y);
		}
//		sum += calc(p[q[0]].x, p[q[0]].y, p[q[n-1]].x, p[q[n-1]].y);
		if(sum <= mans){
			qbk = q;
			mans = sum;
		}
		return;
	}
	for(int i=1; i<=n; i++){
		if(vis[i]) continue;
		q.push_back(i);
		vis[i] = true;
		dfs1(step+1);
		vis[i] = false;
		q.pop_back();
	}
}
