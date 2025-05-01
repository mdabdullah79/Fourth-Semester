#include<bits/stdc++.h>
using namespace std;
int A[100];
int c[100];
int B[100];

void CountingSort(int n){
     int k = A[1];
     for(int i=1;i<=n;i++){
        k = max(k,A[i]);
     }
     for(int i=1;i<=n;i++){
        c[A[i]]++;
     }
     for(int i=1;i<=k;i++){
        c[i] = c[i]+c[i-1];
     }
     for(int j=n;j>=1;j--){
        B[c[A[j]]] = A[j];
        c[A[j]]--;

     }
     return;
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>A[i];
    }
    CountingSort(n);
    for(int i=1;i<=n;i++){
        cout<<B[i]<<" ";
    }


    return 0;
}