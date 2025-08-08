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
            head = newnode;
            temp = newnode;
        }
        else {
            temp -> next = newnode;
            temp = newnode;
        }
    }
}

ListNode* reverseLL(ListNode *&head){
    ListNode *prev = NULL;
    ListNode *curr = head;
    while (curr != NULL){
        ListNode *next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void delete_nodes(ListNode *&head){
    head = reverseLL(head);

    ListNode *curr = head;
    int maxsofar = curr -> val;
    ListNode *prev = curr;
    curr = curr -> next;
    while (curr != NULL){
        if (curr -> val < maxsofar){
            prev -> next = curr -> next;
            delete curr;
            curr = prev -> next;
        }
        else {
            maxsofar = curr -> val;
            prev = curr;
            curr = curr -> next;
        }
    }

    head = reverseLL(head);
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
    delete_nodes(head);
    printLL(head);

    return 0;
}