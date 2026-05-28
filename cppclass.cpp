#include <iostream>
#include <vector>
using namespace std;

// void moveZeroes(vector<int>& nums) {
//     int j=0; 
//         for (int i = 0; i < nums.size(); i++) {
//             if (nums[i] != 0) {
//                 if (i != j) {
//                     swap(nums[j], nums[i]);
//                 }
//                 j++;
//             }
//         }
// }
// int main(){
//     vector<int> nums = {4,5,0,1,9,0,5,0};
//     moveZeroes(nums);
//     for (int num:nums){
//         cout<<num<<" ";
//     }
// }


int main(){
    vector<int> nums = {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0};
    long long even_sum=0;
    long long odd_sum=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]%2==0){
            even_sum+=nums[i];
        }
        else{
            odd_sum+=nums[i];
        }
    }
    cout<<odd_sum-even_sum;
    return 0;
}


















