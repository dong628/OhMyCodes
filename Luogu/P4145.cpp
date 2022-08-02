#include <cstdio>
#include <iostream>
#include <cmath>
using std::swap;

const int Maxn = 1e5+5, Maxsq = 1e3+5;
typedef long long lol;
int block, num, n, start[Maxsq], end[Maxsq], tag[Maxsq];
lol a[Maxn], sqs[10][Maxn], sum[10][Maxsq];
void work(int, int);
lol query(int, int);

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%lld", &a[i]);
	}

	block = sqrt(n); num = n/block;
	for(int i=0; i<num; i++){
		start[i] = i*block;
		end[i] = (i+1)*block;
		for(int j=start[i]; j<end[i]; j++){
			sqs[0][j] = a[j];
			sum[0][i] += sqs[0][j];
		}
		for(int k=1; k<=7; k++){
			for(int j=start[i]; j<end[i]; j++){
				sqs[k][j] = sqrt(sqs[k-1][j]);
				sum[k][i] += sqs[k][j];
			}
		}
	}
	if(n%block != 0){
		start[num] = num*block;
		end[num] = n;
		for(int j=start[num]; j<end[num]; j++){
			sqs[0][j] = a[j];
			sum[0][num] += sqs[0][j];
		}
		for(int k=1; k<=7; k++){
			for(int j=start[num]; j<end[num]; j++){
				sqs[k][j] = sqrt(sqs[k-1][j]);
				sum[k][num] += sqs[k][j];
			}
		}
	}

	int m, k, l, r;
	scanf("%d", &m);
	while(m--){
		scanf("%d %d %d", &k, &l, &r);
		if(l > r) swap(l, r);
		if(k == 0) work(l-1, r-1);
		else printf("%lld\n", query(l-1, r-1));
	}

	return 0;
}

void work(int l, int r){
	int lb = l/block, rb = r/block;
	if(lb != rb){
		for(int i=l; i==l||i%block!=0; i++){
			sqs[0][i] = sqrt(sqs[0][i]);
			sum[0][lb] -= a[i];
			sum[0][lb] += sqs[0][i];
			a[i] = sqrt(a[i]);
			for(int k=1; k<=7; k++){
				sqs[k][i] = sqrt(sqs[k][i]);
				sum[k][lb] -= sqs[k-1][i];
				sum[k][lb] += sqs[k][i];
			}
		}
		for(int i=r; i==r||i%block!=block-1; i--){
			sqs[0][i] = sqrt(sqs[0][i]);
			sum[0][rb] -= a[i];
			sum[0][rb] += sqs[0][i];
			a[i] = sqrt(a[i]);
			for(int k=1; k<=7; k++){
				sqs[k][i] = sqrt(sqs[k][i]);
				sum[k][rb] -= sqs[k-1][i];
				sum[k][rb] += sqs[k][i];
			}
		}
		for(int i=lb+1; i<rb; i++){
			tag[i]++;
			tag[i] = tag[i]>7?7:tag[i];
		}
	}
	else{
		for(int i=l; i<=r; i++){
			sqs[0][i] = sqrt(sqs[0][i]);
			sum[0][lb] -= a[i];
			sum[0][lb] += sqs[0][i];
			a[i] = sqrt(a[i]);
			for(int k=1; k<=7; k++){
				sqs[k][i] = sqrt(sqs[k][i]);
				sum[k][lb] -= sqs[k-1][i];
				sum[k][lb] += sqs[k][i];
			}
		}
	}
}

lol query(int l, int r){
	int lb = l/block, rb = r/block;
	lol summ = 0;
	if(lb != rb){
		for(int i=l; i==l||i%block!=0; i++){
			summ += sqs[tag[lb]][i];
		}
		for(int i=r; i==r||i%block!=block-1; i--){
			summ += sqs[tag[rb]][i];
		}
		for(int i=lb+1; i<rb; i++){
			summ += sum[tag[i]][i];
		}
	}
	else{
		for(int i=l; i<=r; i++){
			summ += sqs[tag[lb]][i];
		}
	}
	return summ;
}
