#include<bits/stdc++.h>
#define ll long long int
using namespace std;
vector<ll> v;
// This algo can only be used to find length of sequence not the sequence
ll lis(ll *a,ll n){
	v.push_back(a[0]);
	
	for(ll i=1;i<n;i++){
		if(v.back()<a[i])
		{
			v.push_back(a[i]);
		}
		else{
			ll b = lower_bound(v.begin(),v.end(),a[i]) - v.begin();
			v[b] = a[i];
		}
	}
	ll max = v.size();
	
	return max;
}
int main(){
	ll n;
	cin>>n;
	ll a[n];
	for(ll i=0;i<n;i++) cin>>a[i];
	
	cout<<lis(a,n)<<endl;
	
	for(auto x: v)
	cout<<x<<" ";
}
