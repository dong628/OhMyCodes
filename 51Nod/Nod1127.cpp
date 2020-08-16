#include <bits/stdc++.h>
using std::string;

int h[27], n;
string a;
bool search(int);
bool judge(void);

int main(){
//	freopen("data.in", "r", stdin);

	std::cin >> a;
	n=a.size();
	for(int i=0; i<n; i++){
		h[a[i]-'A']++;
	}
	for(int i=0; i<26; i++){
		if(h[i]==0){
			printf("No Solution");
			return 0;
		}
	}
	int l=26, r=n, mid;
	while(l<r){
		memset(h, 0, sizeof(h));
		mid=(l+r)>>1;
		if(search(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d", l);

	return 0;
}

bool search(int m){
	for(int i=0; i<m; i++) h[a[i]-'A']++;
	for(int i=m; i<=n; i++){
		if(judge()) return true;
		h[a[i]-'A']++;
		h[a[i-m]-'A']--;
	}
	return false;
}

bool judge(void){
	for(int i=0; i<26; i++) if(h[i]==0) return false;
	return true;
}
