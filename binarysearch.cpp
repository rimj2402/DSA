#include<iostream>
using namespace std;

int binarysearch(int arr[], int n, int key) {
    int left = 0;
    int right = n - 1;
    while(left <= right) {
        int mid = (left + right) / 2; 
        if(arr[mid] == key) {
            return mid;
        } else if(arr[mid] < key) {
            left = mid + 1; 
        } else {
            right = mid - 1; 
        }
    }
    return -1;
}

int main() {
    int n, arr[10], key;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> key;
    int result = binarysearch(arr, n, key);
    if(result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }
}