#include <cstdio>
#include <iostream>

const int Maxn = 2e6+5, Inf = 0x7fffffff;
struct Node{
	Node *ls, *rs;
	int pri, val, size;
} treap[Maxn], leaf;
int cnt;

void split(Node *, int, Node *&, Node *&);
void insert(Node *&, int), del(Node *&, int), update(Node *);
int rank(Node *&, int), kth(Node *, int), pre(Node *&, int), nxt(Node *&, int);
Node *merge(Node*, Node*), *create(int), *init(void);

int main(){
	freopen("data.in", "r", stdin);
	
	srand(114514);
	int t, opt, x, n, last = 0, ans = 0;
	leaf.size = 0; leaf.val = 0; leaf.ls = &leaf; leaf.rs = &leaf;
	Node *root = init();
	scanf("%d %d", &n, &t);
	for(int i=0; i<n; i++){
		scanf("%d", &x);
		insert(root, x);
	}

	while(t--){
		scanf("%d %d", &opt, &x);
		x ^= last;
		switch(opt){
			case 1: insert(root, x);			break;
			case 2: del(root, x);				break;
			case 3: last = rank(root, x)-1; ans ^= last;	break;
			case 4: last = kth(root, x+1); ans ^= last;	break;
			case 5: last = pre(root, x); ans ^= last;	break;
			case 6: last = nxt(root, x); ans ^= last;	break;
		}
	}
	
	printf("%d", ans);

	return 0;
}

Node *init(void){
	Node *rt = create(int(-Inf));
	rt -> rs = create(int(Inf));
	update(rt);
	return rt;
}

void split(Node *rt, int val, Node *&spl, Node *&spr){
	if(rt == &leaf) { spl = spr = &leaf; return; }
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

void insert(Node *&rt, int val){
	Node *ptl, *ptr, *ptn;
	split(rt, val, ptl, ptr);
	ptn = create(val);
	ptl = merge(ptl, ptn);
	rt = merge(ptl, ptr);
}

void del(Node *&rt, int val){
	Node *ptl, *ptr, *ptv;
	split(rt, val, ptl, ptr);
	split(ptl, val-1, ptl, ptv);
	ptv = merge(ptv -> ls, ptv -> rs);
	rt = merge(merge(ptl, ptv), ptr);
}

int rank(Node *&rt, int x){
	Node *ptl, *ptr;
	split(rt, x-1, ptl, ptr);
	int ans = ptl -> size + 1;
	rt = merge(ptl, ptr);
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

int pre(Node *&rt, int x){
	Node *ptl, *ptr;
	split(rt, x-1, ptl, ptr);
	int ans = kth(ptl, ptl -> size);
	rt = merge(ptl, ptr);
	return ans;
}

int nxt(Node *&rt, int x){
	Node *ptl, *ptr;
	split(rt, x, ptl, ptr);
	int ans = kth(ptr, 1);
	rt = merge(ptl, ptr);
	return ans;
}

