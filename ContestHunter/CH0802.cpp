#include <cstdio>
#include <iostream>

int card[15][55], pos[15], cnt[15], ret, life, ans, cnow, len[15];
char a, b, c, d;
int decode(char);

int main(){
	freopen("data.in", "r", stdin);
	life=4;
	for(int i=1; i<=13; i++){
		scanf("%c %c %c %c\n", &d, &c, &b, &a);
		card[i][0]=decode(a);
		card[i][1]=decode(b);
		card[i][2]=decode(c);
		card[i][3]=decode(d);
	}
	while(life!=0){
		cnow=card[13][--life];
		while(cnow!=13){
			cnow=card[cnow][cnt[cnow]++];
		}
	}
	for(int i=1; i<=12; i++) if(cnt[i]==4) ans++;
	printf("%d", ans);
	
	
	return 0;
}

int decode(char x){
	switch(x){
		case '0' : ret=10; break;
		case 'J' : ret=11; break;
		case 'Q' : ret=12; break;
		case 'K' : ret=13; break;
		case 'A' : ret=1; break;
	}
	if(x>'0' && x<='9') ret=int(x-'0');
	return ret;
}
