#include <cstdio>
#include <iostream>
#include <cstring>

const int Max=3e5+5;
char s[Max];
bool flag;
int t, length;
void print(int);

int main(){
//	freopen("data.in", "r", stdin);

	scanf("%d", &t);
	for(int cnum=0; cnum<t; cnum++){
		scanf("%s", s);
		flag=false;
		length=strlen(s);
		for(int i=0, j=length-1; i<j; i++, j--){
			if(s[i]!='a' && s[j]!='a'){
				printf("YES\n");
				print(i);
				flag=true;
				break;
			}
			else if(s[j]!='a'){
				printf("YES\n");
				print(i);
				flag=true;
				break;
			}
			else if(s[i]!='a'){
				printf("YES\n");
				print(j+1);
				flag=true;
				break;
			}
		}
		if(!flag){
			printf("NO\n");
		}
	}

	return 0;
}

void print(int x){
	for(int i=0; i<x; i++){
		printf("%c", s[i]);
	}
	printf("a");
	for(int i=x; i<strlen(s); i++){
		printf("%c", s[i]);
	}
	printf("\n");
}
