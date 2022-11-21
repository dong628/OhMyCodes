#include <cstdio>
#include <iostream>

const int Maxn = 2e5+5, Inf = 0x7fffffff;
struct Node{
	int val, pri, size;
	long long sum;
	bool tag;
	Node *ls, *rs;
} treap[Maxn*128], *root[Maxn], leaf;
int cnt;

Node *clone(Node *rt){
	treap[cnt] = *rt;
	cnt++;
	return &treap[cnt-1];
}

Node *create(int val){
	treap[cnt].val = val;
	treap[cnt].sum = val;
	treap[cnt].size = 1;
	treap[cnt].pri = rand();
	treap[cnt].ls = treap[cnt].rs = &leaf;
	cnt++;
	return &treap[cnt-1];
}

void update(Node *rt){
	rt -> size = rt -> ls -> size + rt -> rs -> size + 1;
	rt -> sum = rt -> ls -> sum + rt -> rs -> sum + rt -> val;
}

void pushd(Node *rt){
	if(rt -> tag){
		if(rt -> ls != &leaf) rt -> ls = clone(rt -> ls);
		if(rt -> rs != &leaf) rt -> rs = clone(rt -> rs);
		std::swap(rt -> ls, rt -> rs);
		rt -> ls -> tag ^= true;
		rt -> rs -> tag ^= true;
		rt -> tag = false;
	}
}

void split(Node *rt, int rk, Node *&spl, Node *&spr){
	if(rt == &leaf){
		spl = spr = &leaf;
		return;
	}
	pushd(rt);
	if(rt -> ls -> size <= rk - 1){
		spl = clone(rt);
		split(rt -> rs, rk - (rt -> ls -> size) - 1, spl -> rs, spr);
		update(spl);
	}
	else{
		spr = clone(rt);
		split(rt -> ls, rk, spl, spr -> ls);
		update(spr);
	}
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

void insert(int cur, int ver, int p, int x){
	Node *spl, *spr, *spm;
	split(root[ver], p+1, spl, spr);
	spm = create(x);
	spl = merge(spl, spm);
	root[cur] = merge(spl, spr);
}

void del(int cur, int ver, int p){
	Node *spl, *spr, *spm;
	split(root[ver], p, spl, spr);
	split(spr, 1, spm, spr);
	root[cur] = merge(spl, spr);
}

void flip(int cur, int ver, int l, int r){
	Node *spl, *spr, *spm;
	split(root[ver], l, spl, spr);
	split(spr, r-l+1, spm, spr);
	spm -> tag ^= true;
	spl = merge(spl, spm);
	root[cur] = merge(spl, spr);
}

long long get(int cur, int ver, int l, int r){
	Node *spl, *spr, *spm;
	split(root[ver], l, spl, spr);
	split(spr, r-l+1, spm, spr);
	long long ans = spm -> sum;
	spl = merge(spl, spm);
	root[cur] = merge(spl, spr);
	return ans;
}

int main(){
	freopen("data.in", "r", stdin);

	int n, v, opt, p, x, l, r;
	long long lastans = 0;

	scanf("%d", &n);
	
	root[0] = merge(create(-Inf), create(Inf));
	for(int i=1; i<=n; i++){
//		lastans = 0;
		scanf("%d %d", &v, &opt);
		if(opt == 1){
			scanf("%d %d", &p, &x);
			p ^= lastans; x ^= lastans;
			insert(i, v, p, x);
		}
		else if(opt == 2){
			scanf("%d", &p);
			p ^= lastans;
			del(i, v, p);
		}
		else if(opt == 3){
			scanf("%d %d", &l, &r);
			l ^= lastans; r ^= lastans;
			flip(i, v, l, r);
		}
		else{
			scanf("%d %d", &l, &r);
			l ^= lastans; r ^= lastans;
			lastans = get(i, v, l, r);
			printf("%lld\n", lastans);
		}
	}

	return 0;
}
