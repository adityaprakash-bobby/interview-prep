#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *insertNode(ListNode *head, int data)
{
    ListNode *temp = head;
    ListNode *new_node = new ListNode(data);

    if (head == NULL)
    {
        head = new_node;
        return head;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = new_node;

    return head;
}

void printLnkedList(ListNode *head)
{
    ListNode *temp = head;

    if (head == NULL)
    {
        cout << "\n";
        return;
    }

    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }

    cout << "\n";

    return;
}

ListNode *removeNthNodeFromEnd(ListNode *head, int n)
{
    ListNode *ptr1 = head;
    ListNode *ptr2 = head;

    int gap = 0; // initially both the pointers are at same node

    // keep the ptr2 at a gap of n places
    while (ptr2 != nullptr && gap != n)
    {
        ptr2 = ptr2->next;
        gap++;
    }

    // if desired gap cannot be achieved even after traversing the end,
    // don't remove any node
    if (gap < n)
    {
        return head;
    }

    // if ptr2 is at the end after maintaining the gap
    if (ptr2 == nullptr)
    {
        head = ptr1->next;
        delete ptr1;
        return head;
    }

    ListNode *prevNode = nullptr;

    while (ptr2 != nullptr)
    {
        prevNode = ptr1;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    prevNode->next = ptr1->next;
    delete ptr1;

    return head;
}

int main()
{
    ListNode *head = NULL;

    head = insertNode(head, 100);
    head = insertNode(head, 200);
    head = insertNode(head, 300);
    head = insertNode(head, 400);

    // before removal
    printLnkedList(head);

    int n = 3;
    head = removeNthNodeFromEnd(head, n);

    // after removal
    printLnkedList(head);

    return 0;
}