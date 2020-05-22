#include<iostream>

using namespace std;

void sort_chk(int *a,int i)
{
	if(i==0){
		cout<<"sorted"<<endl;
		return;
	}
	
	if(a[i]>a[i-1]){
		sort_chk(a,i-1);
	}
	else{
		cout<<"Not sorted"<<endl;
	}
}

int main()
{
	int a[]={1,2,3,4,5,6,7};
	int size = sizeof(a)/sizeof(a[0]);
	sort_chk(a,size-1);
	return 0;
}
