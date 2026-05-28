#include<bits/stdc++.h>
using namespace std;
// 1.what is linklist
// 2.where it is used
// 3. struct/ class in c++
// in c++ we cant store memory location directly we need pointers for it 
// int x=2
// int * y=&x
// cout<<y
// struct Node{ //for object oriented programming we use class rather than using a struct
// public:
//     int data;
//     Node* next;
//     Node(int data1,Node* next1){
//         data=data1;
//         next=next1;
//     }
//     Node(int data1){
//         data=data1;
//         next=nullptr;
//     }
// };
// Node x=Node(2,nullptr); this is an object only not a pointer
// Node *y=&x; this is a pointer which stores the address of object x
//Node * y=new Node(2,nullptr);  this is also a pointer which stores the address of a newly created object in heap memory
// int main(){
//     vector<int> arr={1,2,34};
    // Node* y=new Node(arr[0],nullptr);
    // if we are using this 
    // Node y=Node(arr[0],nullptr);
    // cout<<y.data;
    // if we are using like this 
    // Node *y=new Node(arr[0],nullptr);
    // cout<<y->data;
// }

// 4.memory space used in case of 64 bit the pointer will store 8 bytes and in case of 32 bit it will store 4 bytes
// 5.difference bw Node and Node*
// array to LL
// class Node{
//     public:
//     int data;
//     Node* next;
//     public:
//     Node(int data1,Node* next1){
//         data=data1;
//         next=next1;
//     }
//     public:
//     Node(int data1){
//         data=data1;
//         next=nullptr;
//     }
// };
// Node * convert_array_to_linklist(vector<int> &arr){
//     Node* head=new Node(arr[0],nullptr);
//     Node * mover=head;
//     for(int i=0;i<arr.size();i++){
//         Node* temp =new Node(arr[i],nullptr);
//         mover->next=temp;
//         mover=mover->next; //or you can write mover=temp
//     }
//     return head;
// }
// int main(){
//     vector<int> arr={1,2,3,4,5};
//     Node * head=convert_array_to_linklist(arr);
//     cout<<head->data;
// }






// 6.traversal in linklist
// class Node{
//     public:
//     int data;
//     Node* next;
//     public:
//     Node(int data1,Node* next1){
//         data=data1;
//         next=next1;
//     }
//     public:
//     Node(int data1){
//         data=data1;
//         next=nullptr;
//     }
// };
// Node * convert_array_to_linklist(vector<int> &arr){
//     Node* head=new Node(arr[0],nullptr);
//     Node * mover=head;
//     for(int i=1;i<arr.size();i++){
//         Node* temp =new Node(arr[i],nullptr);
//         mover->next=temp;
//         mover=mover->next; //or you can write mover=temp
//     }
//     return head;
// }
// int main(){
//     vector<int > arr={23,54,2,15,76};
//     Node* head=convert_array_to_linklist(arr);
//     Node* mover=head;
//     while(mover){
//         cout<<mover->data;
//         mover=mover->next;
//     }
//     return 0;
// }

 
// 7.length of linklist

// class Node{
//     public:
//     int data;
//     Node* next;
//     public:
//     Node(int data1,Node* next1){
//         data=data1;
//         next=next1;
//     }
//     public:
//     Node(int data1){
//         data=data1;
//         next=nullptr;
//     }
// };
// Node * convert_array_to_linklist(vector<int> &arr){
//     Node* head=new Node(arr[0],nullptr);
//     Node * mover=head;
//     for(int i=1;i<arr.size();i++){
//         Node* temp =new Node(arr[i],nullptr);
//         mover->next=temp;
//         mover=mover->next; //or you can write mover=temp
//     }
//     return head;
// }
// int length_of_linklist(Node*head){
//     Node* temp=head;
//     int count=0;
//     while(temp){
//         count++;
//         temp=temp->next;
//     }
//     return count;
// }
// int main(){
//     vector<int> arr={23,54,2,15,76};
//     Node* head=convert_array_to_linklist(arr);
//     cout<<length_of_linklist(head);
//     return 0;
// }

// 8.search in linklist

