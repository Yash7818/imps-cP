#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
	ll t,a,b,c,d,i;
	cin>>t;
	while(t--){
		ll e = 0;
		cin>>a>>b>>c>>d;
		ll v[4];
		v[0] = a;
		v[1] = b;
		v[2] = c;
		v[3] = d;
		if(a<=0||b<=0||c<=0||d<=0){
			e++;
		}
//		cout<<e;
		if(e==0){
			cout<<"No"<<endl;
			continue;
		}
		for(i = 1;i<16;i++){
			ll l = i;
			ll j = 0;
			ll c = 0;
			while(l>0&&j<4){
				ll x = l%2;
				c = c + v[j]*x;
				l = l/2;
				j++;
			}
			if(c==0){
				break;
			}
		}
		if(i>=16){
			cout<<"No"<<endl;
		} else{
			cout<<"Yes"<<endl;
		}
	}
}
