/*//--------------------------------->
Mohammad Abdullah
CSE,IIUC (4th semester)
30th April 2025
*///------------------------------------------------------------->
#include<bits/stdc++.h>
using namespace std;
const int mx = 1e5+123;
int arr[mx];
int n,k;
int dp[mx];
int solve(int i){

   if(i==n) return 0;

   if(dp[i]!=-1) return dp[i];

   int ret1=INT_MAX;
   dp[i] = INT_MAX;
   for(int j=1;j<=k;j++){
    if(i+j<=n) ret1 = abs(arr[i]-arr[i+j]) + solve(i+j);
    dp[i] = min(dp[i],ret1);
   }
   
   
   return dp[i];


}

int main(){
    
    cin>>n>>k;
   
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<solve(1)<<endl;



}