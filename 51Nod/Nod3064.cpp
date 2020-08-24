#include <cstdio>
#include <iostream>

const int Max=100005;
int flor[Max], mf, maxx[Max], n, a, b;

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%d %d", &a, &b);
		flor[i]=flor[a]+1;
		mf=flor[i]>mf?flor[i]:mf;
		maxx[flor[i]]=maxx[flor[i]]>b?maxx[flor[i]]:b;
	}
	for(int i=1; i<=mf; i++){
		printf("%d ", maxx[i]);
	}

	return 0;
}
