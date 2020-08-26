#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
//	this is iterative method for finding the no. of unique paths 
// from any point to end of the matrix[n][m]
// the no. can fetched from the dp matrix formed
	ll n,m,i,j;
	cin>>n>>m;
	ll dp[n][m];
	memset(dp,0,sizeof(dp));
	for(i=0;i<n;i++){
		dp[i][m-1] = 1;
	}
	for(j=0;j<m;j++){
		dp[n-1][j] = 1;
	}
	for(i=n-2;i>=0;i--){
		for(j=m-2;j>=0;j--){
			dp[i][j] = dp[i+1][j] + dp[i][j+1];
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			cout<<dp[i][j]<<" ";
		}cout<<endl;
	}
	
}
