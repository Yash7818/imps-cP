#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;
ll d[100001]={0};
//void dp(){
//	d[0] = 1;
//	d[1] = 2;
//	d[2] = 4;
//	for(ll i = 3;i<100001;i++){
//		d[i] = (d[i-3] + d[i-2] + d[i-1])%mod;
//	}
//}
ll dp(ll n){
	if(n==1||n==2){
		return n;
	}
	if(n==3){
		return 4;
	}
	if(d[n]!=0)
	return d[n];
	d[n] = (dp(n-1)+dp(n-2)+dp(n-3))%mod;
	return d[n];
	
}
int main(){
	ll t;
	cin>>t;
	ll n;
//	dp();
	while(t--){
		cin>>n;
		cout<<dp(n)%mod<<endl;
	}
}
