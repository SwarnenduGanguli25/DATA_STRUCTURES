#include<iostream>

using namespace std;

int minn(int num1,int num2,int num3){
	int smt=num1<num2?(num1<num3?num1:num3):(num2<num3?num2:num3);
	return smt;
}

int editDistanceDP(string str1,string str2,int m,int n,int **dp){
	if(m==0) return dp[m][n]=n;
	if(n==0) return dp[m][n]=m;
	if(str1[m-1]==str2[n-1]) return dp[m][n]=editDistanceDP(str1,str2,m-1,n-1,dp);
	if(dp[m][n]!=-1) return dp[m][n];
	
	return dp[m][n]=1+minn(editDistanceDP(str1,str2,m,n-1,dp),editDistanceDP(str1,str2,m-1,n,dp),editDistanceDP(str1,str2,m-1,n-1,dp));
}

int editDistance(string str1,string str2,int m,int n){
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
	return editDistanceDP(str1,str2,m,n,dp);
}

int main(){
	string str1 = "SUNDAY";
	string str2 = "SATURDAY";
	int m=str1.length();
	int n=str2.length();
	cout<<editDistance(str1,str2,m,n)<<endl;
	return 0;
}
