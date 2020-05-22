#include<iostream>

using namespace std;

int length(char* s)
{
	if(*s=='\0'){
		return 0;
	}
	return length(s+1)+1;
}

int main()
{
	char s[]="Rahul Ram";
	cout<<length(s)<<endl;
	return 0;
}
