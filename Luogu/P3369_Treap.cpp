#include <cstdio>
#include <iostream>

struct Node{
	Node *ls, *rs;
	int pri, val, size;
} treap[Maxn];
const Node *leaf;


int main(){
	

	return 0;
}

void split(Node *rt, int val, Node &*spl, node &*spr){
	if(rt == leaf) { spl = spr = leaf; return; }
	if(rt -> val <= val){
		spl = rt;
		split(rt -> rs, val, rt -> rs, spr);
	}
	else{
		spr = rt;
		split(rt -> ls, val, spl, rt -> ls);
	}
	update(rt);
}

Node *merge(Node *mgl, Node *mgr){
	if(mgl == leaf) return mgr;
	if(mgr == leaf) return mgl;
	if(mgl -> pri > mgr -> pri){
		mgl -> rs = merge(mgl -> rs, mgr);
		update(mgl);
		return mgl;
	}
	else{
		mgr -> ls = merge(mgl, mgr -> ls);
		update(mgr);
		return mgr;
	}
}

void update(Node *rt){
	rt -> size = rt -> ls -> size + rt -> rs -> size + 1;
}

Node *create(int val){
	treap[cnt].val = val;
	treap[cnt].pri = rand();
	treap[cnt].size = 1;
	treap[cnt].ls = treap[cnt].rs = leaf;
	cnt++;
	return &treap[cnt-1];
}

void insert(Edge &*rt, int val){
	Edge *ptl, *ptr, *ptn;
	split(rt, val, ptl, ptr);
	ptn = create(val);
	ptl = merge(ptl, ptn);
	rt = merge(ptl, ptr);
}

void del(Edge &*rt, int val){
	Edge *ptl, *ptr, *ptv;
	split(rt, val, ptl, ptr);
	split(ptl, val-1, ptl, ptv);
	ptv = merge(ptv.ls, ptv.rs);
	rt = merge(merge(ptl, ptv), ptr);
}

int rank(Edge &*rt, int x){
	Edge *ptl, *ptr;
	split(rt, x-1, ptl, ptr);
	int ans = ptl -> size + 1;
	rt = merge(ptl, ptr);
	return ans;
}

Edge *kth(Edge *rt, int k){
	if(rt -> ls -> size == k - 1)
		return rt;
	if(rt -> ls -> size > k - 1)
		return kth(rt -> ls, k);
	if(rt -> ls -> size < k - 1)
		return kth(rt -> rs, k - rt -> ls -> size - 1);
}

int pre()
