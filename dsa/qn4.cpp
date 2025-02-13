//circular linked list
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

void insertAtHead(Node* &head, int val) {
    Node* new_node = new Node(val);
    if (head == NULL) {
        new_node->next = new_node;
        head = new_node;
        return;
    }
    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    new_node->next = head;
    temp->next = new_node;
    head = new_node;
}

void insertAtTail(Node* &head, int val) {
    Node* new_node = new Node(val);
    if (head == NULL) {
        new_node->next = new_node;
        head = new_node;
        return;
    }
    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->next = head;
}

void insertAtPositon(Node* &head, int val, int pos) {
    Node* new_node = new Node(val);
    int i = 0;
    if (head != NULL) {
        Node* temp2 = head;
        do {
            i++;
            temp2 = temp2->next;
        } while (temp2 != head);
    }
    if (pos == 0) {
        insertAtHead(head, val);
        return;
    }
    if (pos > i) {
        insertAtTail(head, val);
        return;
    }
    Node* temp = head;
    int current_pos = 0;
    while (current_pos != pos - 1) {
        temp = temp->next;
        current_pos++;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

void updateAtPositon(Node* &head, int val, int pos) {
    if (head == NULL) return;
    int size = 0;
    Node* temp2 = head;
    do {
        size++;
        temp2 = temp2->next;
    } while (temp2 != head);
    pos %= size;
    Node* temp = head;
    int current_pos = 0;
    while (current_pos != pos) {
        temp = temp->next;
        current_pos++;
    }
    temp->data = val;
}

void deleteAtHead(Node* &head) {
    if (head == NULL) return;
    if (head->next == head) {
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    Node* last = head;
    while (last->next != head) {
        last = last->next;
    }
    head = head->next;
    last->next = head;
    delete temp;
}

void deleteAtTail(Node* &head) {
    if (head == NULL) return;
    if (head->next == head) {
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while (temp->next->next != head) {
        temp = temp->next;
    }
    Node* temp2 = temp->next;
    temp->next = head;
    delete temp2;
}

void deleteAtPositon(Node* &head, int pos) {
    if (head == NULL) return;
    int size = 0;
    Node* temp2 = head;
    do {
        size++;
        temp2 = temp2->next;
    } while (temp2 != head);
    pos %= size;
    if (pos == 0) {
        deleteAtHead(head);
        return;
    }
    Node* prev = head;
    int current_pos = 0;
    while (current_pos != pos - 1) {
        prev = prev->next;
        current_pos++;
    }
    Node* temp = prev->next;
    prev->next = temp->next;
    delete temp;
}

void display(Node* head) {
    if (head == NULL) {
        cout << "NULL" << endl;
        return;
    }
    Node* temp = head;
    do {
        cout << temp->data << "->";
        temp = temp->next;
    } while (temp != head);
    cout << "HEAD" << endl;
}

int main() {
    Node* head = NULL;
    display(head);

    insertAtHead(head, 20);
    display(head);
    insertAtHead(head, 10);
    display(head);
    insertAtTail(head, 30);
    display(head);
    insertAtPositon(head, 45, 15);
    display(head);
    updateAtPositon(head, 14, 1);
    display(head);
    updateAtPositon(head, 9, 0);
    display(head);
    deleteAtHead(head);
    display(head);
    deleteAtTail(head);
    display(head);
    deleteAtPositon(head, 1);
    display(head);
    deleteAtPositon(head, 0);
    display(head);
    return 0;
}
