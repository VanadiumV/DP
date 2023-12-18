#include<bits/stdc++.h>
using namespace std;


  int grid[n][m];//input matrix
  int dp[n][m];  // every value here is -1
  
  //subproblem: f(i,j) represents minimum sum path from (i,j) to (n-1,m-1)
  
  int f(int i,int j){ //
  if(i>=n || j>=m){// moving outside the grid // not allowed
      return INF;
  }
  if(i==n-1 && j== m-1)// reached the destination
  return grid[n-1][m-1];
  
  if(dp[i][j] !=-1)// this state has been calculated before
  return dp[i][j];
  
  //state never calculated before 
  dp[i][j]= grid[i][j]+min(f(i,j+1),f(i+1,j));
  return dp[i][j];
  }
   
   
   void solve(){
       cout<<f(0,0)<<nline;
   }
   
   int main(){
       solve();
       return 0;
   }
