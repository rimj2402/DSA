#include<iostream>
using namespace std;

// class A{
    
//         int a=1;
        
// public:
//     void show(){
//         static int b=2;
//         a++;
//         b++;
//         cout<<a<<" "<<b<<endl;

//     }
// };

// int main(){
//     A obj;
//     obj.show();
//     obj.show();
//     obj.show();
//         return 0;
//     }


class A{
    int a=1;
    const  static int b=2;
public:
    static void show(){ 
        A obj; // static member function can access only static data members
        cout<<obj.a+b<<endl;
    }
    void play(){
        cout<<a+b;
    }
};
int main(){
    A obj;
    obj.show();
    obj.play();
    return 0;}
