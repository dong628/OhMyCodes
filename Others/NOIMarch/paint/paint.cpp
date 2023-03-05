#include <cstdio>
#include <iostream>
#include <set>
using std::set;

const int Maxn = 1e5+5;
//const int Maxn = 15;
struct Block{
	mutable int l, r, val;
	bool operator< (const Block &b) const {
		if(l == b.l) return r < b.r;
		else return l < b.l;
	}
};
set <Block> rows[Maxn];
int n, m, q, opt[Maxn], x[Maxn], c[Maxn];
void init(void), paintrow(int, int), paintcol(int, int);
set <Block>::iterator split(int, int);

int main(){
	freopen("paint.in", "r", stdin);
	freopen("paint.out", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t --> 0){
		scanf("%d %d %d", &n, &m, &q);
		init();
		for(int i=1; i<=q; i++){
			scanf("%d %d %d", &opt[i], &x[i], &c[i]);
		}
		for(int i=q; i>=1; i--){
			if(opt[i] == 0){
				paintrow(x[i], c[i]);
			}
			else{
				paintcol(x[i], c[i]);
			}
		}
		for(int i=1; i<=n; i++){
			for(auto iter = rows[i].begin(); iter != rows[i].end(); iter++){
				if(iter -> val == -1) iter -> val = 0;
				for(int j=iter->l; j<=iter->r; j++){
					printf("%d ", iter -> val);
				}
			}
			printf("\n");
		}
	}

	return 0;
}

void paintrow(int row, int color){
	for(auto iter = rows[row].begin(); iter != rows[row].end(); iter++){
		if(iter -> val == -1){
			iter -> val = color;
		}
	}
}

void paintcol(int col, int color){
	set <Block>::iterator px;
	for(int i=1; i<=n; i++){
		px = split(i, col);
		if(px -> val == -1){
			px -> val = color;
		}
	}
}

set <Block>::iterator split(int x, int pos){
	Block fp;
	fp.l = fp.r = pos;
	auto fd = rows[x].lower_bound(fp);
	if(fd == rows[x].end()) fd--;
	if(fd -> l > pos) fd--;
//	Block *fd = rows[x].find(fp);
	if(fd -> r == fd -> l || fd -> val != -1){
		return fd;
	}
	else{
		Block n0, n1, n2;
		
		if(fd -> l != pos){
			n0.l = fd -> l; n0.r = pos - 1; n0.val = -1;
			rows[x].insert(n0);
		}
		n1.l = pos; n1.r = pos; n1.val = -1;
		if(fd -> r != pos){
			n2.l = pos + 1; n2.r = fd -> r; n2.val = -1;
			rows[x].insert(n2);
		}
		rows[x].erase(fd);
		return rows[x].insert(n1).first;
	}
}

void init(){
	Block ins;
	ins.l = 1; ins.r = m; ins.val = -1;
	for(int i=1; i<=n; i++){
		rows[i].clear();
		rows[i].insert(ins);
	}
}
