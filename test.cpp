#include<bits/stdc++.h>
using namespace std;
long long n,k;
bool b[1000000005];
void er(){
	for(long long i=2;i<=sqrt(n);i++){
		long long y=i;
		for(long long j=1;j<k;j++){
			y*=i;
		}
		if(y<=n) b[y]=1;
		else continue;
//		cout<<i<<" "<<y<<endl;
		for(long long j=1;j<=n;j++){
			y*=i;
			if(y<=n) b[y]=1;
			else break;
		}
	}
	return ;
}
int main()
{
//	freopen("power.in","r",stdin);
//	freopen("power.out","w",stdout);
	cin>>n>>k;
	if(k==1){
		cout<<n;
		return 0;
	} 
	er();
	long long sum=1;
	for(long long i=2;i<=n;i++){
		if(b[i]==1) {
			sum++;
//			cout<<i<<" ";
		}
	}
//	cout<<endl;
	cout<<sum;
	return 0;
}
