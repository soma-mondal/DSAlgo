#include<bits/stdc++.h>
using namespace std;

class Node {

  public:
    int data;
    Node *leftNode, *rightNode;

		Node(int data) {
			this->data = data;
			leftNode = rightNode = NULL;
		}

};

void inOrderTraversal(Node *root) {
	if(root) {
		inOrderTraversal(root->leftNode);
		cout<<root->data<<" ";
		inOrderTraversal(root->rightNode);
	}
}

void preOrderTraversal(Node *root) {
	if(root) {
		cout<<root->data<<" ";
		preOrderTraversal(root->leftNode);
		preOrderTraversal(root->rightNode);
	}
}

void postOrderTraversal(Node *root) {
	if(root) {
		postOrderTraversal(root->leftNode);
		postOrderTraversal(root->rightNode);
		cout<<root->data<<" ";
	}
}

int height(Node *root) {
	if (root) {
		int leftHeight = height(root->leftNode);
		int rightheight = height(root->rightNode);
		return leftHeight>rightheight ? leftHeight+1 : rightheight+1;
	}
	return 0;
}

void printGivenLevel(Node* root, int level) {
	if (root == NULL) {
		return;
	}
	if (level == 1) {
		cout<<root->data<<" ";
	} else {
		printGivenLevel(root->leftNode, level-1);
		printGivenLevel(root->rightNode, level-1); 
	}
}

void levelOrderTraversal(Node* root) {
	for(int i = 0; i<=height(root); i++) {
		printGivenLevel(root, i);
	}
}

void levelOrderTraversalUsingQueue(Node *root) {
	queue<Node*> q;
	q.push(root);

	while (!q.empty()) {
		Node *temp = q.front();
		q.pop();

		cout<<temp->data<<" ";
		if (temp->leftNode) {
			q.push(temp->leftNode);
		}
		if (temp->rightNode) {
			q.push(temp->rightNode);
		}
	}
}

void insert(Node *root, int data) {
	queue<Node*> q;
	q.push(root);

	while (!q.empty()) {
		Node *temp = q.front();
		q.pop();

		if (temp->leftNode) {
			q.push(temp->leftNode);
		} else {
			temp->leftNode = new Node(data);
			break;
		}
		if (temp->rightNode) {
			q.push(temp->rightNode);
		} else {
			temp->rightNode = new Node(data);
			break;
		}
	}
}

int main() {
	Node *root = new Node(10);
	root->leftNode = new Node(8);
	root->rightNode = new Node(7);
  root->leftNode->leftNode = new Node(11);
	insert(root, 12);
	cout<<"PreOrder: ";
	preOrderTraversal(root);
	cout<<endl;
	cout<<"InOrder: ";
	inOrderTraversal(root);
	cout<<endl;
	cout<<"PostOrder: ";
	postOrderTraversal(root);
	cout<<endl;
  cout<<"Height: "<<height(root)<<endl;
	cout<<"Print level two: ";
	printGivenLevel(root, 2);
	cout<<endl;
	cout<<"LevelOrderTrversal: ";
	levelOrderTraversal(root);
	cout<<endl;
	cout<<"LevelOrderTrversal Using Queue: ";
	levelOrderTraversalUsingQueue(root);
	return 0;	
}