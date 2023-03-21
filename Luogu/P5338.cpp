#include <cstdio>
#include <iostream>

const int Maxn = 1e6+5;

struct Node{
	int ac, t, pri, size;
	Node *l, *r;
	bool operator> (const Node &b) const {
		if(ac == b.ac) return t < b.t;
		return ac > b.ac;
	}
	Node (int _ac, int _t){
		ac = _ac;
		t = _t;
	}
} treap[Maxn], leaf;
int cnt;

typedef unsigned int ui ;
ui randNum( ui& seed , ui last , const ui m){
	seed = seed * 17 + last ; return seed % m + 1;
}

Node *create(int ac, int t){
	treap[cnt].l = treap[cnt].r = &leaf;
	treap[cnt].ac = ac;
	treap[cnt].t = t;
	treap[cnt].size = 1;
	treap[cnt].pri = rand();
	cnt++;
	return &treap[cnt-1];
}

void update(Node *rt){
	rt -> size = rt -> l -> size + rt -> r -> size + 1;
}

void split(Node &*spl, Node &*spr, Node *rt, Node rnk){
	if(!(*rt > rnk)){ // rt <= rnk
		spl = rt;
		split(rt -> r, spr, rt -> r, rnk);
	}
	else{ // rt > rnk
		spr = rt;
		split(spl, rt -> l, rt -> l, rnk);
	}
	update(rt);
}

Node *merge(Node *mgl, Node *mgr){
	if(mgl -> pri < mgr -> pri){
		mgl -> r = merge(mgl -> r, mgr);
		update(mgl);
		return mgl;
	}
	else{
		mgr -> l = merge(mgl, mgr -> l);
		update(mgr);
		return mgr;
	}
}

int main(){
	freopen("data.in", "r", stdin);

	int t, last = 7, ria, rib, m, n, seed;
	scanf("%d", &t);

	while(t --> 0){
		scanf("%d %d %d", &m, &n, &seed);
		memset(treap, 0, sizeof(treap));
		cnt = 0;
		Node *root = merge(create(0, Inf), create(Inf, -Inf));
		for(int i=1; i<=n; i++){
			ria = randNum(seed, last, m);
			rib = randNum(seed, last, m);
			printf("%d\n", query(root, ria, rib));
		}
	}

	return 0;
}

int query(Node *root, int id, int t){
	Node *spl, *spr, *spm;
	split(spl, spr, root, Node())
}
