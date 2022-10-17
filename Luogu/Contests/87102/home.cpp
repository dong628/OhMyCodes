#include <cstdio>
#include <iostream>
using std::min;

const int Maxn = 3e3+5;
int height[Maxn];

int main(){
//	freopen("data.in", "r", stdin);

	int n, h, res = 0, cur = 0, ans = 0, maxh = 0;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &h);
		height[h]++;
		maxh = maxh>h?maxh:h;
	}
	for(int i=0; i<=maxh; i++){
		cur = 0;
		for(int d=1; i-d>=0 && i+d<=maxh; d++){
			cur += min(height[i-d], height[i+d]);
		}
		if(cur > res){
			res = cur; ans = 0;
		}
		else if(cur == res){
			ans++;
		}
		cur = 0;
		for(int d=1; i-d+1>=0 && i+d<=maxh; d++){
			cur += min(height[i-d+1], height[i+d]);
		}
		if(cur > res){
			res = cur; ans = 0;
		}
		else if(cur == res){
			ans++;
		}
	}
	printf("%d %d", res, ans+1);

	return 0;
}
