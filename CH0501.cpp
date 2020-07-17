#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n, a[100005], b, c;

int main(){
	scanf("%d", &n);
	for(int i=0; i<n; i++) scanf("%d", a+i);
	sort(a, a+n);
	for(int i=0; i<n/2; i++) b+=a[i];
	if(n%2) for(int i=n/2+1; i<n; i++) c+=a[i];
	else for(int i=n/2; i<n; i++) c+=a[i];
	printf("%d", c-b);

	return 0;
}
