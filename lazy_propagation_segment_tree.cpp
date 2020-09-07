#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll a[100000];
ll st[400000];
ll lazy[400000];


void build(ll si,ll ss,ll se){
	if(ss==se){
		st[si]= a[ss];
		return;
	}
	ll mid = (ss+se)/2;
	build(2*si,ss,mid);
	build(2*si+1,mid+1,se);
	st[si]= st[2*si]+ st[2*si+1];
}

void update(ll si,ll ss ,ll se,ll qs,ll qe,ll x){
	ll dx;
	if(lazy[si]!=0){
		dx = lazy[si];
		lazy[si] = 0;
		st[si] += (se-ss+1)*dx;
		if(ss!=se){
			lazy[2*si]+=dx;
			lazy[2*si+1]+=dx;
		}
	}
	
	if(ss>qe || se<qs || ss>se){
		return;
	}
	if(ss>=qs && qe>=se){
		st[si] = (se-ss+1)*x;
//		lazy[si] += x;
		if(ss!=se){
			lazy[2*si] += x;
			lazy[2*si+1] += x;
		}
		return;
	}
	ll mid = (ss+se)/2;
	
	update(2*si,ss,mid,qs,qe,x);
	update(2*si+1,mid+1,se,qs,qe,x);
	
	st[si] = st[2*si] + st[2*si+1];
}

ll query(ll si,ll ss,ll se,ll qs,ll qe){
	ll dx;
	if(lazy[si]!=0){
		dx = lazy[si];
		lazy[si] = 0;
		st[si] += (se-ss+1)*dx;
		if(ss!=se){
			lazy[2*si] += dx;
			lazy[2*si+1] += dx;
		}
	}
	
	if(ss>qe || se<qs) return 0;
	
	if(ss>=qs && qe>=se){
		return st[si];
	}
	
	ll mid = (ss+se)/2;
	ll l = query(2*si,ss,mid,qs,qe);
	ll r = query(2*si+1,mid+1,se,qs,qe);
	
	return (l+r);
}


int main(){
	
	ll n,q,l,r,x,c,i;
	cin>>n>>q;
	for(i=1;i<=n;i++) cin>>a[i];
	build(1,1,n);
	for(i=0;i<q;i++){
		cin>>c;
		if(c==1){
			cin>>l>>r>>x;
			update(1,1,n,l,r,x);
		}
		else{
			cin>>l>>r;
			cout<<query(1,1,n,l,r);
		}
		
	}
	
	
	
	
}
