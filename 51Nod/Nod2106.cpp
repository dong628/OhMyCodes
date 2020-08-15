#include <iostream>
#include <cstdio>
#include <algorithm>

const int Max=100005;
int a[Max], n;

int main(){
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	std::sort(a, a+n);
	int cnt=0, nc=0;
	for(int i=0; i<n; i++){
		if(a[i]!=nc){
			if(cnt%2){
				printf("%d", nc);
				return 0;
			}
			else { nc=a[i]; cnt=1; }
		}
		else cnt++;
	}
	printf("%d", nc);
	
	return 0;
}
