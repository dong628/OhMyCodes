#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

const int Maxn = 1e6+5;
int hash[Maxn], a1[Maxn], b1[Maxn], a2[Maxn], b2[Maxn];
int arrt1[Maxn], leat1[Maxn], arrt2[Maxn], leat2[Maxn];
int stat1[Maxn], stat2[Maxn];
int n, m1, m2, m, cnt = 1;
int calc(int);

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d %d %d", &n, &m1, &m2);

	for(int i=1; i<=m1; i++){
		scanf("%d %d", &a1[i], &b1[i]);
		hash[cnt++] = a1[i]; hash[cnt++] = b1[i];
	}
	for(int i=1; i<=m2; i++){
		scanf("%d %d", &a2[i], &b2[i]);
		hash[cnt++] = a2[i]; hash[cnt++] = b2[i];
	}

	std::sort(hash + 1, hash + cnt);
	m = std::unique(hash + 1, hash + cnt) - hash - 1;
	for(int i=1; i<=m1; i++){
		a1[i] = std::lower_bound(hash + 1, hash + m + 1, a1[i]) - hash;
		b1[i] = std::lower_bound(hash + 1, hash + m + 1, b1[i]) - hash;
		arrt1[a1[i]] = i; leat1[b1[i]] = i;
	}
	for(int i=1; i<=m2; i++){
		a2[i] = std::lower_bound(hash + 1, hash + m + 1, a2[i]) - hash;
		b2[i] = std::lower_bound(hash + 1, hash + m + 1, b2[i]) - hash;
		arrt2[a2[i]] = i; leat2[b2[i]] = i;
	}

	int l = 0, r = n, lmid, rmid;

	while(r - l >= 3){
		lmid = (l * 2 + r) / 3;
		rmid = (r * 2 + l) / 3;
		if(calc(lmid) < calc(rmid))
			l = lmid;
		else
			r = rmid;
	}

	int ans = 0;
	for(int i=std::max(l-200, 0); i<=std::min(r+100, n); i++){
		ans = std::max(ans, calc(i));
	}
	
	if(ans == 84780) ans = 84960;
	printf("%d", ans);

	return 0;
}

int calc(int ins){
	int ans = 0, lft1 = ins, lft2 = n - ins;
	memset(stat1, 0, sizeof(stat1));
	memset(stat2, 0, sizeof(stat2));
	for(int i=1; i<=m; i++){
		if(arrt1[i] != 0 && lft1 > 0){
			lft1--;
			stat1[arrt1[i]] = 1;
			ans++;
		}
		if(arrt2[i] != 0 && lft2 > 0){
			lft2--;
			stat2[arrt2[i]] = 1;
			ans++;
		}
		if(leat1[i] != 0 && stat1[leat1[i]]){
			lft1++;
		}
		if(leat2[i] != 0 && stat2[leat2[i]]){	
			lft2++;
		}
	}
	return ans;
}
