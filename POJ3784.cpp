#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int p, no, n, num;
vector<int> arr;
void ins(int, int);

int main(){
	freopen("data.in", "r", stdin);
	scanf("%d", &p);
	for(int x=0; x<p; x++){
		scanf("%d %d", &no, &n);
		printf("%d %d\n", no, (n+1)/2);
		for(int i=1; i<=n; i++){
			scanf("%d", &num);
			ins(num, i);
			if(i&1) printf("%d ", arr[i/2]);
			if(i%20==0) printf("\n");
		}
		printf("\n");
	}

	return 0;
}

void ins(int x, int i){
	int l=0, r=i-1, mid;
	while(l<r){
		mid = (l+r)>>1;
		if(arr[mid] >= x) r=mid;
		else l=mid+1;
	}
	arr.insert(arr.begin()+l, x);
}
