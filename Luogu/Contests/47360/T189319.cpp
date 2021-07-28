#include <cstdio>
#include <iostream>

const int Maxn=2e5+5;
typedef long long LL;
LL n, line1[Maxn], line1s, line1e, line2s, line2e, data[Maxn];
int ans, t, cnt5, ans1;
void dfs(LL, LL, int, LL);
int max(int a, int b) { return a>b?a:b; }
int min(int a, int b) { return a<b?a:b; }

int main(){
//	freopen("data.in", "r", stdin);
//	freopen("data2.out", "w", stdout);
	freopen("T189319_data.cpp", "w", stdout);

	line1[0]=5;
/*	scanf("%d", &t);
	for(int cs=0; cs<t; cs++){
		scanf("%lld", &n);
		ans=0;
		dfs(n-5, n/5*2-3, 1, 0);
		ans1=ans; cnt5=0;
		ans=0;
		dfs(n, n/5*2-1, 1, 0);
		printf("%lld\n", ans+cnt5+3*ans1+1);
	}*/
	for(int i=1; i<=8; i++){
		n=5*i;
		ans=0;
		dfs(5*i, i*2-1, 1, 0);
		data[i]=ans;
		printf("%lld, ", ans+cnt5+3*data[i-1]+1);
	}

	return 0;
}

void dfs(LL rem, LL cnt, int depth, LL l2){
	if(cnt==0){
		bool flag5=false;
		line1[depth] = rem;
		line1e=-1; line2e=-1;
		for(int i=1; i<=depth; i++){
			line1s = line1e+1;
			line1e += line1[i];
			line2s = line2e+1;
			line2e += 5-line1[i];
			if(line2e<line1s || line2s>line1e) return;
			if(line1[i]==5) flag5=true;
		}
/*		for(int i=1; i<=depth; i++){
			for(int j=1; j<=line1[i]; j++){
				if(i&1) printf("M");
				else printf(".");
			}
		}
		printf("\n");
		for(int i=1; i<=depth; i++){
			for(int j=1; j<=(5-line1[i]); j++){
				if(i&1) printf("M");
				else printf(".");
			}
		}
		printf("\n\n");*/
		if(flag5) cnt5++;
		ans++;
	}

	for(int i=max(max(1, int(rem-cnt*4)), l2-(n-rem)+1); i<=min(5, int(rem-1)); i++){
		line1[depth] = i;
		dfs(rem-i, cnt-1, depth+1, l2+(5-i));
	}
/*	for(int i=max(1, int(rem-cnt*4)); i<=min(5, int(rem-1)); i++){
		line1[depth] = i;
		dfs(rem-i, cnt-1, depth+1);
	}*/
}
