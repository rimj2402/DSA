#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> e= {3,5,2,0};
    vector<int> l= {0,2,4,4};
    int people=0;
    int val;
    cout<<"enter no of hours";
    cin>>val;
    for(int i=0;i<val;i++){
        people = people + e[i] - l[i]; 
    }
    cout<<people;
    return 0;
}