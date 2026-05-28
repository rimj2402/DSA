#include<iostream>
using namespace std;
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void selectionsort(int arr[], int n ){
    for(int i =0; i<=n-2; i++){
        int min_element=arr[i];
        for(int j = i+1; j<=n-1; j++){
            if(arr[j]<min_element){
                min_element=arr[j];
                swap(arr[i], arr[j]);
            }
        }
    }
}

int main(){
    int n, arr[10];
    // cout << "Enter number of elements: " << endl;
    cin >> n;
    // cout << "Enter elements: " << endl ;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    selectionsort(arr, n);
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
}