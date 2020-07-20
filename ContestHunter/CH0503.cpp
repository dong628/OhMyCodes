#include <cstdio>
#include <iostream>

const int MAX=250005;
int n, num, l;
long long ans, ans1;
int start[MAX], end[MAX], temp[MAX];
void MergeSort(int*, int);

int main(){
	freopen("data.in", "r", stdin);

	while(scanf("%d", &n) != EOF){
		if(n==1){
			printf("TAK\n");
			scanf("%d%d", &num, &num);
			continue;
		}
		l=0;
		for(int i=0; i<n*n; i++){
			scanf("%d", &num);
			if(num != 0){
				start[l++]=num;
			}
		}
		l=0;
		for(int i=0; i<n*n; i++){
			scanf("%d", &num);
			if(num != 0){
				end[l++]=num;
			}
		}
		MergeSort(start, l);
		ans1=ans; ans=0;
		MergeSort(end, l);
		if((ans1&1) == (ans&1)) printf("TAK\n");
		else printf("NIE\n");
	}

	return 0;
}

void MergeSort(int *arr, int len){
	if(len==1) return;

	int rl=len/2; int *rs=arr;
	int ll=len-rl; int *ls=arr+len/2;
	MergeSort(rs, rl);
	MergeSort(ls, ll);

	int i=0, j=0, tl=0; ans=0;
	while(i<ll && j<rl){
		if(ls[i]>rs[j]){
			temp[tl++]=rs[j++];
			ans += ll-i;
		}
		else temp[tl++]=ls[i++];
	}
	while(i<ll) temp[tl++]=ls[i++];
	while(j<rl) temp[tl++]=rs[j++];

	for(int x=0; x<tl; x++){
		arr[x]=temp[x];
	}
}
