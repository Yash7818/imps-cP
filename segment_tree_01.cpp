#include<bits/stdc++.h>
#define ll long long int
#define maxN 500001
using namespace std;
int a[maxN];
ll st[maxN];
void buildTree(ll si,ll ss,ll se){
	if(ss==se){
		st[si] = a[ss];
		return;
	}
	ll mid = (ss+se)/2;
	buildTree(2*si,ss,mid);
	buildTree(2*si+1,mid+1,se);
	st[si] = st[2*si] + st[2*si+1];
}

void update(ll si,ll ss,ll se,ll qi){
	if(ss==se)
	{
		st[si] = a[ss];
		return;
	}

	ll mid = (ss+se)/2;

	if(qi<=mid){
		update(2*si,ss,mid,qi);
	}
	else{
		update(2*si+1,mid+1,se,qi);
	}
	st[si] = st[2*si] + st[2*si+1];
}
ll query(ll si,ll ss,ll se,ll qs,ll qe){
	if(qs>se || qe<ss){
		return 0;
	}

	if(ss>=qs && se<=qe){
		return st[si];
	}

	ll mid = (ss+se)/2;
	ll l = query(2*si,ss,mid,qs,qe);
	ll r = query(2*si+1,mid+1,se,qs,qe);

	return l + r;
}
int main(){
	ll n,q,c,x,y;
	cin>>n>>q;
	memset(a,0,sizeof(a));
	buildTree(1,1,n);
	while(q--){
		cin>>c>>x;
		if(c==1){
		a[x] = 2*a[x] + 1;
		update(1,1,n,x);
		}
		else if(c==2){
		a[x] = a[x]/2;
		update(1,1,n,x);
		}
		else{
			cin>>y;
			cout<<query(1,1,n,x,y)<<endl;
		}
	}
}


