#include <cstdio>
#include <iostream>

struct Node{
	int val, pri, size;
	Node *ls, *rs;
} treap[Maxn], leaf, *rts[Maxn];
int cntt = 0, cntr = 2;

Node *create(int x){
	treap[cntt].val = x;
	treap[cntt].pri = rand();
	treap[cntt].size = 1;
	treap[cntt].ls = treap[cntt].rs = &leaf;
	cntt++;
	return &treap[cntt-1];
}

void update(Node *rt){
	rt -> size = rt -> ls -> size + rt -> rs -> size + 1;
}

Node *merge(Node *l, Node *r){
	if(l == &leaf) return r;
	if(r == &leaf) return l;
	Node *rt;
	if(l -> pri < r -> pri){
		rt = r;
		r -> ls = merge(l, r -> ls);
	}
	else{
		rt = l;
		l -> rs = merge(l -> rs, r);
	}
	update(rt);
	return rt;
}

void split(Node *rt, Node *&l, Node *&r, int v){
	if(rt == &leaf){
		l = &leaf; r = &leaf;
		return;
	}
	if(rt -> val > v){
		r = rt;
		split(rt -> ls, l, rt -> ls, v);
		update(r);
	}
	else{
		l = rt;
		split(rt -> rs, rt -> rs, r, v);
		update(l);
	}
}

void insert(Node*, int);

int main(){

	int n, m, a;
	scanf("%d %d", &n, &m);
	rts[1] = merge(create(-Inf), create(Inf));
	for(int i=1; i<=n; i++){
		scanf("%d", &a);
		insert(rts[1], a);
	}

	int opt;
	Node *spl, *spr, *spm;
	while(m --> 0){
		scanf("%d", &opt);
		if(opt == 0){
			scanf("%d %d %d", &p, &x, &y);
			split(rts[p], spl, spr, x);
			split(spr, spm, spr, y+1);
			rts[cntr++] = spm;
			rts[p] = merge(spl, spr);
		}
		else if(opt == 1){
			scanf("%d %d", &p, &x);

		}
		else if(opt == 2){
			scanf("%d %d %d", &p, &x, &y);
		}
		else if(opt == 3){
			scanf("%d %d %d", &p, &x, &y);
		}
		else{
			scanf("%d %d", &p, &x);
		}
	}

	return 0;
}

void insert(Node *rt, int x){
	Node *spl, *spr, *spm;
	split(rt, spl, spr, x);
	spm = create(x);
	spl = merge(spl, spm);
	rt = merge(spl, spr);
}
