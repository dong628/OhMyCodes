#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#define mp make_pair
using std::sort, std::unique, std::lower_bound, std::make_pair, std::min;

const int Maxn = 5e5+5;
typedef std::pair <double, int> pdi;
int n, m, x[Maxn], y[Maxn], v[Maxn], tmpy[Maxn], uni, cnt[Maxn];
//pii mis[Maxn][Maxn];
int mis[1005][Maxn], pos[Maxn], neg[Maxn], tmp[Maxn], ans[Maxn], res[Maxn], table[Maxn];
int lj[Maxn], maxlj[Maxn];
std::pair <double, int> posl[Maxn], posr[Maxn], negl[Maxn], negr[Maxn];
void calc(int *arr, int l, int r);
bool cmp(pdi a, pdi b) { return a.first>b.first; }

int main(){
//	freopen("missile.in", "r", stdin);

	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++){
		scanf("%d %d %d", &x[i], &y[i], &v[i]);
		tmpy[i] = y[i];
	}
	sort(tmpy, tmpy+n);
	uni = int(unique(tmpy, tmpy+n) - tmpy);
	for(int i=0; i<n; i++){
		y[i] = int(lower_bound(tmpy, tmpy+n, y[i])-tmpy);
	}
	for(int i=0; i<n; i++){
		mis[y[i]][cnt[y[i]]++] = i;
	}
	double nt;
	int cpos, cneg;
	for(int la=0; la<uni; la++){
		cpos = 0; cneg = 0;
		nt = sqrt((2*tmpy[la])/9.8);
		for(int i=0; i<cnt[la]; i++){
			if(v[i] >= 0){
				posl[cpos] = mp(double(x[mis[la][i]]), i);
				posr[cpos] = mp(x[mis[la][i]]+v[mis[la][i]]*nt, i);
				cpos++;
			}
			else{
				negr[cneg] = mp(double(x[mis[la][i]]), i);
				negl[cneg] = mp(x[mis[la][i]]+v[mis[la][i]]*nt, i);
				cneg++;
			}
		}
		for(int i=0; i<cpos; i++){
			for(int j=0; j<cneg; j++){
				if(posl[i].first<negr[j].first && posr[i].first-posl[i].first+negr[j].first-negl[j].first >= negr[j].first-posl[i].first){
					ans[posr[i].second]++;
					ans[negr[j].second]++;
				}
			}
		}
		sort(posl, posl+cpos);
		sort(posr, posr+cpos, cmp);
		sort(negl, negl+cneg);
		sort(negr, negr+cneg, cmp);
		for(int i=0; i<cpos; i++){
			tmp[posl[i].second] = i;
		}
		for(int i=0; i<cpos; i++){
			pos[i] = tmp[posr[i].second];
			table[tmp[posr[i].second]] = posr[i].second;
		}
		memset(res, 0, sizeof(res));
		calc(pos, 0, cpos);
		for(int i=0; i<cnt[la]; i++){
			if(res[i] != 0) ans[mis[la][i]] += res[i];
		}
		for(int i=0; i<cneg; i++){
			tmp[negl[i].second] = i;
		}
		for(int i=0; i<cneg; i++){
			neg[i] = tmp[negr[i].second];
			table[tmp[negr[i].second]] = negr[i].second;
		}
		memset(res, 0, sizeof(res));
		calc(neg, 0, cneg);
		for(int i=0; i<cnt[la]; i++){
			if(res[i] != 0) ans[mis[la][i]] += res[i];
		}
	}
//	for(int i=0; i<n; i++) printf("%d ", ans[i]);
	int tot = 0;
	for(int i=0; i<n; i++){
		scanf("%d", &lj[i]);
		maxlj[i] = min(lj[i], ans[i]);
		tot += ans[i];
	}
	sort(maxlj, maxlj+n);
	for(int i=n-1; i>=n-m; i--){
		tot -= maxlj[i];
	}
	printf("%d", tot);

	return 0;
}

void calc(int *arr, int l, int r){
	if(r-l<=1) return;
	int mid = (r+l)>>1, ll=l, lr=mid, rl=mid, rr=r, tptr = 0;
	calc(arr, l, mid);
	calc(arr, mid, r);
	while(ll<lr && rl<rr){
		if(arr[ll] < arr[rl]){
			tmp[tptr++] = arr[rl];
			res[table[arr[ll]]]++;
			res[table[arr[rl]]]++;
			rl++;
		}
		else{
			tmp[tptr++] = arr[ll++];
		}
	}
	while(ll<lr) tmp[tptr++] = arr[ll++];
	while(rl<rr) tmp[tptr++] = arr[rl++];
	for(int i=0; i<tptr; i++){
		arr[i+l] = tmp[i];
	}
}
