# include <iostream>
using namespace std;

struct ListNode {
public : 
    int val;
    ListNode *next;
    ListNode(int data){
        val = data;
        next = NULL;
    }
};

void createLL(ListNode *&head, int n){
    ListNode *temp = head;
    for (int i = 0; i < n; i ++){
        int data;
        cin >> data;
        ListNode *newnode = new ListNode(data);
        if (head == NULL){
            temp = newnode;
            head = newnode;
        }
        else {
            temp -> next = newnode;
            temp = newnode;
        }
    }
}

void insertLL(ListNode *&head, ListNode *&node){
    if (head == NULL){
        head = node;
    }
    else {
        ListNode *temp = head;
        while (temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = node;
    }
    node -> next = NULL;
}

void printLL(ListNode *head){
    ListNode *temp = head;
    while (temp != NULL){
        cout << temp -> val << " ";
        temp = temp -> next;
    }
}

int main(){
    int n;
    cin >> n;
    ListNode *head = NULL;
    createLL(head, n);
    ListNode *odd = NULL;
    ListNode *even = NULL;
    ListNode *temp = head;
    while (temp != NULL){
        ListNode *nextnode = temp -> next;
        if (temp -> val % 2 == 0){
            insertLL(even, temp);
        }
        else {
            insertLL(odd, temp);
        }
        temp = nextnode;
    }

    temp = odd;
    while (temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = even;
    printLL(odd);

    return 0;
}