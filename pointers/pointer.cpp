#include <iostream>

#define MAX_ELEMENTS 10

// Basic structure for a node in a linked list
struct Node {
    
    int value_node;
    Node *next_node;
};

// Method prototypes to work on the linked list
int get_node_count();
void insert_node(int);
int delete_node();
void show_data();

// Init node count to 0 and the head of the linked list to NULL
static int node_count = 0;
struct Node *head = NULL;

// Main funtion to test the methods
int main(int argc, char const *argv[])
{
    Node *head = NULL;



    return 0;
}

/*
    Funcion definitions to manipulate the data in the linked list
    1 - Get the count of elements in the linked list
    2 - Insert a node to the end of the linked list
    3 - Delete a node from the end of the linked list 
    4 - Print the linked list data into the stdout
*/

int get_node_count() {
    
    return node_count;

}

void insert_node(int data) {
    
    Node *temp = head;

    if (node_count == MAX_ELEMENTS) {
        std::cerr << "OVERFLOW";

        return;
    }

    if (temp == NULL) {
        Node *n = malloc((size_t)sizeof(Node*));
        n->next_node = NULL;
        n->value_node = data;

        return;
    }

    while (temp->next_node != NULL) {
        temp = temp->next_node;
    }

    Node *new_node = 0;

    new_node->value_node = data;
    new_node->next_node = NULL;
    temp->next_node = new_node; 

    return;
}

int delete_node() {
    
    Node *temp = head;
    int deleted_node_data;

    if(temp == NULL) {
        std::cerr << "UNDERFLOW";

        return -1;
    }

    while (temp->next_node != NULL) {
        temp = temp->next_node;
    }

    deleted_node_data = temp->value_node;
    free(temp);

    return deleted_node_data;
}

void show_data() {

    Node *temp = head;

    while (temp->next_node != NULL) {
        std::cout << "[" << temp->value_node << "]->";
    }

    return; 

}