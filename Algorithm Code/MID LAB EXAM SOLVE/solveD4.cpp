#include<bits/stdc++.h>
using namespace std;

int dp[100][100];
int solve(int arr[][100],int i,int j,int n,int m){
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(i == n && j==m){
        return arr[i][j];
    }
    int r1=INT_MAX,r2=INT_MAX;
    if(i+1<=m){
            r1 =  arr[i][j] + solve(arr,i+1,j,n,m);
    }
    if(j+1<=n){
           r2 = arr[i][j] + solve(arr,i,j+1,n,m);
    }
    dp[i][j] = min(r1,r2);
    return dp[i][j];


}

int main(){
    int n,m;
    memset(dp,-1,sizeof(dp));

    int arr[100][100];
    cin>>n>>m;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    cout<<solve(arr,0,0,n-1,m-1);



}