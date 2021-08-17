#include <cstdio>
#include <iostream>

const int Maxn=2e6+5;
bool flag;
int t, n, m, cnt;
char ch, s[Maxn], ans[Maxn];

int main(){
//	freopen("data.in", "r", stdin);

	scanf("%d", &t);
	for(int cs=0; cs<t; cs++){
		cnt=0;
		flag=false;
		scanf("%d %d\n", &n, &m);
		if(n==m){
			for(int i=1; i<=n; i++) getchar();
			printf("-1\n");
			continue;
		}
		for(int i=1; i<=n; i++){
			ch = getchar();
			s[i] = ch;
			if(ch==s[i-1] && flag==false){
				for(int j=1; j<=(m-n); j++){
					ans[cnt++] = (ch-'0')^1;
//					printf("%d", (ch-'0')^1);
				}
				ans[cnt++] = ch-'0';
//				printf("%d", ch-'0');
				flag=true;
			}
			else{
				ans[cnt++] = ch-'0';
//				putchar(ch);
			}
		}
		if(flag==false){
			if(n<3){
				printf("-1\n");
				continue;
			}
			else{
				putchar(s[1]);
				putchar(s[2]);
				for(int i=1; i<=(m-n); i++){
					printf("%d", s[2]-'0');
				}
				for(int i=3; i<=n; i++){
					printf("%d", s[i]-'0');
				}
			}
		}
		else{
			for(int i=0; i<cnt; i++){
				printf("%d", ans[i]);
			}
		}
		printf("\n");
	}

	return 0;
}
