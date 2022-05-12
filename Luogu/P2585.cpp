#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int Maxn = 5e5+5;
string s;
int st[Maxn][2], t[Maxn][2], cnt[Maxn], top, cur, fmin[Maxn][2], fmax[Maxn][2];
bool vismax[Maxn][2], vismin[Maxn][2];
int dpmax(int, int, bool), dpmin(int, int, bool);
void mktree(string, int);

int main(){
	freopen("data.in", "r", stdin);

	getline(cin, s);

	mktree(s, 0);
	printf("%d ", max(dpmax(0, 0, true), dpmax(0, 1, true)));
	printf("%d", min(dpmin(0, 0, true), dpmin(0, 1, true)));

	return 0;
}

void mktree(string a, int root){
	st[top][0] = a[0]-'0'; st[top][1] = 0;
	top++; cur++;
	while(cur < a.size() && top!=0){
		st[top-1][0]--;
		t[st[top-1][1]][cnt[st[top-1][1]]++] = cur;
		if(st[top-1][0] == 0){
			top--;
		}
		if(a[cur]-'0' != 0){
			st[top][0] = a[cur]-'0'; st[top][1] = cur;
			top++;
		}
		cur++;
	}
}

int dpmax(int node, int c, bool fst){
	if(fst == false && node == 0) return 0;
	if(vismax[node][c]) return fmax[node][c];
	vismax[node][c] = true;
	if(cnt[node] == 0){
		return c;
	}
	if(c==0){
		fmax[node][c] = max(dpmax(t[node][0],0,false)+dpmax(t[node][1],1,false), dpmax(t[node][0],1,false)+dpmax(t[node][1],0,false));
	}
	if(c==1){
		fmax[node][c] = dpmax(t[node][0],0,false)+dpmax(t[node][1],0,false)+1;
	}
	return fmax[node][c];
}

int dpmin(int node, int c, bool fst){
	if(fst == false && node == 0) return 0;
	if(vismin[node][c]) return fmin[node][c];
	vismin[node][c] = true;
	if(cnt[node] == 0){
		return c;
	}
	if(c==0){
		fmin[node][c] = min(dpmin(t[node][0],0,false)+dpmin(t[node][1],1,false), dpmin(t[node][0],1,false)+dpmin(t[node][1],0,false));
	}
	if(c==1){
		fmin[node][c] = dpmin(t[node][0],0,false)+dpmin(t[node][1],0,false)+1;
	}
	return fmin[node][c];
}
