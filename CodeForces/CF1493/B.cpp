#include <cstdio>
#include <iostream>

int h, m;
bool flag;
int ref[] = {0, 1, 5, -1, -1, 2, -1, -1, 8, -1};
bool judge(int, int);
void opt(int, int);

int main(){
//	freopen("data.in", "r", stdin);

	int hh, mm, t;
	scanf("%d", &t);
	for(int x=0; x<t; x++){
		scanf("%d %d", &h, &m);
		scanf("%d:%d", &hh, &mm);
		flag=false;
		for(int min=mm; min<m; min++){
			if(judge(hh, min)){
				opt(hh, min);
				flag=true;
				break;
			}
		}
		for(int hour=hh+1; hour<h; hour++){
			if(flag==true) break;
			for(int min=0; min<m; min++){
				if(judge(hour, min)){
					opt(hour, min);
					flag=true;
					break;
				}
			}
		}
		if(flag==false) printf("00:00\n");
		/*
		for(int hour=0; hour<hh; hour++){
			if(flag=true) break;
			for(int min=0; min<m; min++){
				if(judge(hour, min)){
					opt(hour, min);
					flag=true;
					break;
				}
			}
		}
		for(int min=0; min<mm; min++){
			if(flag=true) break;
			if(judge(hh, min)){
				opt(hh, min);
				flag=true;
				break;
			}
		}
		*/
	}

	return 0;
}

bool judge(int hour, int min){
	int htm=0, mth=0;
	if(ref[hour/10]==-1 || ref[hour%10]==-1) return false;
	htm += ref[hour/10];
	htm += ref[hour%10]*10;
	if(ref[min/10]==-1 || ref[min%10]==-1) return false;
	mth += ref[min/10];
	mth += ref[min%10]*10;
	if(htm<m && mth<h) return true;
	else return false;
}

void opt(int hour, int min){
	if(hour<10) printf("0%d", hour);
	else printf("%d", hour);
	printf(":");
	if(min<10) printf("0%d", min);
	else printf("%d", min);
	printf("\n");
}
