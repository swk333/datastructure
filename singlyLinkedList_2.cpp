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
        SinglyLinkedList(vector<int> arr){
            this->head = arr.size() > 0 ? new Node(arr[0]) : NULL;
            Node *currentNode = this->head;
            for(int i = 1; i < arr.size(); i++){
                currentNode->next = new Node(arr[i]);
                currentNode = currentNode->next;
            }
        }

        Node *at(int index){
            Node *iterator = this->head;
            for(int i = 0; i < index; i++){
                iterator = iterator->next;
                if(iterator == NULL) return NULL;
            }
            return iterator;
        }

        // 連結リストの中からあるデータを含むノードを検索する処理を O(n) で実装してみましょう。キーを受け取り、そのキーに合致するデータを持つ最初のノードを返す findNode を実装してください。
        int findNode(int key){
            Node *iterator = this->head;
            int count = 0;
            if(iterator != NULL){
                if(iterator-> data == key) return count;
                iterator = iterator->next;
                count++;
            }
            return 0;
        };

};

int main(){

    SinglyLinkedList *numList = new SinglyLinkedList({35,23,546,67,86,234,56,767,34,1,98,78,555});

    // データを出力してください。
    cout << numList->at(2)->data << endl;
    cout << numList->at(5)->data << endl;
    cout << numList->findNode(67) << endl;
    cout << numList->findNode(767) << endl;

}