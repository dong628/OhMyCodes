#include <cstdio>
#include <iostream>

//const int Maxn = 1e3+5, Inf = 0x7fffffff;
const int Maxn = 5e4+5, Inf = 0x7fffffff;

struct Node{
	int val, pri, size, taga, maxx;
	bool tagf;
	Node *ls, *rs;
} treap[Maxn], leaf, *root;
int cnt;

void update(Node *rt){
	leaf.maxx = -Inf; leaf.val = 0;
	rt -> size = rt -> ls -> size + rt -> rs -> size + 1;
	rt -> maxx = std::max(rt -> val, (std::max(rt -> ls -> maxx, rt -> rs -> maxx)));
}

void pushd(Node *rt){
	leaf.maxx = -Inf; leaf.val = 0;
	if(rt -> taga != 0){
		rt -> ls -> taga += rt -> taga;
		rt -> rs -> taga += rt -> taga;
		rt -> ls -> val += rt -> taga;
		rt -> rs -> val += rt -> taga;
		rt -> ls -> maxx += rt -> taga;
		rt -> rs -> maxx += rt -> taga;
		rt -> taga = 0;
//		update(rt);
	}
	if(rt -> tagf){
		std::swap(rt -> ls, rt -> rs);
		rt -> ls -> tagf ^= true;
		rt -> rs -> tagf ^= true;
		rt -> tagf = false;
	}
}

void split(Node *rt, int rk, Node *&spl, Node *&spr){
	if(rt == &leaf){
		spl = spr = &leaf;
		return;
	}
	pushd(rt);
	if(rt -> ls -> size <= rk - 1){
		spl = rt;
		split(rt -> rs, rk - ( rt -> ls -> size ) - 1, rt -> rs, spr);
//		update(spl);
	}
	else{
		spr = rt;
		split(rt -> ls, rk, spl, rt -> ls);
//		update(spr);
	}
	update(rt);
}

Node *merge(Node *mgl, Node *mgr){
	if(mgl == &leaf) return mgr;
	if(mgr == &leaf) return mgl;
	if(mgl -> pri > mgr -> pri){
		pushd(mgl);
		mgl -> rs = merge(mgl -> rs, mgr);
		update(mgl);
		return mgl;
	}
	else{
		pushd(mgr);
		mgr -> ls = merge(mgl, mgr -> ls);
		update(mgr);
		return mgr;
	}
}

void add(int l, int r, int v){
	Node *spl, *spr, *spm;
	split(root, l-1, spl, spr);
	split(spr, r-l+1, spm, spr);
	spm -> taga += v;
	spm -> val += v;
	spm -> maxx += v;
	spr = merge(spm, spr);
	root = merge(spl, spr);
}

void flip(int l, int r){
	Node *spl, *spr, *spm;
	split(root, l-1, spl, spr);
	split(spr, r-l+1, spm, spr);
	spm -> tagf ^= 1;
	spr = merge(spm, spr);
	root = merge(spl, spr);
}

int get(int l, int r){
	Node *spl, *spr, *spm;
	split(root, l-1, spl, spr);
	split(spr, r-l+1, spm, spr);

//	update(spm);
	int ans = spm -> maxx;

	spr = merge(spm, spr);
	root = merge(spl, spr);
	return ans;
}

Node *create(int val){
	treap[cnt].val = val;
	treap[cnt].maxx = val;
	treap[cnt].size = 1;
	treap[cnt].pri = rand();
	treap[cnt].ls = treap[cnt].rs = &leaf;
	cnt++;
	return &treap[cnt-1];
}

void output(Node *rt){
	if(rt == &leaf) return;
	pushd(rt);
	output(rt -> ls);
	if(rt -> val != Inf && rt -> val != -Inf)
		printf("%d ", rt -> val);
	output(rt -> rs);
}

int main(){
	freopen("data.in", "r", stdin);
	
	int n, m, opt, l, r, v;
	scanf("%d %d", &n, &m);

	root = create(-Inf);
	for(int i=0; i<n; i++){
		root = merge(root, create(0));
	}
	root = merge(root, create(Inf));
	
	for(int i=0; i<m; i++){
		scanf("%d", &opt);
		if(opt == 1){
			scanf("%d %d %d", &l, &r, &v);
			add(l+1, r+1, v);
		}
		else if(opt == 2){
			scanf("%d %d", &l, &r);
			flip(l+1, r+1);
		}
		else{
			scanf("%d %d", &l, &r);
			printf("%d\n", get(l+1, r+1));
		}
//		output(root);
//		putchar('\n');
	}

	return 0;
}
