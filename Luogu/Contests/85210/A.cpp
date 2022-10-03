#include <cstdio>
#include <iostream>
#include <cmath>
#define int long long

const int Maxn = 2e5+5, Maxsq = 1e3+5, Tl = 1<<30;
//const int Maxn = 2e2+5, Maxsq = 1e2+5, Tl = 1<<30;
int n, q, num, block;
int a[Maxn], start[Maxsq], end[Maxsq], times[Maxsq], timest[Maxsq], tl[Maxsq], negc[Maxsq];
int max(int xx, int yy) { return xx>yy?xx:yy; }
void set(int, int);
int query(int, int);

signed main(){
//	freopen("data.in", "r", stdin);

	int ty, tmp, x, y;
	scanf("%lld %lld", &n, &q);
	for(int i=0; i<n; i++){
		scanf("%lld", &a[i]);
	}
	block = sqrt(n); num = n/block;
	for(int i=0; i<num; i++){
		start[i] = i*block;
		end[i] = (i+1)*block;
		times[i] = 1; timest[i] = 1;
		for(int j=start[i]; j<end[i]; j++){
			if(a[j] <= 0) negc[i]++;
			timest[i] *= a[j];
			times[i] *= a[j];
			if(times[i] < -(1<<30)) { tl[i]++; times[i] /= Tl; }
			if(times[i] > (1<<30)) { tl[i]++; times[i] /= Tl; }
		}
	}
	if(num*block != n){
		start[num] = num*block;
		end[num] = n;
		times[num] = 1; timest[num] = 1;
		for(int j=start[num]; j<end[num]; j++){
			if(a[j] <= 0) negc[num]++;
			timest[num] *= a[j];
			times[num] *= a[j];
			if(times[num] < -(1<<30)) { tl[num]++; times[num] /= Tl; }
			if(times[num] > (1<<30)) { tl[num]++; times[num] /= Tl; }
		}
		num++;
	}

	int count2 = 0;
	for(int i=0; i<q; i++){
		scanf("%lld %lld %lld", &ty, &x, &y);
//		if(count2 == 15947){
//			printf("%lld %lld", x, y);
//		}
		if(ty == 1) set(x-1, y);
		else{
			count2++;
			tmp = query(x-1, y-1);
			if(tmp == -1) printf("Too large\n");
			else printf("%lld\n", tmp);
		}
	}

	return 0;
}

void set(int ind, int val){
	int id = ind/block;
	if(a[ind] < 0) negc[id]--;
	if(val < 0) negc[id]++;
	a[ind] = val;
	times[id] = 1; timest[id] = 1;
	tl[id] = 0;
	for(int j=start[id]; j<end[id]; j++){
		timest[id] *= a[j];
		times[id] *= a[j];
		if(times[id] < -(1<<30)) { tl[id]++; times[id] /= Tl; }
		if(times[id] > (1<<30)) { tl[id]++; times[id] /= Tl; }
	}
}

