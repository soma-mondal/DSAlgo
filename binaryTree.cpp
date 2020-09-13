#include<iostream>
using namespace std;

class Node {

  private:
    int data;
    Node* leftNode;
    Node* rightNode;

	public:	
		Node(int data) {
			this->data = data;
			leftNode = NULL;
			rightNode = NULL;
		}

};

class BinaryTree
{
private:
	Node* root;
public:
	BinaryTree(int data) {
		Node* root = new Node(data);
		this->root = root;
	};
};

int main() {
	BinaryTree bt = BinaryTree(10);
	return 0;
}