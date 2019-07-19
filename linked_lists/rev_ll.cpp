#include <iostream>

using namespace std;

class Node {
   
    public:
        
        int data;
        Node* next;

};

Node* insertNode(Node* head, int data) {

    Node* temp = head;
    Node* new_node = new Node();
    
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        
        head = new_node;
        return head;

    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = new_node;

    return head;
}

void printLL(Node* head) {

    Node* temp = head;

    if (head == NULL) {
        
        cout << "\n";
        return;
    
    }

    while (temp != NULL) {

        cout << temp->data << " ";
        temp = temp->next;

    }

    cout << "\n";

    return;
}

// void reverseLL() {


// }

int main(int argc, char const *argv[])
{
    Node* head = NULL;

    head = insertNode(head, 100);
    head = insertNode(head, 200);   
    head = insertNode(head, 300);   
    head = insertNode(head, 400);   

    printLL(head);

    return 0;
}