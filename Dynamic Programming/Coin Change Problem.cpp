#include<iostream>

using namespace std;

int coinChangeDP(int S[],int N,int m,int **dp){
	if(m<=0 && N!=0) return dp[m][N]=0;
	if(N==0) return dp[m][N]=1;
	if(N<0) return dp[m][N]=0;
	if(dp[m][N]!=-1) return dp[m][N];
	
	return dp[m][N]=coinChangeDP(S,N-S[m-1],m,dp)+coinChangeDP(S,N,m-1,dp);
}

int coinChange(int S[],int N,int m){
	int **dp;
	dp=new int*[m+1];
	
	for(int i=0;i<m+1;i++){
		dp[i]=new int[N+1];
	}
	
	for(int i=0;i<m+1;i++){
		for(int j=0;j<N+1;j++){
			dp[i][j]=-1;
		}
	}
	return coinChangeDP(S,N,m,dp);
}


int main(){
	int S[] = {1,2,3};
	int N=4;
	int m=sizeof(S)/sizeof(S[0]);
	cout<<coinChange(S,N,m)<<endl;
	return 0;
}
