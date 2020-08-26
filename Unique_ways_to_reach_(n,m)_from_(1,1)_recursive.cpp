#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll n,m;
ll dp[101][101];

ll fill(ll x,ll y){
	if(x>n || y>m || x<1 || y<1){
		return 0;
	}
	
	if(x==n && y==m){
		dp[x][y] = 1;
		return 1;
	}
	
//	 if calculated already
	if(dp[x][y]!=-1){
	return dp[x][y];
	}
	dp[x][y] = fill(x+1,y) + fill(x,y+1);
	
	return dp[x][y];
}

int main(){
	memset(dp,-1,sizeof(dp));
	cin>>n>>m;
	cout<<fill(1,1)<<endl;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	
}
