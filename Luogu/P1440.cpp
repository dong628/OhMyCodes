#include <cstdio>
#include <iostream>

const int Maxn=2e6+5;
int q[Maxn], a[Maxn], maxx[Maxn], minn[Maxn], n, k, front, rear;

int main(){
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);

	scanf("%d %d", &n, &k);
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	front=0; rear=0;
	for(int i=0; i<n; i++){
		while(rear>front && a[q[rear-1]]>=a[i]){
			rear--;
		}
		q[rear++]=i;
		while(q[rear-1]-q[front]>=k){
			front++;
		}
		minn[i]=a[q[front]];

	}
/*
	for(int i=0; i<n; i++){
		if(a[i]>a[q[rear-1]] && rear-front<k){
			q[rear++]=i;
		}
		else if(a[i]<=a[q[rear-1]]){
			q[rear++]=i;
			front=rear-1;
		}
		else{
			q[rear++]=i;
			front++;
		}
		if(i>=k-1){
			minn[i-k+1]=a[q[front]];
		}
	}
*/
	printf("0\n");

	for(int i=0; i<n-1; i++){
		printf("%d\n", minn[i]);
	}

	return 0;
}
