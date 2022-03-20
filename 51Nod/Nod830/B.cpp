#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>

const int Maxc = 35, Maxn = 1e5+5;

struct Node{
	char s; int next;
}lian[Maxc];

int su[Maxc], tail = -1, head = 0, top = 1, calc, ans, len;
char str[Maxn];
bool ha[Maxn];
int front(char, char);
void append(char, char); 
void mmset(void);

int main(){
	freopen("data.in", "r", stdin);

	scanf("%s", str);
	len = strlen(str);
	lian[0].s = str[0]; lian[0].next = tail;
	for(int i=1; i<len; i++){
		if(ha[int(str[i])-int('a')]){
			ans++;
			memset(ha, 0, sizeof(ha));
		}
		else{
			calc = front(str[i-1], str[i]);
			if(calc == 1){
				ha[int(str[i])-int('a')] = true;
			}
			else if(calc == 0){
				ha[int(str[i])-int('a')] = true;
				append(str[i-1], str[i]);
			}
			else{
				memset(ha, 0, sizeof(ha));
				ans++;
			}
		}
	}
	printf("%d", ans);

	return 0;
}

int front(char a, char b){
	bool fa = false;
	for(int i=head; i!=tail; i=lian[i].next){
		if(lian[i].s==a){
			fa == true;
		}
		else if(lian[i].s==b){
			if(fa == true) return 1;
			else return -1;
		}
	}
	return 0;
}

void append(char a, char b){
	int temp;
	for(int i=head; i!=tail; i=lian[i].next){
		if(lian[i].s==a){
			lian[top].s = b;
			lian[top].next = lian[i].next;
			lian[i].next = top;
			top++;
			return;
		}
	}
}

