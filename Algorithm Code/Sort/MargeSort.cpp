#include<bits/stdc++.h>
using namespace std;
int n;
const int mx = 1e5+123;
int arr[mx];
void Marge(vector<int> &arr, int st,int mid,int end){
   vector<int> temp;
   int i = st;
   int j = mid+1;
   while(i<=mid && j<=end){
    if(arr[i]<=arr[j]){
        temp.push_back(arr[i]);
        i++;
    }else{
        temp.push_back(arr[j]);
        j++;
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
    arr[i+st] = temp[i];
   }
  
}

void MargeSort(vector<int> &arr, int st,int end){
    if(st<end){
        int mid = st + (end-st)/2;
        MargeSort(arr,st,mid);
        MargeSort(arr,mid+1,end);
        Marge(arr,st,mid,end);
    }
}
int main(){

   vector<int> arr;
   int n;
   cin>>n;
   for(int i=0;i<n;i++){
    int x;
    cin>>x;
    arr.push_back(x);
   }
   MargeSort(arr,0,(arr.size()-1));
   for(int val:arr){
    cout<<val<<" ";
   }

}