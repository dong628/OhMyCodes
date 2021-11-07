#include <cstdio>
#include <iostream>

const int Maxn=10005;
bool reg[Maxn];
int a[Maxn], size, msize, now=1, n;

int main(){
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
	}
	for(int i=1; i<=n; now<=n){
		if(a[i]!=now){
			if(reg[now]==true){
				reg[now] = false;
				size--;
				now++;
			} 
			else{
				size++;
				reg[a[i]] = true;
				msize = size>msize?size:msize;
				i++;
			}
		}
		else{
			i++;
			now++;
		}
	}
	printf("%d", msize);

	return 0;
}
