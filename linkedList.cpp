#include<bits/stdc++.h>
using namespace std;

class Node {
    private:
        int data;
        Node* nextNode;

    public:
        Node(int data) {
            this->data = data;
            nextNode = NULL;
        }

        void setNextNode(Node* node) {
            nextNode = node;
        }

        int getData() {
            return data;
        }

        Node* getNextNode(){
            return nextNode;
        }
};

class LinkedList {
    private:
        Node *head, *tail;

    public:
        LinkedList(int data) {
            Node *new_node = new Node(data);
            head = tail = new_node;
        }

        void addNode(int data) {
            Node *new_node = new Node(data);
            tail->setNextNode(new_node);
            tail = new_node;
        } 

        void print() {
            Node *temp = head;
            cout<<"Current List: ";
            while (temp != NULL) {
                cout<<temp->getData()<<" ";
                temp = temp->getNextNode();
            }
            cout<<"\n";
        }

        void reverse() {
            Node *curr = head;
            Node *prev = NULL;
            Node *next = NULL;

            while (curr != NULL)
            {
                next = curr->getNextNode();
                curr->setNextNode(prev);
                prev = curr;
                curr = next;
            }
            tail = head;
            head = prev;
        }
};

int main() {
    LinkedList *list = new LinkedList(5);
    list->addNode(12);
    list->addNode(10);
    list->addNode(17);
    list->addNode(20);
    list->print();
    list->reverse();
    list->print();
    return 0;
}