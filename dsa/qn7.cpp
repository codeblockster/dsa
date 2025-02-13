//Program-1: Program for the following operations on Binary Tree (BT)
//i. Creation of a BT
//ii. Traverse the BT in In-order, Preorder and Post Order
#include <iostream>
using namespace std;
class Node{
public:
int data;
Node* left;
Node* right;
Node(int val){
data = val;
left = NULL;
right = NULL;
}
};
void in_Order(Node* root){ // In-order: Left, Root, Right
if(root == NULL) return;
in_Order(root->left);
cout<<root->data<<" ";
in_Order(root->right);
}
void pre_Order(Node* root){ // Pre-order: Root, Left, Right
if(root == NULL) return;
cout<<root->data<<" ";
pre_Order(root->left);
pre_Order(root->right);
}
void post_Order(Node*root){ // Post-order: Left, Right, Root
if(root == NULL) return;
post_Order(root->left);
post_Order(root->right);
cout<<root->data<<" ";

}
int main()
{
Node* root = new Node(10); // 10
root->left = new Node(20); // / \
root->right = new Node(30); // 20 30
root->left->left = new Node(40); // /
// 40
cout << "In-order Traversal: ";
in_Order(root);
cout << "\nPre-order Traversal: ";
pre_Order(root);
cout << "\nPost-order Traversal: ";
post_Order(root);
return 0;
}
