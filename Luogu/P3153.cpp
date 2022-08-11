#include <cstdio>
#include <iostream>

struct Node{
	int val, cur, to;
	Node* fx;
} mapp[Maxn][Maxn], e, ne;
struct Man{
	int mst, yes, no;
} boy[Maxn], girl[Maxn];

int main(){
	input();

	return 0;
}

void input(void){
	scanf("%d %d\n", &n, &k);
	cntp = 1; s = 0; t = 6*n+1;
	for(int i=1; i<=n; i++){
		boy[i].mst = cntp++;
		boy[i].yes = cntp++;
		boy[i].no = cntp++;
		e.val = 0; e.to = boy[i].mst; e.fx = &mapp[e.to][cnt[e.to]]; e.cur = 0;
		ne.val = 0; ne.to = s; ne.fx = &mapp[ne.to][cnt[ne.to]]; ne.cur = 0;
		mapp[s][cnt[s]++] = e;
		mapp[boy[i].mst][cnt[boy[i].mst]++] = ne;
		e.val = k; e.to = boy[i].no; e.fx = &mapp[e.to][cnt[e.to]]; e.cur = 0;
		ne.val = k; ne.to = boy[i].mst; ne.fx = &mapp[ne.to][cnt[ne.to]]; ne.cur = k;
		mapp[boy[i].mst][cnt[boy[i].mst]++] = e;
		mapp[boy[i].no][cnt[boy[i].no]++] = ne;
		e.val = Inf; e.to = boy[i].yes; e.fx = &mapp[e.to][cnt[e.to]]; e.cur = 0;
		ne.val = Inf; ne.to = boy[i].mst; ne.fx = &mapp[ne.to][cnt[ne.to]]; ne.cur = k;
		mapp[boy[i].mst][cnt[boy[i].mst]++] = e;
		mapp[boy[i].yes][cnt[boy[i].yes]++] = ne;
	}
	for(int i=n+1; i<=2*n; i++){
		girl[i].mst = cntp++;
		girl[i].yes = cntp++;
		girl[i].no = cntp++;
		e.val = 0; e.to = girl[i].mst; e.fx = &mapp[e.to][cnt[e.to]]; e.cur = 0;
		ne.val = 0; ne.to = t; ne.fx = &mapp[ne.to][cnt[ne.to]]; ne.cur = 0;
		mapp[t][cnt[t]++] = e;
		mapp[girl[i].mst][cnt[girl[i].mst]++] = ne;
		e.val = k; e.to = girl[i].no; e.fx = &mapp[e.to][cnt[e.to]]; e.cur = k;
		ne.val = k; ne.to = girl[i].mst; ne.fx = &mapp[ne.to][cnt[ne.to]]; ne.cur = 0;
		mapp[girl[i].mst][cnt[girl[i].mst]++] = e;
		mapp[girl[i].no][cnt[girl[i].no]++] = ne;
		e.val = Inf; e.to = girl[i].yes; e.fx = &mapp[e.to][cnt[e.to]]; e.cur = k;
		ne.val = Inf; ne.to = girl[i].mst; ne.fx = &mapp[ne.to][cnt[ne.to]]; ne.cur = 0;
		mapp[girl[i].mst][cnt[girl[i].mst]++] = e;
		mapp[girl[i].yes][cnt[girl[i].yes]++] = ne;
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			scanf("%c", &ch);
			if(ch=='Y'){
				e.val = 1; e.to = girl[j].yes;
				e.fx = &mapp[e.to][cnt[e.to]]; e.cur = 0;
				ne.val = 1; ne.to = boy[i].yes;
				ne.fx = &mapp[ne.to][cnt[ne.to]]; ne.cur = 1;
				mapp[boy[i].yes][cnt[boy[i].yes]++] = e;
				mapp[girl[j].yes][cnt[girl[j].yes]++] = ne;
			}
			else{
				e.val = 1; e.to = girl[j].no;
				e.fx = &mapp[e.to][cnt[e.to]]; e.cur = 0;
				ne.val = 1; ne.to = boy[i].no;
				ne.fx = &mapp[ne.to][cnt[ne.to]]; ne.cur = 1;
				mapp[boy[i].no][cnt[boy[i].no]++] = e;
				mapp[girl[j].no][cnt[girl[j].no]++] = ne;
			}
		}
		getchar();
	}
}


