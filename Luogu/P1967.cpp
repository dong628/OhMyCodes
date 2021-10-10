#include <cstdio>
#include <iostream>

struct Road{
	int x, y, z;
}temp;
bool operator <(const Road &a, const Road &b){
	return a.z<b.z;
}
priority_queue < Road > mapp;
vector<int> tree[Maxn];

void kruskal(void);

int main(){
	scanf("%d %d", &n, &m);
	for(int i=0; i<=m; i++){
		scanf("%d %d %d", &x, &y, &z);
		temp.x = x; temp.y = y; temp.z = z;
		mapp.push_back(temp);
	}
	kruskal();

	return 0;
}

void kruskal(void){
	for(int i=1; i<=m; i++){
		temp = mapp.top();
		if(!query(temp.x, temp.y)){
			merge(temp.x, temp.y);
			tree[x].push_back()
		}
	}
}
