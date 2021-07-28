#include <cstdio>
#include <iostream>

const int Maxn=5e4+5;
long long px, py;
int q, ansb=1, n, ax[Maxn], ay[Maxn], bx[Maxn], by[Maxn];
long long ansa=-0x3f3f3f3f;
void Intersect(int i, int j);

int main(){
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%d %d %d %d", &ax[i], &ay[i], &bx[i], &by[i]);
	}
	for(int i=1; i<=n; i++){
		for(int j=i+1; j<=n; j++){
			Intersect(i, j);
			if(py*ansb>q*ansa){
				ansa=py; ansb=q;
			}
		}
	}
	printf("%.8f", ansa/(double)ansb);

	return 0;
}


void Intersect(int i, int j) {
	px = (long long)(ay[j] * bx[j] - ax[j] * by[j]) * (ax[i] - bx[i]) - (long long)(ay[i] * bx[i] - ax[i] * by[i]) * (ax[j] - bx[j]);
	py = (long long)(ax[i] * by[i] - ay[i] * bx[i]) * (ay[j] - by[j]) - (long long)(ax[j] * by[j] - ay[j] * bx[j]) * (ay[i] - by[i]);
	q = (ax[i] - bx[i]) * (ay[j] - by[j]) - (ax[j] - bx[j]) * (ay[i] - by[i]);
	if (q < 0) px *= -1, py *= -1, q *= -1;

//	printf("(%lld / %d, %lld / %d)\n", px, q, py, q);
//	printf("(%.8f, %.8f)\n", px / (double)q, py / (double)q);
}
