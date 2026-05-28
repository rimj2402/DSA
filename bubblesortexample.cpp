#include<iostream >
using namespace std;

void swap(int &a, int &b){
    int temp=a;
    a=b;
    b=temp;
}


void bubblesort(int arr[],int n){
    for (int i=0; i<n-1 ; i++){
        for(int j=0 ; j<n-i-1 ; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main(){
    int n,arr[10];
    // cout<<"enter number of elements: "<<endl;
    cin>>n;
    // cout<<"enter array elements:"<<endl;

    for(int i=0; i<n;i++){
        cin>>arr[i];
    }
    bubblesort(arr,n);
    cout<<"sorted array is: "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}