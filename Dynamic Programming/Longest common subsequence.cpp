#include<iostream>

using namespace std;

int LCSDP(string str1,string str2,int m,int n,int **dp){
	if(m==0 || n==0) return dp[m][n]=0;
	if(str1[m]==str2[n]) return dp[m][n]=1+LCSDP(str1,str2,m-1,n-1,dp);
	if(dp[m][n]!=-1) return dp[m][n];
	
	return dp[m][n]=max(LCSDP(str1,str2,m-1,n,dp),LCSDP(str1,str2,m,n-1,dp));
}

int LCS(string str1,string str2,int m,int n){
	int **dp;
	dp=new int*[m+1];
	
	for(int i=0;i<m+1;i++){
		dp[i]=new int[n+1];
	}
	for(int i=0;i<m+1;i++){
		for(int j=0;j<n+1;j++){
			dp[i][j]=-1;
		}
	}
	return LCSDP(str1,str2,m,n,dp);
}

int main(){
	string str1 = "AGGTAB";
	string str2 = "GXTXAYB";
	int m=str1.length();
	int n=str2.length();
	cout<<LCS(str1,str2,m,n)<<endl;
	return 0;
}
