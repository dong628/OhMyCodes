#include <cstdio>
#include <iostream>
#define rep(i,j,k) for(int i=j; i<=(k); i++)

int main(){
	scanf("%d %d", &n, &m);
	for(int i=1; i<=m; i++){
		scanf("%d %d %d", &v[i], &p[i], &q[i]);
	}
	for(int i=1; i<=m; i++){
		if(q[i]!=0){
			item[q[i]][cnt[q[i]]].v = v[i]+v[q[i]]
			item[q[i]][cnt[q[i]]].s = v[i]*p[i]+v[q[i]]*p[q[i]];
			cnt[q[i]]++;
		}
		else{
			item[i][cnt[i]].v = v[i]+v[q[i]]
			item[i][cnt[i]].s = v[i]*p[i];
			cnt[q[i]]++;
		}
	}

	return 0;
}
