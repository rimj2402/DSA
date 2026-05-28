#include<bits/stdc++.h>
using namespace std;

int main (){
    vector<vector<int>> nums = {{0,1,0},{1,1,0},
    {1,0,1},{1,1,1}}; //parkinglot(3, vector<int>(3,0));
    int count;
    int maxi=INT_MIN;
    int row=0;
    int count1=0;
    for(int i=0;i<nums.size();i++){
        count = 0;
        for(int j=0;j<nums[i].size();j++){`
            if(nums[i][j]==1) count++;
        }
        count1=count;
        maxi=max(maxi,count);
        if(maxi>=count1) row=i;
    }
    cout<<"Row with maximum 1s is : "<< row+1 <<"row";
    return 0;
}