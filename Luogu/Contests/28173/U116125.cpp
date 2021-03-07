#include<bits/stdc++.h>
using namespace std;

int nx, ny, ma[55][55];

extern "C" bool move_to(char position){
	switch(position){
		case 'W':
			if(ma[nx-1][ny]==0){
				nx--;
				return 1;
			}
			else return 0;
		case 'A':
			if(ma[nx][ny-1]==0){
				ny--;
				return 1;
			}
			else return 0;
		case 'S':
			if(ma[nx+1][ny]==0){
				nx++;
				return 1;
			}
			else return 0;
		case 'D':
			if(ma[nx][ny+1]==0){
				ny++;
				return 1;
			}
			else return 0;
	}
	return 0;
}
/*
extern "C" string find_out_map(int X,int Y,int N){
	int mapp[550][550], posx=X, posy=Y;
	memset(mapp, 0, sizeof(mapp));
	int q[550][2], front, rear=1;
	q[0][0]=X; q[0][1]=Y;
	while(front!=rear){
		if(move_to("W")){
			q[rear][0]=posx-1;
			q[rear][1]=posy;
			rear++;
		}
	}
}
*/

extern "C" string find_out_map(int X,int Y,int N){
	int mapp[55][55], posx=X, posy=Y;
	bool vis[55][55];
	char mode[5]="WASD";
	int q[55][4], top=1;
	string ans;
	memset(mapp, 0, sizeof(mapp));
	memset(vis, 0, sizeof(vis));
	memset(q, 0, sizeof(q));
	mapp[posx][posy]=1;
	vis[posx][posy]=true;
	q[0][0]=posx; q[0][1]=posy; q[0][2]=0;
	while(top){
		posx=q[top-1][0]; posy=q[top-1][1];
		if(posx-1>=0 && q[top-1][2]<=0 && !vis[posx-1][posy] && move_to('W')){
			posx -= 1;
			q[top-1][2]=1;
			mapp[posx][posy]=1;
			vis[posx][posy]=true;
			q[top][0]=posx; q[top][1]=posy;
			q[top][3]=0;
			top++;
			continue;
		}
		if(posy-1>=0 && q[top-1][2]<=1 && !vis[posx][posy-1] && move_to('A')){
			posy -= 1;
			q[top-1][2]=2;
			mapp[posx][posy]=1;
			vis[posx][posy]=true;
			q[top][0]=posx; q[top][1]=posy;
			q[top][3]=1;
			top++;
			continue;
		}
		if(posx+1<N && q[top-1][2]<=2 && !vis[posx+1][posy] && move_to('S')){
			posx += 1;
			q[top-1][2]=3;
			mapp[posx][posy]=1;
			vis[posx][posy]=true;
			q[top][0]=posx; q[top][1]=posy;
			q[top][3]=2;
			top++;
			continue;
		}
		if(posy+1<N && q[top-1][2]<=3 && !vis[posx][posy+1] && move_to('D')){
			posy += 1;
			q[top-1][2]=4;
			mapp[posx][posy]=1;
			vis[posx][posy]=true;
			q[top][0]=posx; q[top][1]=posy;
			q[top][3]=3;
			top++;
			continue;
		}
		move_to(mode[(q[top-1][3]+2)%4]);
		top--;
	}
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(vis[i][j]) ans+='0';
			else ans+='1';
		}
	}
	return ans;
}

int main(){
	freopen("data.in", "r", stdin);	
	int n;
	scanf("%d %d %d", &nx, &ny, &n);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%d", &ma[i][j]);
		}
	}
	cout << find_out_map(nx, ny, n);

	return 0;
}
