#include<bits/stdc++.h>
#define ll long long int
#define INF 100
using namespace std;
int main(){
//	this program calculate the minimum cost to traverse from 1st row to last row
// The allowed movements here is down , down-left & down-right
	ll n,m;
	cin>>n>>m;
	ll a[n][m];
	ll dp[n+1][m+2];
	memset(dp,0,sizeof(dp));
	ll i,j;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	
	for(i=1;i<=m;i++){
		dp[n][i] = a[n][i];
	}
	for(i=1;i<=n;i++){
		dp[i][0] = INF;
		dp[i][m+1] = INF;
	}
	
	for(i=n-1;i>=1;i--){
		for(j=1;j<=m;j++){
			ll c = min(dp[i+1][j],min(dp[i+1][j+1],dp[i+1][j-1]));
			dp[i][j] = a[i][j] + c;
//			cout<<c<<endl;
		}
	}
	
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
		
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	

}
