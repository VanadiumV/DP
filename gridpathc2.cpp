#include<bits/stdc++.h>
using namespace std;


  int grid[n][m];//input matrix
  int dp[n][m];  // every value here is -1
  
  //subproblem: f(i,j) represents minimum sum path from (0,0) to (i,j)
  
  int f(int i,int j){ //
  if(i<0 || j<0){// moving outside the grid // not allowed
      return INF;
  }
  if(i==0 && j== 0)// reached the destination
  return grid[0][0];
  
  if(dp[i][j] !=-1)// this state has been calculated before
  return dp[i][j];
  
  //state never calculated before 
  dp[i][j]= grid[i][j]+min(f(i,j-1),f(i-1,j));
  return dp[i][j];
  }
   
   
   void solve(){
       cout<<f(n-1,m-1)<<nline;
   }
   
   int main(){
       solve();
       return 0;
   }
