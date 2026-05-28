#include <bits/stdc++.h>

using namespace std;
// this is brute force method with O(n^3) time complexity
// int max_subbarray_sum_k(const vector<int>& nums, int k) {
//     int length = 0;
//     int n = nums.size();
//     for (int i = 0; i < n;i++) {
        
//         for (int j = i; j < n; ++j) {
//             int s = 0;
//             for(int x=i;x<=j;x++)
//             s += nums[x];
//             if (s == k) {
//                 length = max(length, j - i + 1);
//             }
//         }
//     return length;
// }
// }

// int main() {
//     int n, k;
//     cin >> n >> k;
//     vector<int> nums(n);
//     for (int i = 0; i < n; ++i) {
//         cin >> nums[i];
//     }
//     cout << max_subbarray_sum_k(nums, k);
//     return 0;
// }

// better approach with O(n) time complexity
int max_subbarray_sum_k_optimized(const vector<int>& nums, int k) {
    unordered_map<int, int> prefix_sum_index;
    int prefix_sum = 0;
    int max_length = 0;

    for (int i = 0; i < nums.size(); ++i) {
        prefix_sum += nums[i];

        if (prefix_sum == k) {
            max_length = i + 1;
        }

        if (prefix_sum_index.find(prefix_sum - k) != prefix_sum_index.end()) {
            max_length = max(max_length, i - prefix_sum_index[prefix_sum - k]);
        }

        if (prefix_sum_index.find(prefix_sum) == prefix_sum_index.end()) {
            prefix_sum_index[prefix_sum] = i;
        }
    }

    return max_length;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    cout << max_subbarray_sum_k_optimized(nums, k);
    return 0;
}
