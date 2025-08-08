# include <iostream>
using namespace std;

struct ListNode {
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

ListNode* rec_reverseLL(ListNode *&head){
    // Base Case : 
    if (head == NULL || head -> next == NULL){
        return head;
    }

    // Recursive Case : 
    ListNode *newhead = rec_reverseLL(head -> next);
    ListNode *temp = head -> next;
    temp -> next = head;
    head -> next = NULL;

    return newhead;
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
    head = rec_reverseLL(head);
    printLL(head);

    return 0;
}












