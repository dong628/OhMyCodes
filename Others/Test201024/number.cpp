#include <cstdio>
#include <iostream>
#include <cstring>

const int Maxl=1e5+5;
char n[Maxl];
int len, cnt, last, left7, left4, last_left4, last_left7, mem[Maxl], num;
bool flag;

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	while(scanf("%s", &n)==1){
		flag=false;
		len=strlen(n);
		if(len&1){
			cnt=(len+1)>>1;
			for(int i=0; i<cnt; i++) putchar('4');
			for(int i=0; i<cnt; i++) putchar('7');
			putchar('\n');
			continue;
		}
		last=-1;
		left7=left4=len>>1;
		for(int i=0; i<len; i++){
			num=int(n[i]-'0');
			if(num<4){
				left4--;
				mem[i]=4;
				for(int j=0; j<=i; j++) putchar(char('0'+mem[j]));
				for(int j=0; j<left4; j++) putchar('4');
				for(int j=0; j<left7; j++) putchar('7');
				flag=true;
				printf("\n");
				break;
			}
			else if(num==4){
				last=i; left4--;
				last_left7=left7-1;
				last_left4=left4;
				mem[i]=4;
			}
			else if(num<7){
				left7--;
				if(left7>=0){
					mem[i]=7;
					for(int j=0; j<=i; j++) putchar(char('0'+mem[j]));
					for(int j=0; j<left4; j++) putchar('4');
					for(int j=0; j<left7; j++) putchar('7');
					flag=true;
					putchar('\n');
					break;
				}
			}
			else if(num==7){
				left7--;
				mem[i]=7;
			}
			if((num>7 || left7<0 || left4<0) && last!=-1){
				for(int j=0; j<last; j++) putchar(char('0'+mem[j]));
				putchar('7');
				for(int j=0; j<last_left4; j++) putchar('4');
				for(int j=0; j<last_left7; j++) putchar('7');
				putchar('\n');
				flag=true;
				break;
			}
			else if((num>7 || left7<0 || left4<0) && last==-1) break;
		}
		if(flag==false && left7==0 && left4==0){
			for(int j=0; j<len; j++) putchar(char('0'+mem[j]));
			putchar('\n');
		}
		else if(flag==false){
			for(int i=0; i<(len>>1)+1; i++) putchar('4');
			for(int i=0; i<(len>>1)+1; i++) putchar('7');
			putchar('\n');
		}
	}

	return 0;
}
