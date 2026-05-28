#include <iostream>
using namespace std;

int findMax(int arr[], int low, int high) {
    if (low == high)
        return arr[low];
    
    
    int mid = (low + high) / 2;
    
    
    int leftMax = findMax(arr, low, mid);
    int rightMax = findMax(arr, mid + 1, high);
    
    
    return max(leftMax, rightMax);
}

int main() {
    int arr[] = {3, 5, 1, 8, 2, 9, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Maximum element: " << findMax(arr, 0, n - 1);
    return 0;
}