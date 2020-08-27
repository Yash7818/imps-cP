#include<bits/stdc++.h>
#define ll long long int
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;
ll lis(ll *a,ll n){
	ll li[n],i,j;
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
		max = li[i];
//		cout<<li[i]<<" ";
	}
//	cout<<endl;
	return max;
}
int main(){
	ll n;
	cin>>n;
	ll a[n];
	for(ll i=0;i<n;i++) cin>>a[i];
	
	cout<<lis(a,n);
	return 0;
}
