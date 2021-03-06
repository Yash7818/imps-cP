#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
	/*
	
	check from behind if j-curr_ele bit is set
	if it is then set the current bit
	
	A = {2,5,3,4}  M =12
	
	dp[] = {1,0,0,0,0,0,0,0,0,0,0,0,0]
	curr_ele = 2 ---->  dp[] = {1,0,1,0,0,0,0,0,0,0,0,0,0}
	curr_ele = 5 ---->  dp[] = {1,0,1,0,1,0,1,0,0,0,0,0,0}
	curr_ele = 3 ---->  dp[] = {1,0,1,1,1,1,1,1,0,1,0,0,0}
	curr_ele = 4 ---->  dp[] = {1,0,1,1,1,1,1,1,1,1,1,1,1}
	
	
	ultimatly if mth bit is set then m can be formed with A subset
	
	
	*/
	
	ll m,n;
	cin>>n>>m;
	ll a[n],i,j;
	ll dp[m+1];
	memset(dp,0,sizeof(dp));
	for(i=0;i<n;i++)
	cin>>a[i];
	dp[0]=1;
	for(i=0;i<n;i++){
		ll cur_ele = a[i];
		for(j=m;j>=cur_ele;j--){
			if(dp[j] || dp[j-cur_ele]==0){
				continue;
			}
			else
			dp[j] = cur_ele;
		}
//		cout<<dp[cur_ele]<<endl;
	}
	for(j=0;j<m+1;j++){
		cout<<dp[j]<<" ";
	}
	
	if(dp[m])
	cout<<"YES"<<endl;
	else
	cout<<"NO"<<endl;
	
	
	//	for printing the subset which forms the sum m
	if(dp[m]==0)
	cout<<"-1"<<endl;
	else{
		i = m;
		while(i!=0&&dp[i]!=0){
			cout<<dp[i]<<" ";
			i = i - dp[i];
		}
	}

}

