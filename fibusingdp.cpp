#include <iostream>
using namespace std;


int fib(int n,vector<int>&memo){
    if(n<=1){
        memo[n]=n;
        return memo[n];
    }
    
    if(memo[n]!=-1){
        return memo[n];
    }
    
    memo[n]=fib(n-1,memo)+fib(n-2,memo);
    return memo[n];
}
int main() {
	// your code goes here
	int n=1000;
	vector<int>memo(n+1,-1);
	cout<<fib(n,memo)<<endl;
	return 0;
}
