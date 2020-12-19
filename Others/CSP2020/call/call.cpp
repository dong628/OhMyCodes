#include <cstdio>
#include <iostream>

const int Max=1005, Mod=998244353;
int n, m, q, a[Max], func[Max][Max], x;
void cal(int);

int main(){
	freopen("call.in", "r", stdin);
	freopen("call.out", "w", stdout);

	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	scanf("%d", &m);
	for(int i=1; i<=m; i++){
		scanf("%d", &func[i][0]);
		if(func[i][0]==1) { scanf("%d %d", &func[i][1], &func[i][2]); func[i][2]%=Mod; }
		else if(func[i][0]==2) { scanf("%d", &func[i][1]); func[i][1]%=Mod; }
		else{
			scanf("%d", &func[i][1]);
			for(int j=2; j<func[i][1]+2; j++){
				scanf("%d", &func[i][j]);
			}
		}
	}
	scanf("%d", &q);
	for(int i=0; i<q; i++){
		scanf("%d", &x);
		cal(x);
	}
	for(int i=0; i<n; i++){
		printf("%d ", a[i]%Mod);
	}

	return 0;	
}

void cal(int nu){
	if(func[nu][0]==1){
		a[func[nu][1]-1]+=func[nu][2]%Mod;
		a[func[nu][1]-1]%=Mod;
	}
	if(func[nu][0]==2){
		for(int i=0; i<n; i++){
			a[i]*=func[nu][1];
			a[i]%=Mod;
		}
	}
	if(func[nu][0]==3){
		for(int i=2; i<func[nu][1]+2; i++){
			cal(func[nu][i]);
		}
	}
}
