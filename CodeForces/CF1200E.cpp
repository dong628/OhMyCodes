#include <cstdio>
#include <iostream>
#include <cstring>
using std::string;

const int Maxn = 1e6+5;
char c[Maxn];
int n, pi[Maxn];
std::string s[Maxn], ans;
int kmp(string);

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%s", c);
		s[i] = c;
	}

	string tmp;
	int minn, j;
	ans = s[1];
	for(int i=2; i<=n; i++){
		minn = std::min(s[i].size(), ans.size());
		tmp = s[i].substr(0, minn) + "&*" + ans.substr(ans.size()-minn);
		j = kmp(tmp);
		for(int k=j; k<s[i].size(); k++){
			ans += s[i][k];
		}
	}

	printf("%s", ans.c_str());

	return 0;
}

int kmp(string a){
	int n = a.size();
	pi[0] = 0;
	for(int i=1; i<n; i++){
		int j = pi[i-1];
		while(j>0 && a[i]!=a[j]) j = pi[j-1];
		if(a[i] == a[j]) j++;
		pi[i] = j;
	}
	return pi[n-1];
}
