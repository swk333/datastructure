#include <iostream>
#include <vector>

using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node(int value){
            this->data = value;
            this->next = NULL;
        };
};

class SinglyLinkedList{
    public:
        Node *head;
        SinglyLinkedList(Node *node){
            this->head = node;
        };
};

int main(){
    vector<int>arr = {35, 23, 546, 67, 86, 234, 56, 767, 34, 1,98, 78, 555};
    Node* node1 = new Node(arr[0]);
    SinglyLinkedList *numList = new SinglyLinkedList(node1);
    Node* current = numList->head;
    for(int i = 1; i < arr.size(); i++){
        current->next = new Node(arr[i]);
        current = current->next;
    }
    current = numList->head;
    while(current != NULL){
        cout << current->data << endl;
        current = current->next;
    }
}