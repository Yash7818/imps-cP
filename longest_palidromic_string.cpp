#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
//	A matrix table is formed y-axis is no. of elements in string 
// x-axis is the end index of that string
// it works as appending two same element on the palindromic string this final is palindromic.
// in lookup table the longest can be found by the largest index having 1 in an array.
	ll n,i,j;
	cin>>n;
	char s[n+1];
	for(i=1;i<=n;i++){
		cin>>s[i];
	}
//	cin>>s;
//	n = s.length();
	
	ll dp[n+1][n+1];
	memset(dp,0,sizeof(dp));
	for(i=0;i<=n;i++){
		dp[0][i] = 1;
		dp[1][i] = 1;
	}
	
	for(i=2;i<=n;i++){
		for(j=i;j<=n;j++){
			if(s[j]==s[j-i+1] && dp[i-2][j-1]==1){
				dp[i][j] = 1;
			}
			else{
				dp[i][j] = 0;
			}
		}
	}
	
	for(i=0;i<=n;i++){
		for(j=0;j<=n;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
}
