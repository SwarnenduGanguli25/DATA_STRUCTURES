#include<bits/stdc++.h>

using namespace std;

int partition(int a[],int st,int en){
	int i=st-1;
	int pivot=a[en];
	for(int j=st;j<en;j++){
		if(a[j]<pivot){
			i++;
			int temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	i++;
 
	a[en]=a[i];
	a[i]=pivot;
	return i;
}
 
 
void quicksort(int a[],int st,int en){
	if(st<en){
	int p=partition(a,st,en);
	quicksort(a,st,p-1);
	quicksort(a,p+1,en);
	}
}
int main(){
	int a[]={6,8,5,7,2,1,3,4};
	int size=8;
	quicksort(a,0,size-1);
	for(int i=0;i<8;i++) cout<<a[i]<<" ";
 
}
