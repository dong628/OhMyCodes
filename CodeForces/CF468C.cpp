#include <cstdio>
#include <iostream>
using namespace std;

unsigned long long a, ans;

int main(){
	cin >> a;
	ans = a-((((unsigned long long)(1e18)%a*9%a*9%a)+1)%a);
	cout << ans+1 << ' ' << ans+(unsigned long long)(1e18);

	return 0;
}
