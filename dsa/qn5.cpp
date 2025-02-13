//Program-3: Program to implement Circular Doubly Linked List [CDLL].//
#include<iostream>
using namespace std;
class Node{
public:
int data;
Node* prev;
Node* next;
Node(int val){
data = val;
prev = this;
next = this;
}
};
void insertAtHead(Node* &head, int val){
Node* new_node = new Node(val);
if(head == NULL){
head = new_node;
return;
}
Node* tail = head->prev;
new_node->next = head;
new_node->prev = tail;
tail->next = new_node;
head->prev = new_node;
head = new_node;
}
void insertAtTail(Node* &head, int val){
Node* new_node = new Node(val);
if(head == NULL){
head = new_node;
return;
}
Node* tail = head->prev;

tail->next = new_node;
new_node->prev = tail;
new_node->next = head;
head->prev = new_node;
tail = new_node;
}
void insertAtPosition(Node* &head, int val, int pos){
Node* new_node = new Node(val);
int current_pos = 0;
Node* temp = head;
int i=0; // for line no.70 case
Node* temp2 = head; // for line no.70 case
do{ // for line no.70 case
temp2 = temp2->next;
i++;
}while(temp2 != head);
if(pos == 0 || head == NULL){
insertAtHead(head, val);
return;
}
if(pos > i){ //If your entered position is behind the current CDLL size then your value will be
// inserted At Tail
insertAtTail(head, val);
return;
}
while(current_pos != pos-1){
temp = temp->next;
current_pos++;
} // temp arrives at pos-1

new_node->next = temp->next;
new_node->prev = temp;
temp->next->prev = new_node;
temp->next = new_node;
}

void updateAtPosition(Node* &head, int val, int pos){
if(head == NULL) return;
int current_pos = 0;
Node* temp = head;
while(current_pos != pos){
temp = temp->next;
current_pos++;
} // temp arrives at pos
temp->data = val;
}
void deleteAtHead(Node* &head){
if(head == NULL) return;
if(head->next == head){ //single node case
delete head;
head = NULL;
return;
}
Node* tail = head->prev;
Node* temp = head;
head = head->next;
head->prev = tail;
tail->next = head;
delete temp;
}
void deleteAtTail(Node* &head){
if(head == NULL) return;
if(head->next == head){ //single node case
delete head;
head = NULL;
return;
}
Node* tail = head->prev;
Node* temp = tail;

tail = tail->prev;
tail->next = head;
head->prev = tail;
delete temp;
}
void deleteAtPosition(Node* &head, int pos){
if(head == NULL) return;
if(pos == 0){
deleteAtHead(head);
return;
}
int current_pos = 0;
Node* prev = head;
while(current_pos != pos-1){
prev = prev->next;
current_pos++;
} // prev arrives at pos-1
Node* temp = prev->next;
prev->next = temp->next;
temp->next->prev = prev;
delete temp;
}
void display(Node* head){
if( head == NULL){
cout<<"NULL"<<endl;
return;
}
Node* temp = head;
do{
cout<<"|"<<temp->prev<<"|"<<temp->data<<"|"<<temp->next<<"|"<<"<->";
temp = temp->next;
}while(temp != head);
cout<<"[head]"<<endl;
}

int main(){
Node* head = NULL;
display(head);
insertAtHead(head, 20);
display(head);
insertAtHead(head, 10);
display(head);
insertAtTail(head, 30);
display(head);
insertAtPosition(head, 40, 5);
display(head);
updateAtPosition(head, 15, 1);
display(head);
deleteAtHead(head);
display(head);
deleteAtTail(head);
display(head);
deleteAtPosition(head, 1);
display(head);
deleteAtPosition(head, 0);
display(head);
return 0;
}
