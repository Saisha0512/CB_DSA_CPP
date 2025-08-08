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

void reverseLL(ListNode *&head){
    ListNode *prev = NULL;
    ListNode *curr = head;
    while (curr != NULL){
        ListNode *next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

void sumTwoLLs(ListNode *&result, ListNode *first, ListNode *second, int carry){
    // Base Case : 
    if (first == NULL && second == NULL & carry == 0){
        return;
    }
    
    // Recursive Case : 
    int sum = carry;
    if (first != NULL){
        sum += first -> val;
        first = first -> next;
    }
    if (second != NULL){
        sum += second -> val;
        second = second -> next;
    }
    ListNode *newnode = new ListNode(sum % 10);
    if (result != NULL){
        newnode -> next = result;
    }
    result = newnode;

    sumTwoLLs(result, first, second, sum/10);
}

void printLL(ListNode *head){
    ListNode *temp = head;
    while (temp != NULL){
        cout << temp -> val << " ";
        temp = temp -> next;
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    ListNode *first = NULL;
    ListNode *second = NULL;
    createLL(first, n);
    createLL(second, m);
    reverseLL(first);
    reverseLL(second);
    ListNode *result = NULL;
    sumTwoLLs(result, first, second, 0);
    printLL(result);

    return 0;
}