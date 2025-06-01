#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int comparison = 0;
void Marge(vi &arr,int st,int mid,int end){
    int i = st;
    int j = mid+1;
    vi temp;
    while(i<=mid && j<=end){
        if(arr[i]<arr[j]){
            temp.push_back(arr[i]);
            i++;
            comparison++;
        }else{
            temp.push_back(arr[j]);
            j++;
            comparison++;
        }
        
    }
    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
      while(j<=end){
        temp.push_back(arr[j]);
        j++;
    }
    for(int i=0;i<temp.size();i++){
        arr[st+i] = temp[i];
    }
}

void MargeSort(vi &arr,int st,int end){
    if(st<end){
        int mid = (st+end)/2;
        MargeSort(arr,st,mid);
        MargeSort(arr,mid+1,end);
        Marge(arr,st,mid,end);
    }
}



int main(){

    int n;
    cin>>n;
    vi arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    MargeSort(arr,0,n-1);
    cout<<"Sorted Array: ";
    for(auto i:arr){
        cout<<i<<" ";
    }
    
    cout<<endl;
    cout<<"Comparison: "<< comparison;



    return 0;
}