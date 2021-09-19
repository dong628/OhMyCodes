#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

const int Maxi = 1445, Maxm = 505;
int n, m, a[Maxm], b[Maxm], x[Maxm], pw, now;
int head, tail;

int main(){
	freopen("exercise.in", "r", stdin);
	freopen("exercise.out", "w", stdout);

	scanf("%d %d\n", &n, &m);
	pw = n;
	for(int i=1; i<=m; i++){
		while(getchar()!=' ');
		scanf("%d %d %d\n", &a[i], &b[i], &x[i]);
	}
	for(int i=1; i<=Maxi; i++){
		pw++;
		for(int j=1; j<=m; j++){
			if(a[j]<=i && b[j]>=i){
				pw-=x[j];
			}
		}
		if(pw<=0){
			printf("Runtime Error\n%d\n", i);
			return 0;
		}
	}
//	now = 1;
	
/*	for(int i=1; i<=Maxi; i++){
		pw++;
		while(a[now] == i){
			q[tail].endt = b[now]; q[tail].hp = x[now];
			now++; tail++;
		}
		for(int j=head; j<cnte; j++){
			pw -= q[j].hp;
		}
		if(pw<=0){
			printf("Runtime Error\n%d\n", i);
			return 0;
		}
		while(q.top().endt == i){
			q.pop(); cnte--;
		}
	}*/
	printf("Accepted\n%d\n", pw);

	return 0;
}
