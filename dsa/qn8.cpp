//Program-2: Program for the following operations on Binary Search Tree (BST) of Integers
//i. Creation of a BST
//ii. Perform insertion operation in the BST
//iii. Traverse the BST in In-order, Preorder and Post Order
//iv. Search the BST for a given element
//v. Perform deletion of some elements
#include <iostream>
using namespace std;
class Node {
public:
int data;
Node* left;
Node* right;
Node(int val) {
data = val;
left = NULL;
right = NULL;

}
};
Node* insert(Node* root, int val) {
if (root == NULL)
return new Node(val);
if (root->data < val)
root->right = insert(root->right, val);
else
root->left = insert(root->left, val);
return root;
}
bool search(Node* root, int val) {
if (root == NULL)
return false;
if (root->data == val)
return true;
if (root->data < val)
return search(root->right, val);
return search(root->left, val);
}
Node* getSuccessor(Node* curr) {
curr = curr->right;
while (curr != NULL && curr->left != NULL)
curr = curr->left;
return curr;
}
void del_Node(Node* &root, int val) {
if (root == NULL)
return;
if (root->data > val) {
del_Node(root->left, val);
}
else if (root->data < val) {

del_Node(root->right, val);
}
else {
if (root->left == NULL) {
Node* temp = root->right;
delete root;
root = temp;
}
else if (root->right == NULL) {
Node* temp = root->left;
delete root;
root = temp;
}
else {
Node* succ = getSuccessor(root);
root->data = succ->data;
del_Node(root->right, succ->data);
}
}
}
void in_Order(Node* root) {
if (root == NULL) return;
in_Order(root->left);
cout << root->data << " ";
in_Order(root->right);
}
int main() {
Node* root = new Node(50); // Creating the following BST
insert(root, 30); // 50
insert(root, 20); // / \
insert(root, 40); // 30 70
insert(root, 70); // / \ / \
insert(root, 60); // 20 40 60 80
insert(root, 80);
in_Order(root);
cout << endl;
cout << endl;

cout << (search(root, 70) ? "70 is Found" : "70 is Not Found") << endl;
cout << (search(root, 19) ? "19 is Found" : "19 is Not Found") << endl;
cout << endl;
del_Node(root, 80);
in_Order(root);
return 0;
}
