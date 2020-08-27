#include<bits/stdc++.h>
#define ll long long int
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;
ll max_ind,li[100000];
ll lis(ll *a,ll n){
	ll i,j;
	for(i=0;i<n;i++)
	li[i] = 1;
	
	for(i=1;i<n;i++){
		for(j=0;j<i;j++){
			if(a[i]>a[j]&&li[i]<li[j]+1){
				li[i] = li[j] + 1;
			}
		}
	}
	ll max = 0;
	for(i=0;i<n;i++){
		if(max<li[i])
		max = li[i],max_ind = i;
//		cout<<li[i]<<" ";
	}
//	cout<<endl;
	return max;
}
void print_it(ll *a,ll n){
	ll max = lis(a,n);
//	cout<<max_ind;
	vector<ll> v;
	v.push_back(a[max_ind]);
	for(ll i=max_ind-1;i>=0;i--){
		if(li[i]+1==li[max_ind] && a[i]<a[max_ind]){
			v.push_back(a[i]);
			max_ind = i;
		}
	}
	reverse(v.begin(),v.end());
	for(auto x:v)
	cout<<x<<" ";
	
}
int main(){
	ll n;
	cin>>n;
	ll a[n];
	for(ll i=0;i<n;i++) cin>>a[i];
	
	cout<<lis(a,n)<<endl;
	print_it(a,n);
	return 0;
}
