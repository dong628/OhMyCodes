#include <iostream>
#include <cstdio>
#define int long long

//const int Maxn = 15;
const int Maxn = 2505;
int n, m, k, a[Maxn][Maxn], s[Maxn][Maxn];
int qs(int, int, int, int);
int divide(int, int, int, int);

signed main(){
	freopen("data.in", "r", stdin);
	
	scanf("%lld %lld %lld\n", &n, &m, &k);

	char ch;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			ch = getchar();
			a[i][j] = ch - '0';
		}
		getchar();
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			s[i][j] = a[i][j] + s[i-1][j] + s[i][j-1] - s[i-1][j-1];
		}
	}

	int ans = divide(1, 1, n, m);
	
	printf("%lld", ans);

	return 0;
}

int qs(int x1, int y1, int x2, int y2){
	if(x1 > x2) std::swap(x1, x2);
	if(y1 > y2) std::swap(y1, y2);
	return s[x2][y2] - s[x1-1][y2] - s[x2][y1-1] + s[x1-1][y1-1];
}

int divide(int x1, int y1, int x2, int y2){
	if(x1 == x2 && y1 == y2) return a[x1][y1] == k;
	int ans = 0, q1, q2, l, r, mmid;
	if(x2 - x1 > y2 - y1){
		int mid = (x1 + x2 - 1) >> 1;
		ans += divide(x1, y1, mid, y2);
		ans += divide(mid+1, y1, x2, y2);
		for(int i=y1; i<=y2; i++){
			for(int j=i; j<=y2; j++){
				for(int x=0; x<=k; x++){
					l = x1; r = mid;
					while(l < r){
						mmid = (l+r+1) >> 1;
						if(qs(mmid, i, mid, j) < x) r = mmid - 1;
						else l = mmid;
					}
					if(qs(l, i, mid, j) < x) l = x1 - 1;
					q1 = l;
					l = x1; r = mid;
					while(l < r){
						mmid = (l+r+1) >> 1;
						if(qs(mmid, i, mid, j) < x + 1) r = mmid - 1;
						else l = mmid;
					}
					if(qs(l, i, mid, j) < x + 1) l = x1 - 1;
					q1 = q1 - l;

					l = mid + 1; r = x2;
					while(l < r){
						mmid = (l+r) >> 1;
						if(qs(mid+1, i, mmid, j) >= k - x) r = mmid;
						else l = mmid + 1;
					}
					if(qs(mid+1, i, l, j) < k - x) l = x2 + 1;
					q2 = l;
					l = mid + 1; r = x2;
					while(l < r){
						mmid = (l+r) >> 1;
						if(qs(mid+1, i, mmid, j) >= k - x + 1) r = mmid;
						else l = mmid + 1;
					}
					if(qs(mid+1, i, l, j) < k - x + 1) l = x2 + 1;
					q2 = l - q2;

					ans += q1 * q2;
				}
			}
		}
	}
	else{
		int mid = (y1 + y2 - 1) >> 1;
		ans += divide(x1, y1, x2, mid);
		ans += divide(x1, mid+1, x2, y2);
		for(int i=x1; i<=x2; i++){
			for(int j=i; j<=x2; j++){
				for(int x=0; x<=k; x++){
					l = y1; r = mid;
					while(l < r){
						mmid = (l+r+1) >> 1;
						if(qs(i, mmid, j, mid) < x) r = mmid - 1;
						else l = mmid;
					}
					if(qs(i, l, j, mid) < x) l = y1 - 1;
					q1 = l;
					l = y1; r = mid;
					while(l < r){
						mmid = (l+r+1) >> 1;
						if(qs(i, mmid, j, mid) < x + 1) r = mmid - 1;
						else l = mmid;
					}
					if(qs(i, l, j, mid) < x + 1) l = y1 - 1;
					q1 = q1 - l;

					l = mid + 1; r = y2;
					while(l < r){
						mmid = (l+r) >> 1;
						if(qs(i, mid+1, j, mmid) >= k - x) r = mmid;
						else l = mmid + 1;
					}
					if(qs(i, mid+1, j, l) < k - x) l = y2 + 1;
					q2 = l;
					l = mid + 1; r = y2;
					while(l < r){
						mmid = (l+r) >> 1;
						if(qs(i, mid+1, j, mmid) >= k - x + 1) r = mmid;
						else l = mmid + 1;
					}
					if(qs(i, mid+1, j, l) < k - x + 1) l = y2 + 1;
					q2 = l - q2;

					ans += q1 * q2;
				}
			}
		}
	}
	return ans;
}
