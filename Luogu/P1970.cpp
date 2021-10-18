#include <cstdio>
#include <iostream>

bool cur;
int fr, now, cnt, n, i;

int main(){
	scanf("%d", &n);
	scanf("%d", &fr);
	for(i=2; i<=n; i++){
		scanf("%d", &now);
		if(now<fr){
			cur = true;
			break;
		}
		else if(now>fr){
			cur = false;
			break;
		}
	}

	fr = now;
	cnt = 2;

	for( ; i<n; i++){
		scanf("%d", &now);
		if(cur){
			if(now>fr){
				cnt++;
				cur = !cur;
			}
			fr=now;
		}
		else{
			if(now<fr){
				cnt++;
				cur = !cur;
			}
			fr=now;
		}
	}
	printf("%d", cnt);

	return 0;
}
