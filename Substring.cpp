#include<iostream>
 
using namespace std; 
  
void subString(string s, int n)  
{ 
    for (int i = 1; i <= n; i++)  
    {     
        for (int j = 0; j <= n - i; j++)  
        { 
            int k = j + i - 1;             
            for (int l = j; l <= k; l++)  
                cout << s[l]; 
              
            cout << endl; 
        } 
    } 
} 
  
int main()  
{ 
    string s = "abcd"; 
    subString(s, s.length()); 
    return 0; 
} 

