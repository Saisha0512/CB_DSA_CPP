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

void k_appends(ListNode *&head, int k, int n){
    if (head == NULL || k == 0 || k % n == 0){
        return;
    }    
    k = k % n;
    ListNode *slow = head;
    ListNode *fast = head;
    for (int i = 0; i < k + 1; i ++){
        fast = fast -> next;
    }
    while (fast != NULL){
        slow = slow -> next;
        fast = fast -> next;
    }
    fast = slow -> next;
    slow -> next = NULL;
    ListNode *temp = fast;
    while (temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = head;
    head = fast;
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
    int k;
    cin >> k;
    k_appends(head, k, n);
    printLL(head);

    return 0;
}

