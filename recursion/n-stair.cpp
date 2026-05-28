#include<iostream>
using namespace std;
int countdistinctways(int n){
    if(n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }
    return countdistinctways(n-1)+ countdistinctways(n-2);
}

int main(){
    int n;
    cin>>n;
    cout<< countdistinctways(n);
    return 0;
}