// class Node{
//     public:
//     int data;
//     Node* next;
//     public:
//     Node(int data1,Node* next1){
//         data=data1;
//         next=next1;
//     }
//     public:
//     Node(int data1){
//         data=data1;
//         next=nullptr;
//     }
// };
// Node * convert_array_to_linklist(vector<int> &arr){
//     Node* head=new Node(arr[0],nullptr);
//     Node * mover=head;
//     for(int i=1;i<arr.size();i++){
//         Node* temp =new Node(arr[i],nullptr);
//         mover->next=temp;
//         mover=mover->next; //or you can write mover=temp
//     }
//     return head;
// }
// bool seaarch_in_linklist(Node* head,int val){
//     Node * temp=head;
//     while(temp){
//         if(temp->data==val) return true;
//         temp=temp->next;
//     }
//     return false;
// }
// int main(){
//     vector<int> arr={23,54,2,15,76};
//     Node* head=convert_array_to_linklist(arr);
//     cout<<seaarch_in_linklist(head,2);
//     return 0;
// }

// delete a linklist head node

// class Node{
//     public:
//     int data;
//     Node* next;
//     public:
//     Node(int data1,Node* next1){
//         data=data1;
//         next=next1;
//     }
//     public:
//     Node(int data1){
//         data=data1;
//         next=nullptr;
//     }
// };
// Node * convert_array_to_linklist(vector<int> &arr){
//     Node* head=new Node(arr[0],nullptr);
//     Node * mover=head;
//     for(int i=1;i<arr.size();i++){
//         Node* temp =new Node(arr[i],nullptr);
//         mover->next=temp;
//         mover=mover->next; //or you can write mover=temp
//     }
//     return head;
// }
// Node * delete_headnode(Node * head){
//     if(head==NULL) return NULL;
//     Node * temp=head->next;
//     delete head;
//     return temp;
// }
// int main(){
//     vector<int> arr={23,54,2,15,76};
//     Node * head=convert_array_to_linklist(arr);
//     head=delete_headnode(head);
//     Node* mover=head;
//     while(mover){
//         cout<<mover->data<<" ";
//         mover=mover->next;
//     }
//     return 0;
// }


// delete a linklist tail node

// class Node{
//     public:
//     int data;
//     Node* next;
//     public:
//     Node(int data1,Node* next1){
//         data=data1;
//         next=next1;
//     }
//     public:
//     Node(int data1){
//         data=data1;
//         next=nullptr;
//     }
// };

class Node{
    public:
    int data;
    Node * next;
    public:
    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }
};

// array to linklist
Node * convertarraytoll(vector<int> &arr){
    Node * head=new Node(arr[0],nullptr);
    Node * mover=head;
    for(int i=1;i<arr.size();i++){
        Node * temp=new Node(arr[i],nullptr);
        mover->next=temp;
        mover=temp;
    }
    return head;
}
traverse (Node* head){
    Node * temp=new Node(0,nullptr);
    temp=head;
    
    while(temp){
        // if(temp->data==val) return 1;
        cout<<temp->data;
        temp=temp->next;
        
    }
        return 0;
}

Node * deletehead(Node * head){

    if(head==nullptr)return nullptr;
    Node * temp=head;
    head = head-> next;
    free(temp);
    return head;
}
Node * deletetail(Node * head){

    if(head==nullptr || head->next ==nullptr) return nullptr;
    Node * temp=head;
    while(temp->next->next!=nullptr){
        temp=temp->next;
    }
    free(temp->next);
    temp->next=nullptr;
    return head;
}
Node * deleteatkposition( Node * head,int k ){
    if(head==NULL || head->next==NULL) return nullptr;
    int pos=1;
    Node * temp=head;
    while(temp->next!=NULL){
        if(pos==k){
        Node* del=temp;
        temp=temp->next;
        pos++;
        free(del);
    }
    }
    return head;
}

int main(){
    vector <int> arr={23,41,2,4,3,4,5,6,7,8};
    Node * head=convertarraytoll(arr);
    head=deleteatkposition(head,5);
    traverse(head);
    return 0;
}

