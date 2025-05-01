/*//--------------------------------->
Mohammad Abdullah
CSE,IIUC (4th semester)
30th April 2025
*///------------------------------------------------------------->
#include<bits/stdc++.h>
using namespace std;

int dim[100];
int m[100][100];
int s[100][100];

void MCO(int n){
    for(int i=1;i<=n;i++){
        m[i][i] = 0;
    }
    for(int l=2;l<=n;l++){
        for(int i=1;i<=n-l+1;i++){
            int j = l+i-1;
            m[i][j] = INT_MAX;
            for(int k=i;k<j;k++){
               int q = m[i][k] + m[k+1][j] + dim[i-1]*dim[j]*dim[k];
               if(q<m[i][j]){
                m[i][j] = q;
                s[i][j] = k;
               }
            }

        }
    }
}

void POP(int s[][100],int i,int j){
    if(i==j){
        cout<<"A"<<i;
    }else{
        cout<<"(";
        POP(s,i,s[i][j]);
        POP(s,s[i][j]+1,j);
        cout<<")";
    }
}
//Using Recursive
int RecursiveMatrixChain(int m[][100],int i,int j){
    if(i==j){
        return 0;
    }
    m[i][j] = INT_MAX;
    for(int k=i;k<j;k++){
        int q = RecursiveMatrixChain(m,i,k) + RecursiveMatrixChain(m,k+1,j) + dim[i-1] * dim[j] * dim[k];
        if(q<m[i][j]){
            m[i][j] = q;
        }
    }
    return m[i][j];
}

//Using DP
int LOOKUP_CHAIN(int i,int j){

    if (m[i][j] <INT_MAX) {return m[i][j];}
    if(i==j){ m[i][j] = 0;}
    else{
        for(int k=i;k<j;k++){
            int q = LOOKUP_CHAIN(i,k) + LOOKUP_CHAIN(k+1,j) + dim[i-1]*dim[j]*dim[k];
            if(q<m[i][j]){
                m[i][j] = q;
            }
        }
    }
    return m[i][j];
}
int MEMOIZED_MATRIX_CHAIN(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            m[i][j] = INT_MAX;
        }
    }

    return LOOKUP_CHAIN(1,n);
}

int main(){

   
    int n;
    cin>>n;
    for(int i=0;i<=n;i++){
        cin>>dim[i];
    }
    MCO(n);
    POP(s,1,n);
    cout<<endl;
    cout<<MEMOIZED_MATRIX_CHAIN(n);


    return 0;
}