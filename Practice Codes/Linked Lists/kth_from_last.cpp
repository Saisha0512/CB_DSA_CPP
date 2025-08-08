# include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode (int data){
        val = data;
        next = NULL;
    }
};

void insertAtEnd(ListNode *&head, int data){
    ListNode *newnode = new ListNode(data);
    if (head == NULL){
        head = newnode;
        return;
    }
    else {
        ListNode *temp = head;
        while (temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = newnode;
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

int kthFromLast(ListNode *head, int k){
    ListNode *slow = head;
    ListNode *fast = head;
    for (int i = 0; i < k; i ++){
        fast = fast -> next;
    }
    while (fast != NULL){
        fast = fast -> next;
        slow = slow -> next;
    }

    return slow -> val;
}

int main(){
    int data;
    cin >> data;
    ListNode *head = NULL;
    while (data != -1){
        insertAtEnd(head, data);
        cin >> data;
    }
    int k;
    cin >> k;
    cout << kthFromLast(head, k) << endl;

    return 0;
}