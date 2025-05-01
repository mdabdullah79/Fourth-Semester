/*//--------------------------------->
Mohammad Abdullah
CSE,IIUC (4th semester)
30th April 2025
*///------------------------------------------------------------->
#include<bits/stdc++.h>
using namespace std;
const int mx = 1e5+123;
int arr[mx];
int n;
int dp[mx];
int solve(int i){

   if(i==n) return 0;

   if(dp[i]!=-1) return dp[i];

   int ret1=INT_MAX,ret2=INT_MAX;
   if(i+1<=n) ret1 = abs(arr[i]-arr[i+1]) + solve(i+1);
   if(i+2<=n) ret2 = abs(arr[i]-arr[i+1]) + solve(i+2);
   dp[i] = min(ret1,ret2);
   return dp[i];


}

int main(){
    
    cin>>n;
   
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<solve(1)<<endl;



}