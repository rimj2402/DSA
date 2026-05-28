#include<iostream>
using namespace std;
fact(int n){
    if(n==0)
        return 1;
    // int chotiprob=fact(n-1);
    // int badiprob=n*chotiprob;
    // return badiprob;
    return n* fact(n-1);
}
int main(){
    int n;
    cin>>n;
    cout<<fact(n);
    return 0;
}