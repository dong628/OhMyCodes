#include <cstdio>
#include <iostream>
#include <map>

const int Maxn=1e6+5;
int maxx, t, n, l, a[Maxn];
std::map<int, int> m;

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d", &t);
	for(int cs=0; cs<t; cs++){
		scanf("%d", &n);
		maxx=0;
		l=1;
		m.clear();
		for(int i=1; i<=n; i++){
			scanf("%d", &a[i]);
			if(m[a[i]]==0){
				m[a[i]]++;
				maxx=maxx>i-l+1?maxx:i-l+1;
			}
			else{
				for( ; a[l-1]==a[i]; l++){
					m[a[l]]--;
				}
			}
		}
		printf("%d", maxx);
	}

	return 0;
}
