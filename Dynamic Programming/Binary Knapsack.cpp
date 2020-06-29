#include<iostream>

using namespace std;

int knapsackDP(int val[],int wt[],int W,int n,int **dp){
	if(n==0 || W<=0) return dp[n][W]=0;
	if(wt[n]>W) return dp[n][W]=knapsackDP(val,wt,W,n-1,dp);
	if(dp[n][W]!=-1) return dp[n][W];
	
	return dp[n][W]=max(val[n]+knapsackDP(val,wt,W-wt[n],n-1,dp),knapsackDP(val,wt,W,n-1,dp));
}

int knapsack(int val[],int wt[],int W,int n){
	int **dp;
	dp=new int*[n];
	
	for(int i=0;i<n;i++){
		dp[i]=new int[W+1];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<W+1;j++){
			dp[i][j]=-1;
		}
	}
	return knapsackDP(val,wt,W,n-1,dp);
}

int main(){
	int val[] = {60,100,120};
	int wt[] = {10,20,30};
	int W = 50;
	int n= sizeof(val)/sizeof(val[0]);
	cout<<knapsack(val,wt,W,n)<<endl;
	return 0;
}
