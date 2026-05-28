// // counting number of '#' and '*' in the string 
#include <bits/stdc++.h>
using namespace std;

// vector<int> stringToArray(const string& str) {
//     vector<int> arr;
//     stringstream ss(str);
//     int number;
//     while (ss >> number) {
//         arr.push_back(number);
//     }
//     return arr;
// }

int countChars(const string& str) {
    int count1 = 0;
    int count2 = 0;
    for (size_t i = 0; i < str.length(); ++i) {
        if (str[i] == '#') {
            ++count1;
        } else if (str[i] == '*') {
            ++count2;
        }
    }
    if (count1 > count2) {
        return 1;
    } else if (count2 == count1) {
        return 0;
    } else {
        return -1;
    }
}

int main(){
    int count1=0;
    int count2=0;

    string str="#*#*#*#*#*#*#*#*#*#";
    // getline(cin, str);
    cout<< countChars(str);
    
    return 0;
}
//     vector<int> arr={7,4,8,3,9};
//     int count =0;
//     int greaterno=0;

//     for(int i=1;i<arr.size();i++){
//         if(arr[i]<arr[i-1]){
//             greaterno=arr[i];
//             count++;
            
//         }
//     }
//     cout<<greaterno;;
//     return 0;
// }


