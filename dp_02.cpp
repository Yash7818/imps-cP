#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;
//ll d[2][2]={{1,1},{1,0}};
//ll m[2][2] = {{1,1},{1,0}};


void mult(ll a[2][2],ll b[2][2]){
	ll x = a[0][0]*b[0][0] + a[0][1]*b[1][0];
	ll y = a[0][0]*b[0][1] + a[0][1]*b[1][1];
	ll z = a[1][0]*b[0][0] + a[1][1]*b[1][0];
	ll s = a[1][0]*b[0][1] + a[1][1]*b[1][1];
	a[0][0] = x;
	a[0][1] = y;
	a[1][0] = z;
	a[1][1] = s;
}
//void dp(){
//	d[0] = 1;
//	d[1] = 2;
//	d[2] = 4;
//	for(ll i = 3;i<100001;i++){
//		d[i] = (d[i-3] + d[i-2] + d[i-1])%mod;
//	}
//}
void power(ll a[2][2], ll n){
	if(n==0 || n ==1){
		return;
	}
	ll m[2][2] = {{1,1},{1,0}};
	power(a,n/2);
	mult(a,a);
	if(n%2!=0){
		mult(a,m);
	}
}
ll dp(ll n){
	
	ll a[2][2] = {{1,1},{1,0}};
	if(n==0){
		return 0;
	}
	power(a,n-1);
	return a[0][0];
}
int main(){
	ll t;
	cin>>t;
	ll n;
//	dp();
	while(t--){
		cin>>n;
		cout<<dp(n+1)%mod<<endl;
	}
}

