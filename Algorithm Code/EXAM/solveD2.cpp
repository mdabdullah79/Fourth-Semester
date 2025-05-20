#include<bits/stdc++.h>
using namespace std;
int shift = 0;
void InsertionSort(int arr[],int n){
    for(int k=1;k<n;k++){
        int cur = arr[k];
        int prev = k-1;
        while(prev>=0 && arr[prev]>cur){
            arr[prev+1] = arr[prev];
            prev--;
            shift++;
        }
        arr[prev+1] = cur;
    }
}

int main(){
    int arr[100];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    InsertionSort(arr,n);
    cout<<"Sorted Array: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"Number of Shift: "<<shift<<endl;


    return 0;

}