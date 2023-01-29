#include <cstdio>
#include <iostream>

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
	}
	scanf("%d", &m);
	for(int i=1; i<=m; i++){
		scanf("%d", t[i]);
		if(t[i] == 1){
			scanf("%d %d", &p[i], &v[i]);
		}
		else if(t[i] == 2){
			scanf("%d", &v[i]);
		}
		else{
			scanf("%d", &a[i]);
			for(int j=1; j<=a[i]; j++){
				scanf("%d", &tmp);
				g[i].push_back(tmp);
				in[tmp]++;
			}
		}
	}
	scanf("%d", &q);
	for(int i=1; i<q; i++){
		scanf("%d", &tmp);
		g[0].push_back(tmp);
	}

	upxv = tp1(0);
	for(int i=1; i<=m; i++) mul[i] = 1;
	for(int i=upxv.size()-1; i>=0; i--){
		for(int j=1; j<=a[i]; j++){
			mul[upxv[i]] *= mul[g[upxv[i]][j]];
		}
	}



	return 0;
}

std::vector <int> tp1(int s){
	std::vector <int> nxt;
	int cur = 0, tar;
	nxt.push_back(s);
	for( ; ; ){
		tar = nxt[cur];
		in[tar]--;
		if(in[tar] == 0){
			nxt.push_back(tar);
		}
		cur++;
		if(cur >= nxt.size()) break;
	}
	return nxt;
}
