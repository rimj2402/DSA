//  queue array implementation

#include<bits/stdc++.h>
using namespace std;

class Arrayqueue{
    private:
    int frontindex;
    int rearindex;
    int capacity;
    int* queuearr;

    public:
    Arrayqueue(int size){
        capacity=size;
        queuearr=new int[capacity];
        frontindex=0;
        rearindex=-1;
    }

    ~Arrayqueue(){
        delete [] queuearr;
    }

    void push(int x){
        if(rearindex>=capacity-1){
            cout<<"queue overflow"<<endl;
            return ;
        }
        else{
            rearindex++;
            queuearr[rearindex]=x;
        }
    }

    int pop(){
        if(frontindex>rearindex){
            cout<<"queue underflow"<<endl;
            return -1;
        }
        else{
            int data=queuearr[frontindex];
            frontindex++;
            return data;
        }
    }

    int front(){
        if(frontindex>rearindex){
            cout<<"queue underflow"<<endl;
            return -1;
        }
        else{
            return queuearr[frontindex];
        }
    }

    bool isempty(){
        return frontindex>rearindex;
    }


};

int main() 