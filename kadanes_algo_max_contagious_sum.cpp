#include<bits/stdc++.h>
using namespace std;
/*
14
74 -72 94 -53 -59 -3 -66 36 -13 22 73 15 -52 75

74 2 96 43 0 0 0 36 23 45 118 123 138 
*/
int maxSubarraySum(int arr[], int n){
	int i;
	int d=0;
	int max_o=-1*INT_MAX;
	for(i=0;i<n;i++){
		if(arr[i]<0){
			d++;
		}
		if(max_o<arr[i]) max_o=arr[i];
		
	}
	if(d==n){
		return max_o;
	}
   	int max=0;
   	int max_p=0;
   	for(i=0;i<n;i++){
	   	max_p = max_p + arr[i];
	   	if(max_p<0){
	   		max_p=0;
		}
		if(max<max_p){
			max = max_p;
		}
	}
    return max;
}
int main(){
int t,n;
cin>>t;
while(t--){
cin>>n; 
int a[n];
	for (int i=0;i<n;i++){
		cin>>a[i]; 
	}
	cout<<maxSubarraySum(a,n)<<endl;
  }
}
