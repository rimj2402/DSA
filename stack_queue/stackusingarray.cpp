//  stack using array 

# include<bits/stdc++.h>
using namespace std;

class Arraystack {
    private:
    int topindex;
    int capacity;
    int* stackarr;

    public:
    Arraystack(int size){
        capacity=size;
        stackarr=new int[capacity];
        topindex=-1;
    }

    ~Arraystack(){
        delete [] stackarr;
    }

    void push(int data){
        if(topindex>=capacity-1){
            cout<<"stack overflow"<<endl;
            return ;
        }
        else{
            topindex++;
            stackarr[topindex]=data;
        }
    }

    int pop(){
        if(topindex==-1){
            cout<<"stack overflow"<<endl;
            return -1;
        }
        else{
            int data=stackarr[topindex];
            topindex--;
            return data;
        }
    }

    int top(){
        if(topindex==-1){
            cout<<"stack overflow"<<endl;
            return -1;
        }
        else{
            return stackarr[topindex];
        }
    }

    bool isempty(){
        return topindex==-1;
    }
};


int main(){
    Arraystack stack(100);
    vector<string> commands={"ArrayStack", "push", "push", "top", "pop", "isEmpty"};
    vector<vector<int>> values={{},{5},{8},{},{},{}};
    for (size_t i = 0; i < commands.size(); ++i) {
        if (commands[i] == "push") {
            stack.push(values[i][0]);
            cout << "null ";
        } else if (commands[i] == "pop") {
            cout << stack.pop() << " ";
        } else if (commands[i] == "top") {
            cout << stack.top() << " ";
        } else if (commands[i] == "isEmpty") {
            cout << (stack.isempty() ? "true" : "false") << " ";
        } else if (commands[i] == "ArrayStack") {
            cout << "null ";
        }
    }

}

