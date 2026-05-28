// check if two strings are same or not 
#include <iostream>
using namespace std;

int main(){
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    vector<char> arr(str1.begin(), str1.end());
    vector<char> arr2(str2.begin(), str2.end());
    for(size_t i=0;i<arr.size();i++){
        if(arr[i]!=arr2[i]){
            cout<<"Strings are not same";
            return 0;
        }
    }
    
}

/*
int main(){
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    vector<char> arr(str1.begin(), str1.end());
    vector<char> arr2(str2.begin(), str2.end());
    for(int i=0;i<arr.size();i++){
        if(arr[i]!=arr2[i]){
            j++;
        }
    }
}
*/