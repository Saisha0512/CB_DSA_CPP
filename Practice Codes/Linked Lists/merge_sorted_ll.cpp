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
    ListNode *temp = NULL;
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

void printLL(ListNode *head){
    ListNode *temp = head;
    while(temp != NULL){
        cout << temp -> val << " ";
        temp = temp -> next;
    }
    cout << endl;
}

ListNode* merge_sorted_LL(ListNode *a, ListNode *b){
    // Base Case : 
    if (a == NULL){
        return b;
    }
    if (b == NULL){
        return a;
    }

    // Recursive Case : 
    ListNode *c;
    if (a -> val <= b -> val){
        c = a;
        c -> next = merge_sorted_LL(a -> next, b);
    }
    else {
        c = b;
        c -> next = merge_sorted_LL(a, b -> next);
    }

    return c;
}

int main(){
    ListNode *first = NULL;
    ListNode *second = NULL;
    int n, m;
    cin >> n;
    createLL(first, n);
    cin >> m;
    createLL(second, m);
    
    ListNode *head = merge_sorted_LL(first, second);
    printLL(head);

    return 0;
}