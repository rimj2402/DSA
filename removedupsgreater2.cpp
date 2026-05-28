#include <bits/stdc++.h>
using namespace std;

int findk(vector<int> &nums){
    unordered_map<int,int> mp;
    int k=0;
    for(int i=0;i<nums.size();i++){
        mp[nums[i]]++;
        // array me tab add hoga jab mp.second is< 2
        if(mp[nums[i]]<=2) {
        nums[k]=nums[i];
        k++;
        }
    }
    return k;
}

int main(){
    vector<int>nums={0,0,1,1,1,1,2,3,3,2};
    int k=findk(nums);
    for(int i=0;i<k;i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}