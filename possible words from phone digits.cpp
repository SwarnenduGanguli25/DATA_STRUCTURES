#include<bits/stdc++.h>

using namespace std;

string keypad[10]={" ",".@$","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void recursion_keypad(string in,string out,int i){
	//base case
	if(i==in.size()){
		cout<<out<<",";
		return;
	}
	
	int digit=in[i]-'0';
	if(digit==0 || digit==1){
		recursion_keypad(in,out,i+1);
	}
	for(int k=0;keypad[digit][k]!='\0';k++){
		out=out+keypad[digit][k];
		recursion_keypad(in,out,i+1);
		out.pop_back();
	}
}

int main(){
	string s;
	cout<<"Enter the number"<<endl;
	cin>>s;
	recursion_keypad(s,"",0);
	return 0;
}
