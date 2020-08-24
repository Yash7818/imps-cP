#include<bits/stdc++.h>
#define ll long long int
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;
int main(){
	ll n,m;
	cin>>n>>m;
	ll a[n];
	rep(i,n) cin>>a[i];
	bool dp[n+1][m+1];
	dp[0][0] = true;
	for(ll i=1;i<m;i++) dp[0][i] = false;
	
	for(ll i=0;i<n;i++){
		for(ll j=0;j<=m;j++){
			if(j<a[i]){
				dp[i][j] = dp[i-1][j];
			}
			else{
				ll need = j - a[i];
				if(dp[i-1][j] || dp[i-1][need]){
					dp[i][j] = true;
				}
				else{
					dp[i][j] =false;
				}
			}
		}
	}
	bool ans = dp[n][m];
	
	if(ans)
	cout<<"YES"<<endl;
	else{
		cout<<"NO"<<endl;
	}
	
	for(ll i=0;i<=n;i++){
		for(ll j=0;j<=m;j++){
			if(dp[i][j])
			cout<<"1"<<" ";
			else
			cout<<"0"<<" ";
		}
		cout<<endl;
	}
}
