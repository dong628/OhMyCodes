#include <cstdio>
#include <iostream>

const int Maxn = 2e5+5, Inf = 0x7fffffff;
struct Node{
	int pri, size;
	long long sum, val, tval;
	bool tflip;
	Node *ls, *rs;
} treap[Maxn*128], *root[Maxn], leaf;
int cnt;

Node *clone(Node *rt){
	treap[cnt] = *rt;
	cnt++;
	return &treap[cnt-1];
}

void split(Node *rt, int rk, Node *&spl, Node *&spr, bool fork){
	if(rt == &leaf){
		spl = spr = &leaf;
		return;
	}
	if(rt -> ls -> size <= rk - 1){
		if(fork) spl = clone(rt);
		else spl = rt;
		pushd(spl);
		split(rt -> rs, rk - (rt -> ls -> size) - 1, rt -> rs, spr, fork);
		update(spl);
	}
	else{
		if(fork) spr = clone(rt);
		else spr = rt;
		pushd(spr);
		split(rt -> ls, rk, spl, rt -> ls, fork);
		update(spr);
	}
}

Node *merge(Node *mgl, Node *mgr){
	if(mgl == &leaf) return mgr;
	if(mgr == &leaf) return mgl;
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


