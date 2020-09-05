#include <cstdio>
#include <iostream>

const int Max=1000005, Inf=0x7fffffff;
int left[Max], right[Max], lmax[Max], lsum[Max], lenn=1, top=1;
void push(int), ret(), del(), lft(), rig(), insert();

int main(){
	freopen("data.in", "r", stdin);
	int n; char mode;
	scanf("%d\n", &n);
	for(int i=0; i<n; i++) lmax[i]=-Inf;
	for(int i=0; i<n; i++){
		scanf("%c", &mode);
		switch(mode){
			case 'I' : insert(); break;
			case 'Q' : ret(); break;
			case 'D' : del(); break;
			case 'L' : lft(); break;
			case 'R' : rig(); break;
		}
	}

	return 0;
}
void insert(void){
	int x; scanf("%d\n", &x);
	push(x);
}

void push(int x){
	left[top] = x;
	lsum[top] = lsum[top-1]+x;
	lmax[top] = lmax[top-1]>lsum[top]?lmax[top-1]:lsum[top];
	top++; lenn++;
}

void ret(void){
	int k; scanf("%d\n", &k);
	printf("%d\n", lmax[k]);
}

void del(void){
	getchar();
	if(top!=1){
		top--; lenn--;
	}
}

void lft(void){
	getchar();
	if(top!=1){
		right[lenn-top+1]=left[top-1];
		top--;
	}
}

void rig(void){
	getchar();
	if(top!=lenn){
		push(right[lenn-top]);
		lenn--;
	}
}
