#include <cstdio>
#include <iostream>

const int Maxn=5e5+5;
int n, m, st[Maxn][2], top, cnt, summ, v, ans, tot;
char la, ch;

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d %d\n", &n, &m);
	for(int i=1; i<=n; i++){
		ch = getchar();
		if(la!=ch){
			st[top][0]=la-'0';
			st[top][1]=cnt;
			top++;
			cnt=1;
		}
		else{
			cnt++;
		}
		la = ch;
	}
	st[top][0]=la-'0';
	st[top][1]=cnt;
	for(int cs=1; cs<=m; cs++){
		scanf("%d", &v);
		summ=0;
		cnt=0;
		if(v>0){
			for(; top>0; top--){
				summ+=st[top][1];
				if(st[top][0]==0){
					cnt+=st[top][1];
					if(cnt>v){
						st[top][0] = 0;
						st[top][1] = cnt-v;
						top++;
						st[top][0] = 1;
						st[top][1] = summ-cnt+v;
						break;
					}
					else if(cnt==v){
						top--;
						st[top][1] += summ;
						break;
					}
				}
			}
			if(top==0){
				top++;
				st[top][0] = 1;
				st[top][1] = summ;
			}
		}
		else{
			v=-v;
			for(; top>0; top--){
				summ+=st[top][1];
				if(st[top][0]==1){
					cnt+=st[top][1];
					if(cnt>v){
						st[top][0] = 1;
						st[top][1] = cnt-v;
						top++;
						st[top][0] = 0;
						st[top][1] = summ-cnt+v;
						break;
					}
					else if(cnt==v){
						top--;
						st[top][1] += summ;
						break;
					}
				}
			}
			if(top==0){
				top++;
				st[top][0] = 0;
				st[top][1] = summ;
			}

		}
		ans=0; tot=0;
		for(int i=top; i>0; i--){
			tot += st[i][1];
			ans += tot;
		}
		printf("%d\r\n", ans);
	}

	return 0;
}
