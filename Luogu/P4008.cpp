#include <cstdio>
#include <iostream>

const int Maxn = 2*1024*1024+5;
//const int Maxn = 1e2+5;
struct Node{
	int size, pri;
	char val;
	Node *ls, *rs;
} treap[Maxn], leaf, *root;
int cnt;
void split(Node *rt, int rk, Node *&spl, Node *&spr);
Node *merge(Node *, Node *), *create(char);
void insert(int, char), del(int, int), get(int, int), output(Node *), input(int);
void update(Node *);

int main(){
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);

	int t, n, cur = 1, tcur; char tmp, opt; Node *nt;

	root = merge(create('*'), create('*'));

	srand(114514);

	scanf("%d\n", &t);
	while(t--){
		while(true){
			opt = getchar();
			if(opt != ' ' && opt != '\n' && opt != '\r') break;
		}
		if(opt == 'M'){
			input(4); scanf("%d", &n); getchar();
			cur = n + 1;
		}
		else if(opt == 'I'){
			input(6); scanf("%d", &n); getchar();
			tcur = cur;
			for(int i=0; i<n; i++){
				tmp = getchar();
				if(tmp == '\n' || tmp == '\r'){
					i--; continue;
				}
				insert(cur, tmp);
				cur++;
			}
			cur = tcur;
		}
		else if(opt == 'D'){
			input(6); scanf("%d", &n); getchar();
			del(cur, n);
		}
		else if(opt == 'G'){
			input(3); scanf("%d", &n); getchar();
			get(cur, n);
		}
		else if(opt == 'P'){
			input(4); cur--;
		}
		else{
			input(4); cur++;
		}
/*
		printf("%d : ", cur);
		output(root);
		putchar('\n');
*/
	}

	return 0;
}

void input(int n){
	for(int i=0; i<n; i++) getchar();
}

void split(Node *rt, int rk, Node *&spl, Node *&spr){
	if(rt == &leaf){
		spl = spr = &leaf;
		return;
	}
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

void insert(int rk, char c){
	Node *spl, *spr, *spc;
	spc = create(c);
	split(root, rk, spl, spr);
	spl = merge(spl, spc);
	root = merge(spl, spr);
}

void del(int rk, int cntn){
	Node *spl, *spr, *spc;
	split(root, rk, spl, spr);
	split(spr, cntn, spc, spr);
	root = merge(spl, spr);
}

void get(int rk, int cntn){
	Node *spl, *spr, *spc;
	split(root, rk, spl, spr);
	split(spr, cntn, spc, spr);
	output(spc);
	printf("\n");
	spl = merge(spl, spc);
	root = merge(spl, spr);
}

void output(Node *rt){
	if(rt == &leaf) return;
	output(rt -> ls);
	printf("%c", rt -> val);
	output(rt -> rs);
}

Node *create(char val){
	treap[cnt].size = 1;
	treap[cnt].ls = treap[cnt].rs = &leaf;
	treap[cnt].val = val;
	treap[cnt].pri = rand();
	cnt++;
	return &treap[cnt-1];
}

void update(Node *rt){
	rt -> size = rt -> ls -> size + rt -> rs -> size + 1;
}
