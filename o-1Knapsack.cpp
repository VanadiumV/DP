//ATCoder
/*
https://atcoder.jp/contests/dp/tasks/dp_d

w   3     4     5    <-
v   30    50    60

1) write BF recursion
2)write base case
3)write dp
4) use long long
*/


#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int wt[105],val[105];

long long dp[105][100005];  //3rd step


long long func(int ind,int wt_left){
    //base case
if(wt_left == 0) return 0;
if(ind < 0) return 0; // saari items consider krli but wt left in the bag

if(dp[ind][wt_left] != -1) return dp[ind][wt_left];

//Don't choose item at index
long long ans = func(ind -1,wt_left); // using ans as ll to avoid overflow bec of 10^9
//choose item at index
if(wt_left - wt[ind] >=0)
ans = max(ans,func(ind-1,wt_left-wt[ind]) +val[ind]);
return dp[ind][wt_left] = ans;
}


int main(){
    memset(dp, -1, sizeof(dp));
    int n,w;
    cin>>n>>w;
    for(int i=0;i<n;++i){
        cin>>wt[i]>>val[i];
    }
    cout<<func(n-1,w);// we'll consider elements till n-1 and w->space in the bag
}