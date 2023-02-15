#include <cstdio>
#include <iostream>

const int Maxn = 1e5+5, Inf = 0x3f3f3f3f;
struct Node{
	int val, size, pri;
	Node *ls, *rs;
} *rt, treap[Maxn], leaf;
int cnt;

void insert(int), del(int);
int query(Node*, int), kth(Node*, int), pre(int), nxt(int);

void update(Node *root){
	root -> size = root -> ls -> size + root -> rs -> size + 1;
}

Node *create(int val){
	treap[cnt].val = val;
	treap[cnt].size = 1;
	treap[cnt].pri = rand();
	treap[cnt].ls = treap[cnt].rs = &leaf;
	cnt++;
	return &treap[cnt-1];
}

void split(Node *root, int x, Node *&l, Node *&r){
	if(root == &leaf) { l = r = &leaf; return; }
	if(root -> val <= x){
		l = root;
		split(root -> rs, x, root -> rs, r);
	}
	else{
		r = root;
		split(root -> ls, x, l, root -> ls);
	}
	update(root);
}

Node *merge(Node *lmg, Node *rmg){
	if(lmg == &leaf) return rmg;
	if(rmg == &leaf) return lmg;
	if(lmg -> pri > rmg -> pri){
		lmg -> rs = merge(lmg -> rs, rmg);
		update(lmg);
		return lmg;
	}
	else{
		rmg -> ls = merge(lmg, rmg -> ls);
		update(rmg);
		return rmg;
	}
}

int main(){
	freopen("data.in", "r", stdin);

	int n, opt, x;
	scanf("%d", &n);

	rt = merge(create(-Inf), create(Inf));
	while(n --> 0){
		scanf("%d %d", &opt, &x);
		if(opt == 1){
			insert(x);
		}
		else if(opt == 2){
			del(x);
		}
		else if(opt == 3){
			printf("%d\n", query(rt, x)-1);
		}
		else if(opt == 4){
			printf("%d\n", kth(rt, x+1));
		}
		else if(opt == 5){
			printf("%d\n", pre(x));
		}
		else{
			printf("%d\n", nxt(x));
		}
	}

	return 0;
}

void insert(int x){
	Node *spl, *spr, *spm;
	spm = create(x);
	split(rt, x, spl, spr);
	spl = merge(spl, spm);
	rt = merge(spl, spr);
}

void del(int x){
	Node *spl, *spr, *spm;
	split(rt, x, spl, spr);
	split(spl, x-1, spl, spm);
	spm = merge(spm -> ls, spm -> rs);
	rt = merge(merge(spl, spm), spr);
}

int query(Node *root, int x){
	Node *spl, *spr;
	split(root, x-1, spl, spr);
	int ans = spl -> size + 1;
	root = merge(spl, spr);
	return ans;
}

int kth(Node *root, int x){
	if(root -> ls -> size == x - 1) return root -> val;
	if(root -> ls -> size > x - 1) return kth(root -> ls, x);
	else return kth(root -> rs, x - root -> ls -> size - 1);
}

int pre(int x){
	Node *spl, *spr;
	split(rt, x-1, spl, spr);
	int ans = kth(spl, spl -> size);
	rt = merge(spl, spr);
	return ans;
}

int nxt(int x){
	Node *spl, *spr;
	split(rt, x, spl, spr);
	int ans = kth(spr, 1);
	rt = merge(spl, spr);
	return ans;
}
