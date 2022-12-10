#include <cstdio>
#include <iostream>
#include <cstring>

const int Maxn = 2505;
//const int Maxn = 25;
int mapp[Maxn][Maxn];
long long smp[Maxn][Maxn], up[10], dn[10];
long long calc(int, int, int, int, int);
long long sum(int xl, int yl, int xr, int yr){
	return smp[xr][yr] - smp[xl-1][yr] - smp[xr][yl-1] + smp[xl-1][yl-1];
}
int min(int a, long long b) { return a<b?a:b; }

int main(){
	freopen("data.in", "r", stdin);

	int n, m, k;
	char ch;
	scanf("%d %d %d\n", &n, &m, &k);

	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			ch = getchar();
			if(ch == '0') mapp[i][j] = 0;
			else mapp[i][j] = 1;
		}
		getchar();
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			smp[i][j] = mapp[i][j] + smp[i-1][j] + smp[i][j-1] - smp[i-1][j-1];
		}
	}

	long long ans;

	ans = calc(1, 1, n, m, k);
	printf("%lld", ans);

	return 0;
}

long long calc(int xl, int yl, int xr, int yr, int k){
	if(xr == xl && yr == yl){
		return mapp[xl][yl] == k;
	}
	long long ans = 0, tmp;
	int mid, lmid, l, r;
	if(xr - xl >= yr - yl){
		mid = (xr + xl) >> 1;
		for(int i=yl; i<=yr; i++){
			for(int j=i; j<=yr; j++){
//				memset(up, 0, sizeof(up));
//				memset(dn, 0, sizeof(dn));
				tmp = min(k, sum(xl, i, mid, j));
				for(int val = 0; val <= tmp; val++){
					l = 0; r = mid-xl+1;
					while(l<r){
						lmid = (l+r+1)>>1;
						if(sum(mid-lmid+1, i, mid, j) <= val) l = lmid;
						else r = lmid - 1;
					}
//					if(sum(mid-l-1, i, mid, j) < val && l==mid-xl+1) break;
//					if(val != 0) up[val] = l - up[val-1];
					up[val] = l;
				}
				for(int val = tmp; val >= 0; val--) up[val] -= up[val-1];
				tmp = min(k, sum(mid+1, i, xr, j));
				for(int val = 0; val <= tmp; val++){
					l = 0; r = xr-mid;
					while(l<r){
						lmid = (l+r+1)>>1;
						if(sum(mid+1, i, mid+lmid, j) <= val) l = lmid;
						else r = lmid - 1;
					}
//					if(sum(mid+1, i, mid+l, j) < val && l==xr-mid) break;
//					if(val != 0) dn[val] = l - dn[val-1];
					dn[val] = l;
				}
				for(int val = tmp; val >= 0; val--) dn[val] -= dn[val-1];
/*
				for(int l=0; l<=mid-xl; l++){
					tmp = sum(mid - l, i, mid, j);
					if(tmp <= k){
						up[tmp]++;
					}
					else break;
				}
				for(int l=0; l<=xr-mid-1; l++){
					tmp = sum(mid + 1, i, mid + l + 1, j);
					if(tmp <= k){
						dn[tmp]++;
					}
					else break;
				}
*/
				for(int l=0; l<=k; l++){
					ans += up[l]*dn[k-l];
				}
			}
		}
		ans += calc(xl, yl, mid, yr, k);
		ans += calc(mid+1, yl, xr, yr, k);
	}
	else{
		mid = (yr + yl) >> 1;
		for(int i=xl; i<=xr; i++){
			for(int j=i; j<=xr; j++){
//				memset(up, 0, sizeof(up));
//				memset(dn, 0, sizeof(dn));
				tmp = min(k, sum(i, yl, j, mid));
				for(int val = 0; val <= tmp; val++){
					l = 0; r = mid-yl+1;
					while(l<r){
						lmid = (l+r+1)>>1;
						if(sum(i, mid-lmid+1, j, mid) <= val) l = lmid;
						else r = lmid - 1;
					}
//					if(sum(i, mid-l-1, j, mid) < val && l==mid-yl+1) break;
//					if(val != 0) up[val] = l - up[val-1];
					up[val] = l;
				}
				for(int val = tmp; val >= 0; val--) up[val] -= up[val-1];
				tmp = min(k, sum(i, mid+1, j, yr));
				for(int val = 0; val <= tmp; val++){
					l = 0; r = yr-mid;
					while(l<r){
						lmid = (l+r+1)>>1;
						if(sum(i, mid+1, j, mid+lmid) <= val) l = lmid;
						else r = lmid - 1;
					}
//					if(sum(i, mid+1, j, mid+l) < val && l==yr-mid) break;
//					if(val != 0) dn[val] = l - dn[val-1];
					dn[val] = l;
				}
				for(int val = tmp; val >= 0; val--) dn[val] -= dn[val-1];
/*
				for(int l=0; l<=mid-yl; l++){
					tmp = sum(i, mid - l, j, mid);
					if(tmp <= k){
						up[tmp]++;
					}
					else break;
				}
				for(int l=0; l<=yr-mid-1; l++){
					tmp = sum(i, mid + 1, j, mid + l + 1);
					if(tmp <= k){
						dn[tmp]++;
					}
					else break;
				}
*/
				for(int l=0; l<=k; l++){
					ans += up[l]*dn[k-l];
				}
			}
		}
		ans += calc(xl, yl, xr, mid, k);
		ans += calc(xl, mid+1, xr, yr, k);
	}
	return ans;
}
