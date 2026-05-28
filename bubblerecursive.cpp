#include<iostream>
using namespace std;

void swap(int &a, int&b){
    int temp=a;
    a=b;
    b=temp;
}

void bubble(int arr[],int n){
    if(n==1){
        return;
    }
    for(int i=0; i<n-1; i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
    bubble(arr,n-1);
}

int main(){
    int n,arr[10];
    cin>>n;
    for(int i=0; i<n;i++){
        cin>>arr[i];
    }
    bubble(arr ,n);
    cout<<"sorted array is: "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    
}