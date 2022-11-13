#include <cstdio>
#include <iostream>
using std::make_pair, std::min, std::max;

typedef std::pair<int, int> pii;
pii stair(int, int);
pii cube(int, int, int, int);

int main(){
	int t, n;
	pii ans;

	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		ans = stair(1, n);
		printf("! %d %d\n", min(ans.first, ans.second), max(ans.first, ans.second));
		fflush(stdout);
	}

	return 0;
}

pii stair(int l, int r){
	int ret;
	pii p1, p2;
	if(r-l == 0){
		return make_pair(-1, -1);
	}
	if(r-l == 1){
		printf("? %d", l);
		for(int i=1; i<=l; i++){
			printf(" %d", i);
		}
		printf("\n");
		fflush(stdout);
		scanf("%d", &ret);
		if(ret == 0) return make_pair(-1, -1);
		else return make_pair(l, r);
	}
	else{
		printf("? %d", (r+l)>>1);
		for(int i=1; i<=(r+l)>>1; i++){
			printf(" %d", i);
		}
		printf("\n");
		fflush(stdout);
		scanf("%d", &ret);
		if(ret == 0){
			p1 = stair(l, (r+l)>>1);
			p2 = stair(((r+l)>>1)+1, r);
			if(p1.first == -1){
				if(p2.first == -1){
					return p1;
				}
				else{
					return p2;
				}
			}
			else{
				return p1;
			}
		}
		else{
			return cube(l, (r+l)>>1, ((r+l)>>1)+1, r);
		}
	}
}

pii cube(int l1, int r1, int l2, int r2){
	int len1 = r1-l1+1, len2 = r2-l2+1, ret;
	if(len1 == 1 && len2 == 1){
		return make_pair(l1, l2);
	}
	else if(len1 > len2){
		printf("? %d", (l1+r1)>>1);
		for(int i=1; i<=(l1+r1)>>1; i++){
			printf(" %d", i);
		}
		printf("\n");
		fflush(stdout);
		scanf("%d", &ret);
		if(ret == 1){
			return cube(l1, (l1+r1)>>1, l2, r2);
		}
		else{
			return cube(((l1+r1)>>1)+1, r1, l2, r2);
		}
	}
	else{
		printf("? %d", (l2+r2)>>1);
		for(int i=1; i<=(l2+r2)>>1; i++){
			printf(" %d", i);
		}
		printf("\n");
		fflush(stdout);
		scanf("%d", &ret);
		if(ret == 1){
			return cube(l1, r1, ((l2+r2)>>1)+1, r2);
		}
		else{
			return cube(l1, r1, l2, (l2+r2)>>1);
		}
	}
}
