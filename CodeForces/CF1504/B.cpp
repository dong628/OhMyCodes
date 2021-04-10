#include <cstdio>
#include <iostream>

const int Max=3e5+5;
int n, cntz, cnto, cnt, t;
bool flag;
char a[Max], b[Max];

int main(){
//	freopen("data.in", "r", stdin);

	scanf("%d", &t);
	for(int cnum=0; cnum<t; cnum++){
		scanf("%d\n", &n);
		scanf("%s\n%s", &a, &b);
		flag=false; cnt=0; cntz=0; cnto=0;
		for(int i=0; i<n; i++){
			if(a[i]!=b[i]){
				cnt++;
			}
			else if(a[i-1]!=b[i-1]){
				if(cnt&1 || cntz!=cnto){
					flag=true;
					printf("NO\n");
					break;
				}
				else{
					cnt=0;
				}
			}
			if(a[i]=='0') cntz++;
			if(a[i]=='1') cnto++;
		}
		if((!flag) && cnt>0){
			if(cnt&1 || cntz!=cnto){
				flag=true;
				printf("NO\n");
			}
		}
		if(!flag) printf("YES\n");
	}

	return 0;
}
