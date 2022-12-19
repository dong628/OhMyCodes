#include <cstdio>
#include <iostream>

int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int calc(int, int);

int main(){

	int month, day, minn = 114, tmp;
	scanf("%d-%d", &month, &day);

	for(int i=1; i<=12; i++){
		for(int j=1; j<=days[i]; j++){
			tmp = calc(month, i)+calc(day, j);
			minn = minn<tmp?minn:tmp;
		}
	}
	printf("%d", minn);


	return 0;
}

int calc(int a, int b){
	int ans = 0;
	if(a/10 != b/10) ans++;
	if(a%10 != b%10) ans++;
	return ans;
}
