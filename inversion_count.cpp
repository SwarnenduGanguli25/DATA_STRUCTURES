#include <iostream>
using namespace std;

int merge(int a[],int st,int en){
	int mid=(st+en)/2;
	int n=mid-st+1;
	int m=en-mid;
	int le[mid-st+1];
	int ri[en-mid];
	for(int i=0;i<n;i++){
	le[i]=a[st+i];
	}
	for(int i=0;i<m;i++)ri[i]=a[i+mid+1];
	int i=0,j=0;
	int k=st;
	int co=0;
	while(i!=n && j!=m){
		if(le[i]<ri[j]){
			a[k]=le[i];
			i++;
			k++;
		}
		else{
			co=co+n-i;
			a[k]=ri[j];
			j++;
			k++;
		}
	}
	while(i!=n){
		a[k]=le[i];
		i++;
		k++;
	}
	while(j!=m){
		a[k]=ri[j];
		j++;
		k++;
	}
	return co;
}
int mergeSort(int a[],int st,int en){
	if(st<en){
		int mid=(st+en)/2;
		int lc=mergeSort(a,st,mid);
		int rc=mergeSort(a,mid+1,en);
		int merc=merge(a,st,en);
		return lc+rc+merc;
	}
	return 0;
}
	
int main(){
	// your code goes here
	int a[]={2,3,8,6,1};
	int b=mergeSort(a,0,4);
	cout<<b<<endl;
	return 0;
}
