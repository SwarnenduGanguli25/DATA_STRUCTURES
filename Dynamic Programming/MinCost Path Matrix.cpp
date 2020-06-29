#include<iostream>

using namespace std;

int minn(int num1,int num2,int num3){
	int smt=num1<num2?(num1<num3?num1:num3):(num2<num3?num2:num3);
	return smt;
}

int minCostDP(int cost[3][3],int i,int j,int m,int n,int row,int column){
	int dp[row][column];
	if(i==m && j==n) return dp[i][j]=cost[m][n];
	if(i>=row || j>=column) return dp[i][j]=INT_MAX;
	
	return dp[i][j]=cost[i][j]+minn(minCostDP(cost,i,j+1,m,n,row,column),minCostDP(cost,i+1,j,m,n,row,column),minCostDP(cost,i+1,j+1,m,n,row,column));
}


int main(){
	int cost[3][3] = {{1,2,3},{4,8,2},{1,5,3}};
	int row=3;
	int column=3;
	cout<<minCostDP(cost,0,0,2,2,row,column)<<endl;
	return 0;
}
