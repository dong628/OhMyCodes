#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;

int k, n[6];
// int k, n[6], f[31][31][31][31][31];

void w(){
	long long f[n[1]+1][n[2]+1][n[3]+1][n[4]+1][n[5]+1];
	memset(f, 0, sizeof(f));
	f[0][0][0][0][0]=1;
	
	for(int a5=0; a5<=n[5]; a5++)
	for(int a4=0; a4<=n[4]; a4++)
	for(int a3=0; a3<=n[3]; a3++)
	for(int a2=0; a2<=n[2]; a2++)
	for(int a1=0; a1<=n[1]; a1++){
		if(a1<n[1]) f[a1+1][a2][a3][a4][a5]+=f[a1][a2][a3][a4][a5];
		if(a2<n[2] && a2<a1) f[a1][a2+1][a3][a4][a5]+=f[a1][a2][a3][a4][a5];
		if(a3<n[3] && a3<a2) f[a1][a2][a3+1][a4][a5]+=f[a1][a2][a3][a4][a5];
		if(a4<n[4] && a4<a3) f[a1][a2][a3][a4+1][a5]+=f[a1][a2][a3][a4][a5];
		if(a5<n[5] && a5<a4) f[a1][a2][a3][a4][a5+1]+=f[a1][a2][a3][a4][a5];
	}
	printf("%d\n", f[n[1]][n[2]][n[3]][n[4]][n[5]]);
}

int main(){
	for( ; ; ){
		scanf("%d", &k);
		if(k==0) break;
		memset(n, 0, sizeof(n));
		for(int i=1; i<=k; i++){
			scanf("%d", &n[i]);
		}
		w();
	}

	return 0;
}
