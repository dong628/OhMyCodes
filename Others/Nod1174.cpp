#include <cstdio>
#include <cmath>
#include <iostream>
using std::max;

const int Max=10005;
void init(void);
void search(int, int);
int a[Max], st[Max][17], n, m;

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
//		a[i]=read();
		scanf("%d", &a[i]);
	}
	init();
	scanf("%d", &m);
	int l, r;
	for(int i=0; i<m; i++){
//		l=read(); r=read();
		scanf("%d %d", &l, &r);
		search(l+1, r+1);
	}
	
	return 0;
}

void init(void){
	for(int i=1; i<=n; i++) st[i][0]=a[i];
	int t=log(n)/log(2)+1;
	for(int j=1; j<t; j++){
		for(int i=1; i<=n-(1<<j)+1; i++){
			st[i][j]=max(st[i][j-1], st[i+(1<<(j-1))][j-1]);
		}
	}
}

void search(int l, int r){
	int t=log(r-l+1)/log(2);
	int ans=max(st[l][t], st[r-(1<<t)+1][t]);
	printf("%d\n", ans);
}