int query(int l, int r){
	int lb = l/block, rb = r/block;
	int ans = 1, tlt = 0, anst = 1, cneg = 0;

	if(lb == rb){
		for(int i=l; i<=r; i++){
			if(a[i] < 0) cneg++;
			ans *= a[i];
			anst *= a[i];
			if(ans < -(1<<30)) { tlt++; ans /= Tl; }
			if(ans > (1<<30)) { tlt++; ans /= Tl; }
		}
		if(ans > 0 && tlt > 0) return -1;
		else if(ans > 0 && tlt == 0) return ans;
		if(tlt >= 3) return -1;
		if(tlt == 2 && cneg != 1) return -1;
		if(tlt == 2){
			int ansl = 1, ansr = 1;
			for(int i=l; i<=r; i++){
				if(a[i] < 0) break;
				ansl *= a[i];
				if(ansl > Tl) return -1;
			}
			for(int i=r; i>=l; i--){
				if(a[i] < 0) break;
				ansr *= a[i];
				if(ansr > Tl) return -1;
			}
			ans = max(ansl, ansr);
			return ans;
		}
		int ansl = anst, ansr = anst;
		for(int i=l; i<=r; i++){
			ansl /= a[i];
			if(ansl > 0) break;
		}
		for(int i=r; i>=l; i--){
			ansr /= a[i];
			if(ansr > 0) break;
		}
		ans = max(ansl, ansr);
		if(ans > Tl) return -1;
		else return ans;
	}

	for(int i=l; i<end[lb]; i++){
		if(a[i] < 0) cneg++;
		ans *= a[i];
		anst *= a[i];
		if(ans < -(1<<30)) { tlt++; ans /= Tl; }
		if(ans > (1<<30)) { tlt++; ans /= Tl; }
	}
	for(int i=start[rb]; i<=r; i++){
		if(a[i] < 0) cneg++;
		ans *= a[i];
		anst *= a[i];
		if(ans < -(1<<30)) { tlt++; ans /= Tl; }
		if(ans > (1<<30)) { tlt++; ans /= Tl; }
	}
	for(int i=lb+1; i<=rb-1; i++){
		cneg += negc[i];
		tlt += tl[i];
		ans *= times[i];
		anst *= timest[i];
		if(ans < -(1<<30)) { tlt++; ans /= Tl; }
		if(ans > (1<<30)) { tlt++; ans /= Tl; }
	}
	if(ans > 0 && tlt > 0) return -1;
	else if(ans > 0 && tlt == 0) return ans;
	if(tlt >= 3) return -1;
	if(tlt == 2 && cneg != 1) return -1;
	if(tlt == 2){
//		printf("aaa");
		int ansl = 1, ansr = 1, flag = -1;
		bool flag1 = false;
		for(int i=lb+1; i<=rb-1; i++){
			if(negc[i] > 0){
				flag = i;
				break;
			}
		}
		for(int i=l; i<end[lb]; i++){
			if(a[i] < 0) { flag1 = true; break; }
			ansl *= a[i];
			if(ansl > Tl) return -1;
		}
		if(!flag1){
			if(flag != -1){
				for(int i=lb+1; i<flag; i++){
					if(timest[i] < 0) { flag1 = true; break; }
					ansl *= timest[i];
					if(ansl > Tl) return -1;
				}
			}
			else{
				for(int i=lb+1; i<rb; i++){
					if(timest[i] < 0) { flag1 = true; break; }
					ansl *= timest[i];
					if(ansl > Tl) return -1;
				}
			}
		}
		if(!flag1){
			for(int i=start[rb]; i<=r; i++){
				if(a[i] < 0) { flag1 = true; break; }
				ansl *= a[i];
				if(ansl > Tl) return -1;
			}
		}

		flag1 = false;
		for(int i=r; i>=start[rb]; i--){
			if(a[i] < 0) { flag1 = true; break; }
			ansr *= a[i];
			if(ansr > Tl) return -1;
		}
		if(!flag1){
			if(flag != -1){
				for(int i=rb-1; i>flag; i--){
					if(timest[i] < 0) { flag1 = true; break; }
					ansr *= timest[i];
					if(ansr > Tl) return -1;
				}
			}
			else{
				for(int i=rb-1; i>lb; i--){
					if(timest[i] < 0) { flag1 = true; break; }
					ansr *= timest[i];
					if(ansr > Tl) return -1;
				}
			}
		}
		if(!flag1){
			for(int i=end[lb]; i>=l; i--){
				if(a[i] < 0) { flag1 = true; break; }
				ansr *= a[i];
				if(ansr > Tl) return -1;
			}
		}

		ans = max(ansl, ansr);
		return ans;
	}

	int ansl = anst, ansr = anst, flag;
	for(int i=l; i<end[lb]; i++){
		ansl /= a[i];
		if(ansl > 0) break;
	}
	if(ansl < 0){
		flag = -1;
		for(int i=lb+1; i<=rb-1; i++){
			if(negc[i] > 0){
				flag = i;
				break;
			}
			else{
				ansl /= timest[i];
			}
		}
		if(flag != -1){
			for(int i=start[flag]; i<end[flag]; i++){
				ansl /= a[i];
				if(ansl > 0) break;
			}
		}
	}
	if(ansl < 0){
		for(int i=start[rb]; i<=r; i++){
			ansl /= a[i];
			if(ansl > 0) break;
		}
	}

	for(int i=r; i>=start[lb]; i--){
		ansr /= a[i];
		if(ansr > 0) break;
	}
	if(ansr < 0){
		flag = -1;
		for(int i=rb-1; i>=lb+1; i--){
			if(negc[i] > 0){
				flag = i;
				break;
			}
			else{
				ansr /= timest[i];
			}
		}
		if(flag != -1){
			for(int i=end[flag]-1; i<=start[flag]; i--){
				ansr /= a[i];
				if(ansr > 0) break;
			}
		}
	}
	if(ansr < 0){
		for(int i=end[lb]-1; i>=l; i--){
			ansr /= a[i];
			if(ansr > 0) break;
		}
	}
	
	ans = max(ansl, ansr);
	if(ans > Tl) return -1;
	else return ans;
}
