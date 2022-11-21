#include <cstdio>
#include <iostream>

const int Maxn = 5e5+5, Inf = 0x7fffffff;
struct Node{
	Node *ls, *rs;
	int pri, val, size;
} treap[Maxn*128], leaf, *root[Maxn];
int cnt;

void split(Node *, int, Node *&, Node *&);
void insert(int, int, int), del(int, int, int), update(Node *);
int rank(int, int, int), kth(Node *, int), pre(int, int, int), nxt(int, int, int);
Node *merge(Node*, Node*), *create(int), *init(void), *clone(Node *);

int main(){
	freopen("data.in", "r", stdin);
	
	srand(114514);
	int t, opt, x, ver;
	leaf.size = 0; leaf.val = 0; leaf.ls = &leaf; leaf.rs = &leaf;
	root[0] = merge(create(-Inf), create(Inf));
	scanf("%d", &t);

	for(int i=1; i<=t; i++){
		scanf("%d %d %d", &ver, &opt, &x);
		switch(opt){
			case 1: insert(i, ver, x);			break;
			case 2: del(i, ver, x);				break;
			case 3: printf("%d\n", rank(i, ver, x)-1);	break;
			case 4: root[i] = root[ver]; printf("%d\n", kth(root[ver], x+1));	break;
			case 5: printf("%d\n", pre(i, ver, x));		break;
			case 6: printf("%d\n", nxt(i, ver, x));		break;
		}
	}

	return 0;
}

Node *init(void){
	Node *rt = create(int(-Inf));
	rt -> rs = create(int(Inf));
	update(rt);
	return rt;
}

Node *clone(Node *rt){
	treap[cnt++] = *rt;
	return &treap[cnt-1];
}

void split(Node *rt, int val, Node *&spl, Node *&spr){
	if(rt == &leaf) { spl = spr = &leaf; return; }
	if(rt -> val <= val){
		spl = clone(rt);
		split(rt -> rs, val, spl -> rs, spr);
		update(spl);
	}
	else{
		spr = clone(rt);
		split(rt -> ls, val, spl, spr -> ls);
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

void update(Node *rt){
	rt -> size = rt -> ls -> size + rt -> rs -> size + 1;
}

Node *create(int val){
	treap[cnt].val = val;
	treap[cnt].pri = rand();
	treap[cnt].size = 1;
	treap[cnt].ls = treap[cnt].rs = &leaf;
	cnt++;
	return &treap[cnt-1];
}

void insert(int cur, int ver, int val){
	Node *ptl, *ptr, *ptn;
	split(root[ver], val, ptl, ptr);
	ptn = create(val);
	ptl = merge(ptl, ptn);
	root[cur] = merge(ptl, ptr);
}

void del(int cur, int ver, int val){
	Node *ptl, *ptr, *ptv;
	split(root[ver], val, ptl, ptr);
	split(ptl, val-1, ptl, ptv);
	ptv = merge(ptv -> ls, ptv -> rs);
	root[cur] = merge(merge(ptl, ptv), ptr);
}

int rank(int cur, int ver, int x){
	Node *ptl, *ptr;
	split(root[ver], x-1, ptl, ptr);
	int ans = ptl -> size + 1;
	root[cur] = merge(ptl, ptr);
	return ans;
}

int kth(Node *rt, int k){
	if(rt -> ls -> size == k - 1)
		return rt -> val;
	else if(rt -> ls -> size > k - 1)
		return kth(rt -> ls, k);
	else 
		return kth(rt -> rs, k - rt -> ls -> size - 1);
}

int pre(int cur, int ver, int x){
	Node *ptl, *ptr;
	split(root[ver], x-1, ptl, ptr);
	int ans = kth(ptl, ptl -> size);
	root[cur] = merge(ptl, ptr);
	return ans;
}

int nxt(int cur, int ver, int x){
	Node *ptl, *ptr;
	split(root[ver], x, ptl, ptr);
	int ans = kth(ptr, 1);
	root[cur] = merge(ptl, ptr);
	return ans;
}

