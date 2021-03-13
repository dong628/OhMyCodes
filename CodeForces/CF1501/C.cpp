#include <cstdio>
#include <iostream>

struct Node{
	int index, value;
} a[Max];

int main(){
	scnaf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &num);
		a[i].index=i; a[i].value=num;
	}
	std::sort(a, a+n, cmp);
	for(int i=1; i<n; i++){
		tmp=a[i].value-a[i-1].value;
		if(b[tmp]==-1){
			b[tmp]=i;
		}
		else if(b[tmp]!=i-1){
			printf("%d %d %d %d", a[b[tmp]])
		}
	}

	return 0;
}
