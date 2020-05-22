#include <bits/stdc++.h>

using namespace std;

void merge(int a[],int st,int en){
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
	while(i!=n && j!=m){
		if(le[i]<ri[j]){
			a[k]=le[i];
			i++;
			k++;
		}
		else{
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
}
void mergeSort(int a[],int st,int en){
	if(st<en){
		int mid=(st+en)/2;
		mergeSort(a,st,mid);
		mergeSort(a,mid+1,en);
		merge(a,st,en);
	}
	if(st==en) return;
}
int main() {
	int a[]={1,3,2,4,8,7,6,5};
	int size=8;
 
	mergeSort(a,0,size-1);
	for(int i=0;i<size;i++) cout<<a[i]<<" "; 
}
