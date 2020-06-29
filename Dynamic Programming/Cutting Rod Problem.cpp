#include<iostream>

using namespace std;


int cutRodDP(int price[],int N){
	int dp[N+1];
	dp[0]=0;
	for(int i=1;i<=N;i++){
		int max_val=INT_MIN;
		for(int j=0;j<i;j++){
			max_val = max(max_val,price[j]+dp[i-j-1]);
		}
		dp[i]=max_val;
	}
	return dp[N];
}


int main(){
	int price[] = {1,5,8,9,10,17,17,20};
	int N=sizeof(price)/sizeof(price[0]);
	cout<<cutRodDP(price,N)<<endl;
	return 0;
}
