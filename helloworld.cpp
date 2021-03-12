#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        // C++では、次のノードのメモリアドレスを保存するために、ポインタを使用します。このポインタがNullの場合は、参照はありません。
        Node *next;
        Node(int value){
            this->data = value;
            this->next = NULL;
        };
};

// 先頭のノードを保持するコンテナ
// 片方向リスト
class SinglyLinkedList{
    public:
        // 先頭の参照を格納するためのポインタ
        Node *head;
        // ノードへの参照を取得します。
        SinglyLinkedList(Node *node){
            // 先頭を定義します。
            this->head = node;
        };
};

int main(){
    // ノードを扱う際には、オブジェクトが格納されているヒープのメモリアドレスを保持するポインタを使用します。これがNULLの場合はNULLノードになります。
    // これがポインタではなく通常の変数であれば、Node node1(1)を実行します。
    // しかし、これはポインタであり、"new Object(....) "はヒープ内にオブジェクトを作成し、ポインタになるオブジェクトの参照を返します。ポインタはメモリアドレスです。
    Node* node1 = new Node(4);
    Node* node2 = new Node(65);
    Node* node3 = new Node(24);

    // これは先頭のポインタを保持するための単なるコンテナです。これはリスト自体を表しており、挙動を内部に置き、リストを操作することができます。
    SinglyLinkedList numList(node1);

    // リストに他のリストを追加します。 
    // ポインタであれば、→を使って参照を解除し、直接データにアクセスすることができます。
    // これは、最初にオブジェクトの参照を解除してから実際のデータを取得します。node->dataは、nodeがポインタなので、*node.dataと同じです。
    numList.head->next = node2;
    numList.head->next->next = node3;

    // 連結リストを反復します。
    // 反復によって、現在のノードは次のノードになります。この処理を最後のノードまで繰り返します。

    // その場所を参照するポインタとして設定します。このポインタがnullでない限り、走査を続けることができます。
    Node* currentNode = numList.head;
    while(currentNode != NULL){
        // 現在のノードを出力します。
        cout << currentNode->data << endl;
        currentNode = currentNode->next;
    }

    cout << "Different syntax...." << endl;

    // 参照の解除を行う異なるシンタックスの例: *node.data
    currentNode = numList.head;
    while(currentNode != NULL){
        // 現在のノードを出力します。
        // ポインタに*演算子を適用すると、実際のデータを取得します。これを「参照解除」演算子と呼びます。
        cout << (*currentNode).data << endl;
        currentNode = currentNode->next;
    }
}
