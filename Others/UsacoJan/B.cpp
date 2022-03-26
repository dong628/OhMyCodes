#include <cstdio>
#include <iostream>
#include <algorithm>

const int Maxn = 10;
int t, a[Maxn], b[Maxn], c[Maxn], tot[Maxn], m, ark, brk, maxx;
bool flag;
bool judge();

int main(){
//	freopen("data.in", "r", stdin);
	
	scanf("%d", &t);
	for(int cst=0; cst<t; cst++){
		for(int i=0; i<4; i++){
			scanf("%d", &a[i]);
			tot[i] = a[i];
		}
		for(int i=0; i<4; i++){
			scanf("%d", &b[i]);
			tot[i+4] = b[i];
		}
		std::sort(tot, tot+8);
		m = std::unique(tot, tot+8)-tot;
		maxx = 0;
		for(int i=0; i<4; i++){
//			a[i] = (std::lower_bound(tot, tot+m, a[i])-tot+1)*2;
			maxx = maxx>a[i]?maxx:a[i];
//			printf("%d ", a[i]);
		}
		std::sort(a, a+4);
//		printf("\n");
		for(int i=0; i<4; i++){
//			b[i] = (std::lower_bound(tot, tot+m, b[i])-tot+1)*2;
			maxx = maxx>b[i]?maxx:b[i];
//			printf("%d ", b[i]);
		}
		std::sort(b, b+4);
//		printf("\n");
//		printf("\n");
		ark = 0; brk = 0;
		for(int i=0; i<4; i++){
			for(int j=0; j<4; j++){
				if(a[i]>b[j]) ark++;
				if(a[i]<b[j]) brk++;
			}
		}
		if(ark == brk){
			printf("no\n");
			continue;
		}
		flag = false;
		for(int x=1; x<=10; x++){
			c[0] = x;
			for(int y=1; y<=10; y++){
				c[1] = y;
				for(int z=1; z<=10; z++){
					c[2] = z;
					for(int k=1; k<=10; k++){
						c[3] = k;
						if(judge()){
							flag = true;
							break;
						}
					}
					if(flag) break;
				}
				if(flag) break;
			}	
			if(flag) break;
		}
		if(flag) printf("yes\n");
		else printf("no\n");
	}


	return 0;
}

bool judge(){
	int arkk=0, brkk=0, crk1=0, crk2=0;
	if(ark>brk){
		for(int i=0; i<4; i++){
			for(int j=0; j<4; j++){
				if(a[i]>c[j]) arkk++;
				if(a[i]<c[j]) crk1++;
			}
		}
		for(int i=0; i<4; i++){
			for(int j=0; j<4; j++){
				if(b[i]>c[j]) brkk++;
				if(b[i]<c[j]) crk2++;
			}
		}
		if(arkk<crk1 && brkk>crk2) return true;
		else return false;
	}
	else{
		for(int i=0; i<4; i++){
			for(int j=0; j<4; j++){
				if(a[i]>c[j]) arkk++;
				if(a[i]<c[j]) crk1++;
			}
		}
		for(int i=0; i<4; i++){
			for(int j=0; j<4; j++){
				if(b[i]>c[j]) brkk++;
				if(b[i]<c[j]) crk2++;
			}
		}
		if(arkk>crk1 && brkk<crk2) return true;
		else return false;
	}
}
