/*//--------------------------------->
Mohammad Abdullah
CSE,IIUC (4th semester)
29th April 2025
*///------------------------------------------------------------->
#include<iostream>
using namespace std;
//Time Complexcity: O(n)
void InsertionSort(int arr[],int n);


int main(){
    int arr[100];
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }   
    InsertionSort(arr,n);    
    for(int i=1;i<=n;i++){
       cout<<arr[i]<<" ";
    }                                                                          
    return 0;
}

void InsertionSort(int arr[],int n){
    arr[0] = INT64_MIN;  
    for(int k=2;k<=n;k++){
        int temp = arr[k];
        int ptr = k-1;
        while(temp<arr[ptr]){
            arr[ptr+1] = arr[ptr];
            ptr=ptr-1;
        }
        arr[ptr+1] = temp;
    }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
}


           