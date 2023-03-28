#include <cstdio>
#include <iostream>

int main(){
	freopen("data.in", "r", stdin);
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
	}
	scanf("\n");
	char op[15];
	int pos, i, k;
	while(m --> 0){
		scanf("%s", op);
		if(op[0] == 'I'){
			scanf("%d %d", &i, &k);
			pos = add(i);
			insert(pos, k);
		}
		else if(op[4] == "S"){
			
		}
		else{
		}
	}

	return 0;
}
