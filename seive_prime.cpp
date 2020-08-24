#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll dp[10001];
ll s[10001];
void seive(){
	ll i,j;
	for(i=3;i<=10000;i+=2){
		s[i] = 1;
	}
	
	for(i=3;i<=10000;i+=2){
		if(s[i]==1){
			for(j = i*i;j<=10000;j+=i){
				s[j] = 0;
			}
		}
		
	}
	s[2]=1;
	s[0]=s[1]=0;
}
int main(){
	ll t,n;
	ll i;
	seive();
	cin>>t;
//	while(t--){
//		cin>>n;
//		cout<<dp[n]<<endl;
//	}
for(i=1;i<10000;i++){
	if(s[i]){
		cout<<i<<" ";
	}
}
}
