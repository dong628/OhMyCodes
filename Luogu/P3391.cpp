#include <cstdio>
#include <iostream>
using std::swap;

const int Maxn = 1e5+5;
struct Node{
	int val, pri, size;
	bool lazy;
	Node *ls, *rs;
} treap[Maxn], leaf;
int cnt;

void split(Node *rt, int rk, Node *&spl, Node *&spr);
void flip(Node *&rt, int l, int r);
Node *merge(Node *mgl, Node *mgr);
void pushd(Node *&rt);
void update(Node *&rt);
void create(Node *&rt, int val);
void output(Node *&rt);

int main(){
	freopen("data.in", "r", stdin);

	Node *root;
	int n, m, l, r;
	scanf("%d %d", &n, &m);
	if(n == 1){
		printf("1");
		return 0;
	}
	treap[0].ls = &leaf; treap[0].rs = &leaf; treap[0].size = 1;
	treap[0].val = 1; treap[0].pri = rand(); cnt++;
	treap[1].ls = &leaf; treap[1].rs = &leaf; treap[0].size = 1;
	treap[1].val = n; treap[1].pri = rand(); cnt++;
	root = merge(&treap[0], &treap[1]);

	for(int i=2; i<n; i++){
//		output(root);
//		printf("\n");
		create(root, i);
	}

	for(int i=0; i<m; i++){
		scanf("%d %d", &l, &r);
		flip(root, l, r);
//		output(root);
//		printf("\n");
	}
	
	output(root);

	return 0;
}

void output(Node *&rt){
	if(rt == &leaf) return;
	pushd(rt);
	output(rt -> ls);
	printf("%d ", rt -> val);
	output(rt -> rs);
}

void create(Node *&rt, int val){
	Node *lsp, *rsp;
	split(rt, val-1, lsp, rsp);
	treap[cnt].val = val; treap[cnt].pri = rand();
	treap[cnt].ls = treap[cnt].rs = &leaf; treap[cnt].size = 1;
	lsp = merge(lsp, &treap[cnt]);
	rt = merge(lsp, rsp);
	cnt++;
}

void split(Node *rt, int rk, Node *&spl, Node *&spr){
	if(rt == &leaf){
		spl = spr = &leaf;
		return;
	}
	pushd(rt);
	if(rt -> ls -> size <= rk - 1){
		spl = rt;
		split(rt -> rs, rk-(rt->ls->size)-1, rt -> rs, spr);
	}
	else{
		spr = rt;
		split(rt -> ls, rk, spl, rt -> ls);
	}
	update(rt);
}

Node *merge(Node *mgl, Node *mgr){
	if(mgl == &leaf) return mgr;
	if(mgr == &leaf) return mgl;
	if(mgl -> pri < mgr -> pri){
		pushd(mgr);
		mgr -> ls = merge(mgl, mgr -> ls);
		update(mgr);
		return mgr;
	}
	else{
		pushd(mgl);
		mgl -> rs = merge(mgl -> rs, mgr);
		update(mgl);
		return mgl;
	}
}

void pushd(Node *&rt){
	if(rt -> lazy){
		swap(rt -> ls, rt -> rs);
		rt -> ls -> lazy ^= true;
		rt -> rs -> lazy ^= true;
		rt -> lazy = 0;
	}
}

void update(Node *&rt){
	rt -> size = rt -> ls -> size + rt -> rs -> size + 1;
}

void flip(Node *&rt, int l, int r){
	Node *spl, *spr, *spmid;
	split(rt, l-1, spl, spr);
	split(spr, r-l+1, spmid, spr);
	spmid -> lazy ^= true;
	spl = merge(spl, spmid);
	rt = merge(spl, spr);
}
