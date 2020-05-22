#include<iostream>

using namespace std;

void last_char_index(string s,char c,int i)
{
	if(i==-1){
		cout<<"No such character"<<endl;
		return;
	}
	if(s[i]==c){
		cout<<"The character's last occurrence is at index "<<i<<endl;
	}
	else{
		last_char_index(s,c,i-1);
	}
}



int main()
{
	string s="Swarnendu";
	last_char_index(s,'w',s.length()-1);
	return 0;
}
