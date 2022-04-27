#include<iostream>
#include<vector>

using namespace std;

struct Node{
    int data;
    struct Node* next;
};

void insertBegin(struct Node** ref_head, int data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = (*ref_head);
    (*ref_head) = new_node;
}


struct Node* insertLast(struct Node* head, int data){
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next  = NULL;

    struct Node* ptr = head;

    if(head == NULL) {
        return new_node;
    }

    
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = new_node;

    return head;
}

void print(struct Node* head){

    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}

int node_from_Last(struct Node* head, int N){
    vector<int> vct;

    struct Node* p = head;

    while(head != NULL){
        vct.push_back(head->data);
        head = head->next;
    }
    int d = vct.at(vct.size()- N);
    return d;
}

int main(){
    struct Node* head = NULL;

    // insertBegin(&head,4);
    // insertBegin(&head,1);
    // insertBegin(&head,5);

    head = insertLast(head,4);
    head = insertLast(head,7);
    head = insertLast(head,9);
    head = insertLast(head,2);
    head = insertLast(head,1);
    head = insertLast(head,5);
    head = insertLast(head,8);

    print(head);

    cout << endl << node_from_Last(head, 7);
}




