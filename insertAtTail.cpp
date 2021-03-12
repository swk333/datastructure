#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iterator>

using namespace std;

class SinglyLinkedListNode{
    public:
        int data;
        SinglyLinkedListNode *next;
        SinglyLinkedListNode(int data){
            this->data = data;
            this->next = NULL;
        };
};

SinglyLinkedListNode* insertAtTail(SinglyLinkedListNode* head,int data){
    //ここから書きましょう
    SinglyLinkedListNode* iterator = head->next;
    while(iterator->next != NULL){
        iterator = iterator->next;

    }
    cout << iterator << endl;



    iterator->data = data;

    return head;
};

