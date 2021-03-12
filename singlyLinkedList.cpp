#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node(int value){
            this->data = value;
            this->next = NULL;
        }
};

class SinglyLinkedList{
    public:
        Node *head;
        // 配列が渡されるようにします。片方向リストの初期化を行います。
        SinglyLinkedList(vector<int> arr){
            // 連結リストは先頭が必要です。もし配列に要素が存在しなれば、nullを初期値とします。
            this->head = arr.size() > 0 ? new Node(arr[0]) : NULL;
            Node *currentNode = this->head;
            for(int i = 1; i < arr.size(); i++){
                currentNode->next = new Node(arr[i]);
                currentNode = currentNode->next;
            }
        }

        Node *at(int index){
            Node *iterator = this->head;
            // 与えられたインデックスまでリストの中を反復します。
            // nullになったところは反復の範囲外になります。
            for(int i = 0; i < index; i++){
                // もしnextがnullの場合、nullを返します。これはインデックスが範囲外にあることを示します。
                iterator = iterator->next;
                if(iterator == NULL) return NULL;
            }
            return iterator;
        }

        //
        
};

int main(){

    SinglyLinkedList *numList = new SinglyLinkedList({35,23,546,67,86,234,56,767,34,1,98,78,555});

    // 連結リストを反復します。
    cout << numList->at(2)->data << endl;
    cout << numList->at(12)->data << endl;

    // a(13)はnullを返すので、エラーになります。
    // cout << numList->at(13)->data << endl;

}