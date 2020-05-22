#include <iostream>
using namespace std;
 
// Given a array, write a recursive function that will add 
//sum of all its previous number to each index 
// 1,2,3,4,5,6
// 1,3,6,10,15,21
 
 
 
int recursion(int arr[], int i) {
	if(i == 0)  {
		return arr[0];
	}
	arr[i] = arr[i] + recursion(arr, i-1); 
	return arr[i];
}
 
// 1 -> 2 + 1, 3 + 3, 4 + 6, 5 + 10, 6 + 15
// Stack: main() ,6 + rec(5),5 + rec(4), 4 + rec(3), 3 + rec(2), 2 + rec(1), rec(0)
int main() {
	// your code goes here
	int arr[] = {1, 2, 3, 4, 5, 6};
	int size = sizeof(arr)/sizeof(arr[0]);
	recursion(arr, size-1);
	for(int i = 0; i < size; i++) 
		cout << arr[i] << " " ;
	cout << endl;
	return 0;
}
