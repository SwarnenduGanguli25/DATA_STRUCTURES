#include <bits/stdc++.h>
using namespace std;
#define N 5

int maze[N][N] = {
    {1, 0, 0, 0, 0},
    {1, 1, 0, 1, 0},
    {0, 1, 1, 1, 0},
    {0, 0, 0, 1, 0},
    {1, 1, 1, 1, 1}
};

int soln[N][N];
 void showPath()
 {
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<soln[i][j]<<" ";
        }
        cout<<endl;
    }
        
 }
 
  void showPathProblem()
 {
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<maze[i][j]<<" ";
        }
        cout<<endl;
    }
        
 }
 
 bool isValid(int x, int y)
 {
     if(x>=0 && x<N && y>=0 && y<N && maze[x][y]==1)
        return true;
    return false;
 }
 
 bool solveUtil(int x,int y)
 {
     if(x == N-1 && y==N-1) //destination
     {
         soln[x][y]=1;
         return true;
     }
     
     if(isValid(x,y)==true)
     {
         soln[x][y]=1;
         
         if(solveUtil(x+1,y)==true) //find Path by moving right
            return true;
        
         if(solveUtil(x,y+1)==true) //when x direction gets blocked, find Path by moving bottom
            return true;
        
        soln[x][y]=0;
        return false;
     }
     return false;
     
 }
 
 
 
bool findSolution()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            soln[i][j]=0;
        }
    }
    if(solveUtil(0,0)==false)
    {
        cout<<"No Path";
        return false;
    }
    cout<<"Problem\n";
    showPathProblem();
    cout<<"Solution\n";
    cout<<endl;
    showPath();
    return true;
}
int main() {
	
	findSolution();
	return 0;
}
