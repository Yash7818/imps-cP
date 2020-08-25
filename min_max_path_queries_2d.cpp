#include<bits/stdc++.h>
#define ll long long int
//#define INF 100
using namespace std;
int main(){
//	This program is for finding the minimum cost path to reach at the end from any point.
// This is for when only down and right movement is allowed.
	ll n,m,i,j;
	cin>>n>>m;
	ll a[n][m];
	ll dp[n+1][m+1];
	
	ll INF = INT_MAX;
	
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			cin>>a[i][j];
			if(j==m-1){
				dp[i][m] = INF;
			}
			if(i==n-1){
				dp[n][j] = INF;
			}
			dp[i][j]=0; 
		}
	}
	dp[n][m] = INF;
	dp[n][m-1] = 0;
	dp[n-1][m] = 0;


	for(i=n-1;i>=0;i--){
		for(j=m-1;j>=0;j--){
			ll c = min(dp[i+1][j],dp[i][j+1]);
			dp[i][j] = a[i][j] + c;
		}
	}
	
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	
	
	
}
