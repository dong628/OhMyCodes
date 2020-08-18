#include <cstdio>
#include <cmath>
#include <iostream>
using std::max;
using std::min;

const int Max=500005;
const int Mod=1000000000;
void init(void);
int SearchMin(int, int);
int SearchMax(int, int);
int a[Max], stmin[Max][19], stmax[Max][19], n, m, summ;

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (!isdigit(ch)){if (ch=='-') f=-1;ch=getchar();}
	while (isdigit(ch)){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

int main(){
	freopen("data.in", "r", stdin);
	
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		a[i]=read();
//		scanf("%d", &a[i]);
	}
	init();
	for(int i=1; i<=n; i++){
		for(int j=i; j<=n; j++){
			summ += (j-i+1)*(SearchMin(i, j)%Mod)*(SearchMax(i, j)%Mod);
			summ %= Mod;
		}
	}
	printf("%d", summ);
	
	return 0;
}

void init(void){
	for(int i=1; i<=n; i++) { stmax[i][0]=a[i]; stmin[i][0]=a[i]; }
	int t=log(n)/log(2)+1;
	for(int j=1; j<t; j++){
		for(int i=1; i<=n-(1<<j)+1; i++){
			stmax[i][j]=max(stmax[i][j-1], stmax[i+(1<<(j-1))][j-1]);
			stmin[i][j]=min(stmin[i][j-1], stmin[i+(1<<(j-1))][j-1]);
		}
	}
}

int SearchMax(int l, int r){
	int t=log(r-l+1)/log(2);
	int ans=max(stmax[l][t], stmax[r-(1<<t)+1][t]);
	return ans;
}
int SearchMin(int l, int r){
	int t=log(r-l+1)/log(2);
	int ans=min(stmin[l][t], stmin[r-(1<<t)+1][t]);
	return ans;
}
