#include<iostream>
#include<algorithm>

using namespace std;

void remove(string &s,char c)
{
	s.erase(remove(s.begin(),s.end(),c),s.end());
}

int main()
{
	string s="SWARNENDU";
	remove(s,'U');
	cout<<s<<endl;
	return 0;
}
