#include<bits/stdc++.h>
using namespace std ;

class Node{
    public:
    int data;
    Node* next;

    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node *arr2LL(const vector<int>& arr){
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(size_t i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=mover->next;
    }
    return head;
}

int main(){
    vector<int> arr={12 ,13, 14 ,15};
    Node *head= arr2LL(arr);
    if(head) cout<<head->data;
    cout<<'\n';
    return 0;
}