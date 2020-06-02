#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int slow_power(int n,int p){
	if(p==0) return 1;
	return n*slow_power(n,p-1);
}

int fast_power(int n,int p){
	if(p==0) return 1;
	int ans=fast_power(n,p/2);
	ans*=ans;
	if(p%2==1) ans*=n;
	return ans;
}

int main(){
	int n,p;
	cin>>n>>p;
	cout<<slow_power(n,p)<<endl;
	cout<<fast_power(n,p)<<endl;
	return 0;
}
