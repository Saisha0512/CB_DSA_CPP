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
            while (temp -> next != NULL){
                temp = temp -> next;
            }
            temp -> next = newnode;
            temp = newnode;
        }
    }
}

void printLL(ListNode *head){
    ListNode *temp = head;
    while (temp != NULL){
        cout << temp -> val << " ";
        temp = temp -> next;
    }
    cout << endl;
}

ListNode* k_reverse(ListNode *head, int k){
    // Base Case : 
    if (head == NULL){
        return head;
    }

    // Recursive Case : 
    ListNode *temp = head;
    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *next = head;
    for (int i = 0; i < k; i ++){
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    temp -> next = k_reverse(curr, k);
    return prev;
}

int main(){
    int n, k;
    cin >> n >> k;
    ListNode *head = NULL;
    createLL(head, n);
    head = k_reverse(head, k);
    printLL(head);

    return 0;
}