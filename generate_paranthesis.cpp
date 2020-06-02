#include<bits/stdc++.h>

using namespace std;

void generate_paranthesis(string out,int op_rem,int cl_rem){
	if(op_rem==0 and cl_rem==0){
		cout<<out<<endl;
		return;
	}
	
	if(op_rem>0)
	generate_paranthesis(out+"(",op_rem-1,cl_rem);
	
	if(cl_rem>op_rem)
	generate_paranthesis(out+")",op_rem,cl_rem-1);
}

int main(){
	int n;
	cout<<"Enter the count of paranthesis"<<endl;
	cin>>n;
	generate_paranthesis("",n,n);
}
