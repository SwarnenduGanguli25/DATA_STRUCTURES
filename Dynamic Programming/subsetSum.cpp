#include<iostream>

using namespace std;

bool subsetSumDP(int arr[],int sum,int n,int **dp){
	if(sum==0) return dp[n][sum]=true;
	if(n==0 && sum!=0) return dp[n][sum]=false;
	if(dp[n][sum]!=-1) return dp[n][sum];
	
	return dp[n][sum]=subsetSumDP(arr,sum-arr[n],n-1,dp) || subsetSumDP(arr,sum,n-1,dp);
}

bool subsetSum(int arr[],int sum,int n){
	int **dp;
	dp=new int*[n];
	
	for(int i=0;i<n;i++){
		dp[i]=new int[sum+1];
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<sum+1;j++){
			dp[i][j]=-1;
		}
	}
	return subsetSumDP(arr,sum,n-1,dp);
}

int main(){
	int arr[] = {3,34,4,12,5,2};
	int sum;
	cout<<"Enter the sum:"<<endl;
	cin>>sum;
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<subsetSum(arr,sum,n)<<endl;
	return 0;
}
