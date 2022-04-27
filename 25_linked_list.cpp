#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    
};

void push(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;

}

void printList(Node *node)
{
    while (node->next!=NULL)
    {
        cout<<node->data<<" ";
        node = node->next;
    }
}

Node *merge(Node *head1, Node *head2)
{

    Node *sorted = NULL;

    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }

    if (head1->data <= head2->data)
    {
        sorted = head1;
        sorted->next = merge(head1->next, head2);
    }
    
    else
    {
        sorted = head2;
        sorted->next = merge(head1, head2->next);
    }

    return sorted;
}

int main()
{
    Node *head1 = new Node();
    Node *head2 = new Node();

    push(&head1,7);
    push(&head1,5);
    push(&head1,3);
    push(&head1,1);

    printList(head1);
    cout<<endl;
    
    push(&head2,8);
    push(&head2,6);
    push(&head2,4);
    push(&head2,2);
    push(&head2,0);

    printList(head2);
    cout<<endl;

    Node *new_node = merge(head1,head2);

    printList(new_node);
    
    return 0;
}